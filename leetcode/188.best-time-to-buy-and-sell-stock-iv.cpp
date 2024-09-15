//  Tag: Array, Dynamic Programming
//  Time: O(NK)
//  Space: O(NK)
//  Ref: -
//  Note: -

//  You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
//  Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
//  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//   
//  Example 1:
//  
//  Input: k = 2, prices = [2,4,1]
//  Output: 2
//  Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
//  
//  Example 2:
//  
//  Input: k = 2, prices = [3,2,6,5,0,3]
//  Output: 7
//  Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//  
//   
//  Constraints:
//  
//  1 <= k <= 100
//  1 <= prices.length <= 1000
//  0 <= prices[i] <= 1000
//  
//  

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        k = min(k, (int)prices.size() / 2);
        vector<int> buy = vector<int>(k + 1, INT_MIN);
        vector<int> sell = vector<int>(k + 1, 0);

        for (auto p: prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = max(buy[i], sell[i - 1] - p);
                sell[i] = max(sell[i], buy[i] + p);
            }
        }

        return sell[k];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        if (k >= prices.size()) {
            return maxProfitUnlimited(prices);
        }

        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int p : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = max(buy[i], sell[i - 1] - p);
                sell[i] = max(sell[i], buy[i] + p);
            }
        }

        return sell[k];
    }

    int maxProfitUnlimited(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i - 1] > 0) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};