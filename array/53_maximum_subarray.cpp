class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];
        
        int sum = INT_MIN;
        
        for(size_t i = 0; i < nums.size(); ++i)
        {
            int temp = nums[i];
            sum = (temp > sum) ? temp : sum;
            
            for(size_t j = i + 1; j < nums.size(); ++j)
            {
                temp += nums[j];   
                sum = (temp > sum) ? temp : sum;
            }
        }
        
        return sum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int dp = nums[0]; 
        int max_sum = dp;
        
        for(int i = 1; i < nums.size(); i++)
        {
            dp = max(dp + nums[i], nums[i]);
            max_sum = max(max_sum, dp);
        }
        
        return max_sum;
    }
};


