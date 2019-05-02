class Solution {
public:
    void reverseString(vector<char>& s) {
        
        const int j = s.size() - 1;
        
        for(int i = 0; i < s.size() * 0.5; ++i)
        {
            const char t = s[i];
            
            s[i]  = s[j - i];
            s[j - i] = t;
        }
    }
};
