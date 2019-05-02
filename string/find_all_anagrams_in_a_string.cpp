class Solution {
public:
    
    bool isAnagram(string a, string b)
    {       

        if (a.size() != b.size()) 
            return false; 
  
        sort(a.begin(), a.end()); 
        sort(b.begin(), b.end()); 
  
        for (int i = 0; i < a.size(); i++) 
            if (a[i] != b[i]) 
                return false; 
  
        return true;      
    } 
    
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> result;
        
        if(s.size() >= p.size())
        {
            for(int i = 0; i <= s.size() - p.size(); ++i)
            {
                const string ss = string(s.begin() + i, s.begin() + i + p.size());
                const bool is_anagram =  isAnagram(ss, p);
            
                if(is_anagram)
                    result.push_back(i);
            }    
        }
        
        return result;
    }
};

/*Sliding window approach*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> pv(26,0), sv(26,0), res;
    
        if(s.size() < p.size())
           return res;
        
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }

        if(pv == sv)
           res.push_back(0);

        for(int i = p.size(); i < s.size(); ++i) 
        {
             
            ++sv[s[i]-'a'];            
            --sv[s[i-p.size()]-'a']; 

            if(pv == sv)  
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};
