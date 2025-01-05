//  Tag: Array, Dynamic Programming
//  Time: O(NM)
//  Space: O(NM)
//  Ref: -
//  Note: -

//  You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//  Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
//  You may assume that you have an infinite number of each kind of coin.
//  The answer is guaranteed to fit into a signed 32-bit integer.
//   
//  Example 1:
//  
//  Input: amount = 5, coins = [1,2,5]
//  Output: 4
//  Explanation: there are four ways to make up the amount:
//  5=5
//  5=2+2+1
//  5=2+1+1+1
//  5=1+1+1+1+1
//  
//  Example 2:
//  
//  Input: amount = 3, coins = [2]
//  Output: 0
//  Explanation: the amount of 3 cannot be made up just with coins of 2.
//  
//  Example 3:
//  
//  Input: amount = 10, coins = [10]
//  Output: 1
//  
//   
//  Constraints:
//  
//  1 <= coins.length <= 300
//  1 <= coins[i] <= 5000
//  All the values of coins are unique.
//  0 <= amount <= 5000
//  
//  

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(amount + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[n][amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[amount];
    }
};