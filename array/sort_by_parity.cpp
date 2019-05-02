class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        const int size = static_cast<int>(A.size());
        
        vector<int> result(size, 0);
        vector<int> temp;
        
        int idx_even = 0, idx_odd = 0;
        
        for(int  i = 0; i < size; ++i)
        {
            if(A[i] % 2 == 0)
            {
                result[idx_even] = A[i];
                ++idx_even;
            }
            else
            {
                temp.push_back(A[i]);
            }
        }
        
        for(int i = 0; i < temp.size(); ++i)
            result[i + idx_even] = temp[i];
        
        return result;
    }
};

    vector<int> sortArrayByParity(vector<int>& A) {
        
        int i = 0, j = A.size()-1;
        
        while(i < j)
        {
            if(A[i] % 2 > A[j] % 2)
            {
                const int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
            
            if(A[i] % 2 == 0) ++i;
            if(A[j] % 2 == 1) --j;
                
        }
        
        return A;

    }
