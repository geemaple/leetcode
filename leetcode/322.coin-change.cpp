/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (27.95%)
 * Total Accepted:    261.6K
 * Total Submissions: 810K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> table(amount + 1, INT_MAX);
        table[0] = 0;
        
        for (auto i = 1; i <= amount; ++i) {
            for (auto j = 0; j < coins.size(); ++j) {
                int pre = i - coins[j];
                if (pre >= 0 && table[pre] != INT_MAX && table[pre] + 1 < table[i]) {
                    table[i] = table[pre] + 1;
                }
            }
        }
        
        return table[amount] < INT_MAX ? table[amount] : -1;
    }
};
