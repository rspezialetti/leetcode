class Solution {
public:

    /*Extra array*/
    void rotate(vector<int>& nums, int k) 
    {
        
        if(k % nums.size())
        {
            vector<int> temp(nums.size(), 0);
            
            for(size_t i = 0; i < nums.size(); ++i)
            {
                temp[(i + k) % nums.size()] = nums[i];
            }
            
            nums = temp;
        }
    }
};
