class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        if (k == 0 || prices.size() == 0)
        {
            return 0;
        }
        
        int m  = prices.size();
        int res = 0;
        
        if (k > m / 2) // same as stock 2
        {
            for(auto i = 1; i < m; ++i)
            {
                if (prices[i] - prices[i - 1] > 0)
                {
                    res += (prices[i] - prices[i - 1]);
                }
            }
        }
        else // same as stock 3
        {
            int state = 2 * k + 1;
            vector<vector<int>> table(m + 1, vector<int>(state + 1, 0));
            // init
            for (auto j = 1; j <= state; ++j)
            {
                table[0][j] = (j == 1) ? 0 : INT_MIN;
            }
            
            for (auto i = 1; i <= m; ++i)
            {
                for (auto j = 1; j <= state; ++j)
                {
                    int value = 0;
                    if (j % 2 == 1) // 1, 3, 5 ...
                    {
                        // f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + prices[i - 1] - prices[i - 2])
                        value = table[i - 1][j];
                        if (i - 2 >= 0 && j > 1 && table[i - 1][j - 1] != INT_MIN)
                        {
                            value = max(value, table[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
                        }
                    }
                    else // 2, 4, 6 ...
                    {
                        // f[i][j] = max(f[i - 1][j - 1], f[i - 1][j] + prices[i - 1] - prices[i - 2], f[i - 1][j - 2] + prices[i - 1] - prices[i - 2])
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
            
            for (auto j = 1; j <= state; j+=2) {
                res = max(res, table[m][j]);
            }
        }
        
        return res;
    }
};