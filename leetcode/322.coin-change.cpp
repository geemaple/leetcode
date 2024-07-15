//  Tag: Breadth-First Search, Array, Dynamic Programming
//  Time: O(K * N)
//  Space: O(N)
//  Ref: https://youtu.be/EjMjlFjLRiM
//  Note: Index

//  You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//  Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//  You may assume that you have an infinite number of each kind of coin.
//   
//  Example 1:
//  
//  Input: coins = [1,2,5], amount = 11
//  Output: 3
//  Explanation: 11 = 5 + 5 + 1
//  
//  Example 2:
//  
//  Input: coins = [2], amount = 3
//  Output: -1
//  
//  Example 3:
//  
//  Input: coins = [1], amount = 0
//  Output: 0
//  
//   
//  Constraints:
//  
//  1 <= coins.length <= 12
//  1 <= coins[i] <= 231 - 1
//  0 <= amount <= 104
//  
//  

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
            for (auto c : coins) {
                if (i >= c && dp[i - c] < INT_MAX) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1: dp[amount];
    }
};


class Solution {
    unordered_map<int, int> cache;
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = helper(coins, amount);
        return res == INT_MAX ? -1 : res;
    }

    int helper(vector<int>& coins, int amount) {
        if (cache.find(amount) != cache.end()) {
            return cache[amount];
        }

        if (amount == 0) {
            cache[amount] = 0;
            return 0;
        }

        int count = INT_MAX;
        for (auto c : coins) {
            if (amount >= c) {
                int test = helper(coins, amount - c);
                if (test < INT_MAX) {
                    count = min(count, helper(coins, amount - c) + 1);
                }
            }
        }

        cache[amount] = count;
        return count;
    }
};

// backpack
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            int coin = coins[i - 1];
            for (int j = 0; j <= m; j++) {
                if (coin <= j && dp[i][j - coin] != INT_MAX) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coin] + 1);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m] == INT_MAX ? -1: dp[n][m];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;
        vector<int> dp(m + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int coin = coins[i - 1];
            for (int j = coin; j <= m; j++) {
                if (dp[j - coin] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coin] + 1);
                }
            }
        }

        return dp[m] == INT_MAX ? -1: dp[m];
    }
};