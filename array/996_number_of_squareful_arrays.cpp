class Solution {
public:
    
    
    bool isSquareFul(vector<int>& A)
    {
        for(size_t t = 0; t < A.size()-1; ++t)
        {
            const int sum = A[t] + A[t + 1];
            const float s = sqrt(sum);
            
            if(ceil(s) != floor(s))
                return false;
        }
        
        return true;
    }
    
    string convertArrayToString(vector<int>& numbers)
    {
        string res = "";
        
        for(int n : numbers)
            res += to_string(n);
            
        return res;
    }
    
    void permutation(vector<int>& numbers, int n, map<string, int>& map_values)
    {
        if(n == 1)
        {
            const int is_valid = isSquareFul(numbers);
            map_values[convertArrayToString(numbers)] = is_valid;
        }
            
        for(size_t i = 0; i < n; ++i)
        {
            swap(numbers[i], numbers[n - 1]);
            permutation(numbers, n - 1, map_values);
            swap(numbers[i], numbers[n - 1]);
        }
    }

    int numSquarefulPerms(vector<int>& A) 
    {
        int res = 0;
        map<string, int> map_values;
        
        permutation(A, A.size(), map_values);
        
        for(auto it = map_values.begin(); it != map_values.end(); ++it)
            res += it->second;
        
        return res;
    }
};

class Solution {
public:
    
    unordered_map<int, int> count;
    unordered_map<int, unordered_set<int>> cand;
    int res = 0;
    
    int numSquarefulPerms(vector<int>& A) 
    {
        for (int &a : A) 
            count[a]++;
        
        for (auto &i : count) 
        {
            for (auto &j : count) 
            {
                int x = i.first, y = j.first, s = sqrt(x + y);
                if (s * s == x + y)
                    cand[x].insert(y);
            }
        }
        
        for (auto e : count)
            dfs(e.first, A.size() - 1);
        
        return res;
    }

    void dfs(int x, int left) 
    {
        count[x]--;
    
        if (!left) 
            res++;
        
        for (int y : cand[x])
            if (count[y] > 0)
                dfs(y, left - 1);
        
        count[x]++;
    }
    
};
