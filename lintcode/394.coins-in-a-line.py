#  Tag: Dynamic Programming/DP, Game DP, Game Theory
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  There are `n` coins in a line.
#  Two players take turns to take one or two coins from right side until there are no more coins left.
#  The player who take the last coin wins.
#  
#  Could you please decide the **first** player will win or lose?
#  
#  If the first player wins, return `true`, otherwise return `false`.
#  
#  **Example 1:**
#  
#  ```
#  Input: 1
#  Output: true
#  ```
#  
#  **Example 2:**
#  
#  ```
#  Input: 4
#  Output: true
#  Explanation:
#  The first player takes 1 coin at first. Then there are 3 coins left.
#  Whether the second player takes 1 coin or two, then the first player can take all coin(s) left.
#  ```
#  
#  

class Solution:
    """
    @param n: An integer
    @return: A boolean which equals to true if the first player will win
    """
    def first_will_win(self, n: int) -> bool:
        # write your code here
        if n == 0:
            return False

        if n <= 2:
            return True

        dp = [False for i in range(1 + n)]
        dp[1] = dp[2] = True
        for i in range(3, n + 1):
            dp[i] = not (dp[i - 1] and dp[i - 2]) 

        return dp[n]

class Solution:
    """
    @param n: An integer
    @return: A boolean which equals to true if the first player will win
    """
    def first_will_win(self, n: int) -> bool:
        # write your code here
        return n % 3 != 0