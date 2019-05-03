class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> repetitions;
        int val = 0;
        
        for(size_t i = 0; i < A.size(); ++i)
        {
            repetitions[A[i]]++;
            
            if(repetitions[A[i]] == A.size() * 0.5)
            {
                val = A[i];
                break;
            }
        }
        
        return val;
        
    }
};
