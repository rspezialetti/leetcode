class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) 
    {
        vector<int> result;
        int i = A.size();
        int carry =  K;
        
        while(--i >=  0 || carry > 0)
        {
            if(i >= 0)
                carry += A[i];
            
            result.push_back(carry % 10);
            carry /= 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
