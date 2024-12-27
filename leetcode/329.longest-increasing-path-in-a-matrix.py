#  Tag: Array, Dynamic Programming, Depth-First Search, Breadth-First Search, Graph, Topological Sort, Memoization, Matrix
#  Time: O(NM)
#  Space: O(NM)
#  Ref: -
#  Note: -

#  Given an m x n integers matrix, return the length of the longest increasing path in matrix.
#  From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
#   
#  Example 1:
#  
#  
#  Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
#  Output: 4
#  Explanation: The longest increasing path is [1, 2, 6, 9].
#  
#  Example 2:
#  
#  
#  Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
#  Output: 4
#  Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
#  
#  Example 3:
#  
#  Input: matrix = [[1]]
#  Output: 1
#  
#   
#  Constraints:
#  
#  m == matrix.length
#  n == matrix[i].length
#  1 <= m, n <= 200
#  0 <= matrix[i][j] <= 231 - 1
#  
#  

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        dp = [[0] * m for i in range(n)]

        res = 0
        for i in range(n):
            for j in range(m):
                res = max(res, self.dfs(i, j, matrix, dp))

        return res


    def dfs(self, i: int, j: int, matrix: List[List[int]], dp: list) -> int:

        if dp[i][j] == 0:
            n = len(matrix)
            m = len(matrix[0])

            directions = [-1, 0, 1, 0, -1]

            res = 1
            for d in range(4):
                x = i + directions[d]
                y = j + directions[d + 1]

                if 0 <= x < n and 0 <= y < m and matrix[x][y] > matrix[i][j]:
                    res = max(res, 1 + self.dfs(x, y, matrix, dp))

            dp[i][j] = res

        return dp[i][j]