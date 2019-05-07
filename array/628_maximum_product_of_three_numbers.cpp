class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        
        int min_1 = INT_MAX;
        int min_2 = INT_MAX;
        
        int max_1 = INT_MIN;
        int max_2 = INT_MIN;
        int max_3 = INT_MIN;
        
        for(auto i : nums)
        {
            if(i >= max_1)
            {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = i;
            }
            else if(i >= max_2)
            {
                max_3 = max_2;
                max_2 = i;
            }else if(i >= max_3)
            {
                max_3 = i;
            }
            
            if(i <= min_1)
            {
                min_2 = min_1;
                min_1 = i;
            }
            else if(i <= min_2)
            {
                min_2 = i;
            }
        }
        
        return max(min_1 * min_2 * max_1, max_1 * max_2 * max_3);
    }
};
