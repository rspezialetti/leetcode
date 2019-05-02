class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        vector<int> v_s(26, 0);
        vector<int> v_t(26, 0);
        
        for(size_t i = 0; i < s.size(); i++)
        {
            v_s[s[i] - 'a']++;
            v_t[t[i] - 'a']++;
        }
        
        return v_s == v_t;
    }
};
