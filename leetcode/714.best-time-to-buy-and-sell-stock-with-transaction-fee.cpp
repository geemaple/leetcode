//  Tag: Array, Dynamic Programming, Greedy
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
//  Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
//  Note:
//  
//  You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//  The transaction fee is only charged once for each stock purchase and sale.
//  
//   
//  Example 1:
//  
//  Input: prices = [1,3,2,8,4,9], fee = 2
//  Output: 8
//  Explanation: The maximum profit can be achieved by:
//  - Buying at prices[0] = 1
//  - Selling at prices[3] = 8
//  - Buying at prices[4] = 4
//  - Selling at prices[5] = 9
//  The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
//  
//  Example 2:
//  
//  Input: prices = [1,3,7,5,10,3], fee = 3
//  Output: 6
//  
//   
//  Constraints:
//  
//  1 <= prices.length <= 5 * 104
//  1 <= prices[i] < 5 * 104
//  0 <= fee < 5 * 104
//  
//  

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buy(n + 1, INT_MIN);
        vector<int> sell(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int s = 0; s < i; s++) {
                buy[s + 1] = max(buy[s + 1], sell[s] - prices[i - 1]);
                sell[s + 1] = max(sell[s + 1], buy[s + 1] + prices[i - 1] - fee);
            }
        }

        return *max_element(sell.begin(), sell.end());
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;
        for (auto p: prices) {
            buy = max(buy, sell - p);
            sell = max(sell, buy + p - fee);
        }

        return sell;
    }
};