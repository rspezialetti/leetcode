class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        map<int, int> map_v;
        
        for(int i : nums)
        {       
            if( i > 0 )
                map_v[i]++;
        }
        
        int res = 0;
        
        auto it = map_v.begin();
        int prev = map_v.begin()->first;
        
        if(prev != 1)
            return 1;
        
        it = it++;

        for(; it != map_v.end(); ++it)
        {
            const int diff = it->first - prev;
            if(diff > 1 && res ==0 )
                res = prev + 1;    
            
            prev = it->first;
        }
        
        if(res == 0)
            res = map_v.end()->first + 1;
            
        return res;
    }
};
