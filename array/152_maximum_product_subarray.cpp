class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if(nums.size() == 1)                    
            return nums[0];
        
        vector<int> no_el(nums.begin(), nums.end()-1);
        
        int product = 1;
        for(size_t i = 0; i < nums.size() - 1; ++i)
            product *= nums[i];
        
        return max(maxProduct(no_el), nums.back() * product);
    }

    int maxProduct(vector<int>& nums) 
    {
     
        if(nums.size()==0) 
            return 0;
        
        vector<int> max_p{nums[0]};
        vector<int> min_p{nums[0]};
        
        for(int i = 1; i < nums.size(); i++)
        {
            max_p.push_back(max(max(nums[i], nums[i] * max_p[i-1]), nums[i] * min_p[i-1]));
            min_p.push_back(min(min(nums[i], nums[i] * max_p[i-1]), nums[i] * min_p[i-1]));
        }
        
        return *max_element(max_p.begin(), max_p.end());
    }
	
        int maxProduct(vector<int>& nums) 
    {
        if (nums.empty()) 
            return 0;
		
        int max_global = INT_MIN;
        
        // Running products
        int max_prod = 1;
        int min_prod = 1;
        
        for (int n: nums) 
        {
            if (n < 0) 
            {
                swap(max_prod, min_prod);
            }
        
            max_prod = max(max_prod * n, n);
            min_prod = min(min_prod * n, n);
            
            max_global = max(max_global, max_prod);
        }
        
        return max_global;
    }
	
};
