class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        
        for(size_t i = 0; i < prices.size(); ++i)
        {
            for(size_t j = i + 1; j < prices.size(); ++j)
            {
                int temp_profit = prices[j] - prices[i];
                
                if(prices[j] >= prices[i] && temp_profit >= profit)
                    profit = temp_profit;
            }
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int min = INT_MAX;
        int profit = 0;
        
        for(size_t i = 0; i  < prices.size(); ++i)
        {
            if(prices[i] < min)
                min = prices[i];
            
            if(prices[i] - min > profit)
                profit = prices[i] - min;
        }
        
        return profit;
        
    }
};
