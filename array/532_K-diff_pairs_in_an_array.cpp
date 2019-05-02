class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        map<pair<int,int>, int> map_pair;
        int max = 0;
        
        for(size_t i = 0; i < nums.size(); ++i)
        {
            for(size_t j = i + 1; j < nums.size(); ++j)
            {
                if(abs(nums[i] - nums[j]) == k && map_pair.count(pair<int,int>(nums[j], nums[i])) == 0)
                {
                    map_pair[pair<int,int>(nums[i], nums[j])] = 0;
                }
            }
        }
        
        return map_pair.size();

    }
};
