//  Tag: Array, Dynamic Programming
//  Time: O(NK)
//  Space: O(K)
//  Ref: -
//  Note: -

//  You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.
//  You are allowed to make at most k transactions, where each transaction can be either of the following:
//  
//  
//  Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].
//  
//  
//  Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].
//  
//  
//  Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.
//  Return the maximum total profit you can earn by making at most k transactions.
//   
//  Example 1:
//  
//  Input: prices = [1,7,9,8,2], k = 2
//  Output: 14
//  Explanation:
//  We can make $14 of profit through 2 transactions:
//  
//  
//  A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.
//  A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.
//  
//  
//  Example 2:
//  
//  Input: prices = [12,16,19,19,8,1,19,13,9], k = 3
//  Output: 36
//  Explanation:
//  We can make $36 of profit through 3 transactions:
//  
//  
//  A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 for $19.
//  A short selling transaction: sell the stock on day 3 for $19 then buy back on day 4 for $8.
//  A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 for $19.
//  
//  
//   
//  Constraints:
//  
//  2 <= prices.length <= 103
//  1 <= prices[i] <= 109
//  1 <= k <= prices.length / 2
//  
//  

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<long long> bought(k, LONG_LONG_MIN);
        vector<long long> res(k + 1, 0);
        vector<long long> sold(k, 0);

        for (auto &x: prices) {
            for (int j = k; j > 0; j--) {
                res[j] = max(res[j], max(bought[j - 1] + x, sold[j - 1] - x));
                bought[j - 1] = max(bought[j - 1], res[j - 1] - x);
                sold[j - 1] = max(sold[j - 1], res[j - 1] + x);
            }
        }

        return res[k];
    }
};

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(3, 0LL)));

        for (int j = 0; j <= k; ++j) {
            dp[0][j][1] = -prices[0]; // Buy
            dp[0][j][2] = prices[0]; // Sold
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] = max({dp[i - 1][j][0], dp[i - 1][j][1] + prices[i], dp[i - 1][j][2] - prices[i]});
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
};