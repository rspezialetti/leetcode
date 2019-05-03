class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        
        int count = 0;
        for(int j = 1, i = 0; i < nums.size()-1; ++i, ++j)
        {
             if(nums[i] > nums[j])
             {
                 count++; 
                 
                if(i > 0 && nums[i - 1] > nums[j])
                    nums[j] = nums[i];

             }
        }
        
        return count <= 1;
    }
};
