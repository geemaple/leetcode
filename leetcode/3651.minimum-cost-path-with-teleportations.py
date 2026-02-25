#  Tag: Array, Dynamic Programming, Matrix
#  Time: O((K+logMN) * MN)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  You are given a m x n 2D integer array grid and an integer k. You start at the top-left cell (0, 0) and your goal is to reach the bottom‐right cell (m - 1, n - 1).
#  There are two types of moves available:
#  
#  
#  Normal move: You can move right or down from your current cell (i, j), i.e. you can move to (i, j + 1) (right) or (i + 1, j) (down). The cost is the value of the destination cell.
#  
#  
#  Teleportation: You can teleport from any cell (i, j), to any cell (x, y) such that grid[x][y] <= grid[i][j]; the cost of this move is 0. You may teleport at most k times.
#  
#  
#  Return the minimum total cost to reach cell (m - 1, n - 1) from (0, 0).
#   
#  Example 1:
#  
#  Input: grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2
#  Output: 7
#  Explanation:
#  Initially we are at (0, 0) and cost is 0.
#  
#  
#  
#  Current Position
#  Move
#  New Position
#  Total Cost
#  
#  
#  (0, 0)
#  Move Down
#  (1, 0)
#  0 + 2 = 2
#  
#  
#  (1, 0)
#  Move Right
#  (1, 1)
#  2 + 5 = 7
#  
#  
#  (1, 1)
#  Teleport to (2, 2)
#  (2, 2)
#  7 + 0 = 7
#  
#  
#  
#  The minimum cost to reach bottom-right cell is 7.
#  
#  Example 2:
#  
#  Input: grid = [[1,2],[2,3],[3,4]], k = 1
#  Output: 9
#  Explanation: 
#  Initially we are at (0, 0) and cost is 0.
#  
#  
#  
#  Current Position
#  Move
#  New Position
#  Total Cost
#  
#  
#  (0, 0)
#  Move Down
#  (1, 0)
#  0 + 2 = 2
#  
#  
#  (1, 0)
#  Move Right
#  (1, 1)
#  2 + 3 = 5
#  
#  
#  (1, 1)
#  Move Down
#  (2, 1)
#  5 + 4 = 9
#  
#  
#  
#  The minimum cost to reach bottom-right cell is 9.
#  
#   
#  Constraints:
#  
#  2 <= m, n <= 80
#  m == grid.length
#  n == grid[i].length
#  0 <= grid[i][j] <= 104
#  0 <= k <= 10
#  
#  

class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        points = [(i, j) for i in range(m) for j in range(n)]
        points.sort(key=lambda p: grid[p[0]][p[1]])
      
        dp = [[float("inf")] * n for _ in range(m)]
        for t in range(k + 1):
            minCost = float("inf")
            j = 0
            for i in range(len(points)):
                minCost = min(minCost, dp[points[i][0]][points[i][1]])
                if (i + 1 < len(points) and grid[points[i][0]][points[i][1]] == grid[points[i + 1][0]][points[i + 1][1]]):
                    i += 1
                    continue
                for r in range(j, i + 1):
                    dp[points[r][0]][points[r][1]] = minCost
                j = i + 1
                
            for i in range(m - 1, -1, -1):
                for j in range(n - 1, -1, -1):
                    if i == m - 1 and j == n - 1:
                        dp[i][j] = 0
                        continue
                    if i != m - 1:
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + grid[i + 1][j])
                    if j != n - 1:
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + grid[i][j + 1])
        return dp[0][0]