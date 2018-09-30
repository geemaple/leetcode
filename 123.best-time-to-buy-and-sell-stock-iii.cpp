class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
        {
            return 0;
        }
        
        int m = prices.size();
        vector<vector<int>> table(m + 1, vector<int>(5 + 1, 0));
        
        // init
        for(auto j = 1; j <= 5; ++j)
        {
            table[0][j] = (j == 1)? 0: INT_MIN;
        }
        
        for (auto i = 1; i <= m; ++i)
        {
            for (auto j = 1; j <= 5; ++j)
            {
                int value = INT_MIN;
                
                if (j % 2 == 1) // 1, 3, 5
                {
                    value = table[i - 1][j];
                    
                    if (i - 2 >= 0 && j > 1 && table[i - 1][j - 1] != INT_MIN)
                    {
                        value = max(value, table[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
                    }
                }
                else // 2, 4
                {
                    value = table[i - 1][j - 1];
                    
                    if (i - 2 >= 0 && table[i - 1][j] != INT_MIN)
                    {
                        value = max(value, table[i - 1][j] + prices[i - 1] - prices[i - 2]);
                    }
                    
                    if (i - 2 >= 0 && j > 2 && table[i - 1][j - 2] != INT_MIN)
                    {
                        value = max(value, table[i - 1][j - 2] + prices[i - 1] - prices[i - 2]);
                    }
                }
                
                table[i][j] = value;
            }
        }
        
        int res = 0;
        for(auto j = 1; j <= 5; j+=2)
        {
            res = max(res, table[m][j]);
        }
        
        return res;
    }
};