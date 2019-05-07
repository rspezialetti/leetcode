class Solution {
public:
    /*Time exceeding solution*/
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int res = 0;
        
        for(size_t i = 0; i < nums.size(); ++i)
        {
            if(nums[i] < k)
                ++res;
            
            int prod = nums[i]; 
            int j = i + 1;
                            
            while(prod < k && j < nums.size())
            {
                prod *= nums[j];
                
                if(prod <  k)
                    ++res;
                
                ++j;
            }
        }
        
        return res;
    }

    /*Sliding Windows*/
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if (k <= 1) 
            return 0;
        
        int res = 0;
        int left = 0;
        int prod = 1;
        
        for (int right = 0; right < nums.size(); right++)
        {
            prod *= nums[right];
            
            while (prod >= k) 
                prod /= nums[left++];

            res += right - left + 1;
        }
        
        return res;
    }
};
