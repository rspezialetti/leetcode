class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> result;
        
        vector<bool>is_present(nums.size(), false);
        
        for(int i : nums)
            is_present[i - 1] = true;
        
        for(size_t i = 0; i  < is_present.size(); ++i)
            if(!is_present[i])
                result.push_back(i + 1);
        
        return result;
    }

	vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        for (auto n: nums) 
        {
            n = abs(n) - 1;
            
            if (nums[n] > 0)
                nums[n] = -nums[n];
        }
        
        for (auto i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                res.push_back(i + 1);
        
        return res;
    }
};
    
