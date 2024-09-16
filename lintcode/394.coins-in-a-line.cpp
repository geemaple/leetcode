//  Tag: Dynamic Programming/DP, Game DP, Game Theory
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  There are `n` coins in a line.
//  Two players take turns to take one or two coins from right side until there are no more coins left.
//  The player who take the last coin wins.
//  
//  Could you please decide the **first** player will win or lose?
//  
//  If the first player wins, return `true`, otherwise return `false`.
//  
//  **Example 1:**
//  
//  ```
//  Input: 1
//  Output: true
//  ```
//  
//  **Example 2:**
//  
//  ```
//  Input: 4
//  Output: true
//  Explanation:
//  The first player takes 1 coin at first. Then there are 3 coins left.
//  Whether the second player takes 1 coin or two, then the first player can take all coin(s) left.
//  ```
//  
//  

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        if (n == 0) {
            return false;
        }

        if (n <= 2) {
            return true;
        }

        vector<bool> dp(n + 1, false);
        dp[1] = true;
        dp[2] = true;
        for (int i = 3; i <= n; i++) {
            dp[i] = !(dp[i - 1] && dp[i - 2]);
        }

        return dp[n];
    }
};

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        return n % 3 != 0;
    }
};