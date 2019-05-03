class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        
        vector<int> result(digits.size(), 0);
        int carry  = 1;
        
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            int sum = digits[i] + carry;
            carry = sum > 9;
            
            result[i] = sum % 10;
        }
        
        if(carry)
        {
            result = vector<int>(digits.size() + 1, 0);
            result[0] = 1;
        }
        
        return result;
    }
};
