#  Tag: Array, Dynamic Programming, Matrix
#  Time: O(MN)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
#  Note: You can only move either down or right at any point in time.
#   
#  Example 1:
#  
#  
#  Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
#  Output: 7
#  Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
#  
#  Example 2:
#  
#  Input: grid = [[1,2,3],[4,5,6]]
#  Output: 12
#  
#   
#  Constraints:
#  
#  m == grid.length
#  n == grid[i].length
#  1 <= m, n <= 200
#  0 <= grid[i][j] <= 200
#  
#  

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        dp = [[0] * m for i in range(n)]
        for i in range(n):
            for j in range(m):
                if i == 0 and j == 0:
                    dp[i][j] = grid[i][j]
                elif i == 0:
                    dp[i][j] = dp[i][j - 1] + grid[i][j]
                elif j == 0:
                    dp[i][j] = dp[i - 1][j] + grid[i][j]
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]

        return dp[n - 1][m - 1]