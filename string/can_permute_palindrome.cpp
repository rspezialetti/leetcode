class Solution {
public:

    
    bool canPermutePalindrome(string s) 
    {
        map<char, int> map_char;
        
        for(size_t i = 0; i < s.size(); ++i)
        {
            map_char[s[i]] += 1;
        }
        
        int count = 0;
        
        for(map<char, int>::iterator it = map_char.begin(); it !=map_char.end(); it++)
            count += it->second % 2; 
        
        return count <= 1;
    }
};
    bool canPermutePalindrome(string s) 
    {
        vector<int> v_char(26, 0);
        
        int count = 0;
        for(size_t i = 0; i  < s.size(); ++i)
        {
            v_char[s[i] - 'a']++;
            
            if(v_char[s[i] - 'a'] % 2)
                count--;
            else
                count++;    
        }
        return count <= 1;
    }
