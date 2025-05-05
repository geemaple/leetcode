#  Tag: Dynamic Programming
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/UMUU_xu4yYU

#  You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
#  
#  Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.
#  In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.
#   
#  Example 1:
#  
#  
#  Input: n = 3
#  Output: 5
#  Explanation: The five different ways are show above.
#  
#  Example 2:
#  
#  Input: n = 1
#  Output: 1
#  
#   
#  Constraints:
#  
#  1 <= n <= 1000
#  
#  

class Solution:
    def numTilings(self, n: int) -> int:
        dp = [[0] * 3 for i in range(n + 1)]
        dp[0][0] = 1
        dp[1][0] = 1
        mod = 10 ** 9 + 7

        for i in range(2, n + 1):
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]) % mod
            dp[i][1] = (dp[i - 1][2] + dp[i - 2][0]) % mod
            dp[i][2] = (dp[i - 1][1] + dp[i - 2][0]) % mod

        return dp[n][0]