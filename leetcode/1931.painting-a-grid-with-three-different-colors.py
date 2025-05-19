#  Tag: Dynamic Programming
#  Time: O(N * 48 ^ 2)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/mVdxVHIq4hQ

#  You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
#  Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.
#   
#  Example 1:
#  
#  
#  Input: m = 1, n = 1
#  Output: 3
#  Explanation: The three possible colorings are shown in the image above.
#  
#  Example 2:
#  
#  
#  Input: m = 1, n = 2
#  Output: 6
#  Explanation: The six possible colorings are shown in the image above.
#  
#  Example 3:
#  
#  Input: m = 5, n = 5
#  Output: 580986
#  
#   
#  Constraints:
#  
#  1 <= m <= 5
#  1 <= n <= 1000
#  
#  

class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        dp = [[0] * 1024 for i in range(n + 1)]
        mod = 10 ** 9 + 7

        def dfs(i: int, j: int, cur: int, pre: int) -> int:
            if i == m:
                return dfs(0, j + 1, 0, cur)

            if j == n:
                return 1

            if (i == 0 and dp[j][pre] > 0):
                return dp[j][pre]

            res = 0
            up = 0 if i == 0 else (cur >> ((i - 1) * 2)) & 3
            left = (pre >> (i * 2)) & 3
            for k in range(1, 4):
                if k != up and k != left:
                    res += dfs(i + 1, j, k << (i * 2) | cur, pre)
                    res %= mod

            if i == 0:
                dp[j][pre] = res

            return res

        return dfs(0, 0, 0, 0)