//  Tag: Array, Dynamic Programming
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given an array prices where prices[i] is the price of a given stock on the ith day.
//  Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
//  
//  After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
//  
//  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//   
//  Example 1:
//  
//  Input: prices = [1,2,3,0,2]
//  Output: 3
//  Explanation: transactions = [buy, sell, cooldown, buy, sell]
//  
//  Example 2:
//  
//  Input: prices = [1]
//  Output: 0
//  
//   
//  Constraints:
//  
//  1 <= prices.length <= 5000
//  0 <= prices[i] <= 1000
//  
//  

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> rest(n, 0);
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);

        buy[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], rest[i - 1] - prices[i]);
            sell[i] = buy[i] + prices[i];
            rest[i] = max(rest[i - 1], sell[i - 1]);
        }

        return max(rest[n - 1], sell[n - 1]);
    }
};