//  Tag: Array, Dynamic Programming
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given an array prices where prices[i] is the price of a given stock on the ith day.
//  Find the maximum profit you can achieve. You may complete at most two transactions.
//  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//   
//  Example 1:
//  
//  Input: prices = [3,3,5,0,0,3,1,4]
//  Output: 6
//  Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//  Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
//  Example 2:
//  
//  Input: prices = [1,2,3,4,5]
//  Output: 4
//  Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//  Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
//  
//  Example 3:
//  
//  Input: prices = [7,6,4,3,1]
//  Output: 0
//  Explanation: In this case, no transaction is done, i.e. max profit = 0.
//  
//   
//  Constraints:
//  
//  1 <= prices.length <= 105
//  0 <= prices[i] <= 105
//  
//  

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> buy(3, INT_MIN);
        vector<int> sell(3, 0);

        for (auto p: prices) {
            for (int i = 1; i <= 2; i++) {
                buy[i] = max(buy[i], sell[i - 1] - p);
                sell[i] = max(sell[i], buy[i] + p);
            }
        }

        return max(sell[1], sell[2]);
    }
};

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