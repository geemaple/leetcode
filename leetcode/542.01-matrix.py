#  Tag: Array, Dynamic Programming, Breadth-First Search, Matrix
#  Time: O(MN)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
#  The distance between two adjacent cells is 1.
#   
#  Example 1:
#  
#  
#  Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
#  Output: [[0,0,0],[0,1,0],[0,0,0]]
#  
#  Example 2:
#  
#  
#  Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
#  Output: [[0,0,0],[0,1,0],[1,2,1]]
#  
#   
#  Constraints:
#  
#  m == mat.length
#  n == mat[i].length
#  1 <= m, n <= 104
#  1 <= m * n <= 104
#  mat[i][j] is either 0 or 1.
#  There is at least one 0 in mat.
#  
#  

import collections
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        dp = [[float('inf') for j in range(n)] for i in range(m)]

        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    dp[i][j] = 0
                else:
                    if i > 0:
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1)

                    if j > 0:
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1)

        for i in reversed(range(m)):
            for j in reversed(range(n)):
                if mat[i][j] == 0:
                    dp[i][j] = 0
                else:
                    if i + 1 < m:
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1)

                    if j + 1 < n:
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1)

        return dp
        

import collections
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        q = collections.deque()
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    q.append((i, j))
                else:
                    mat[i][j] = -1
                    
        directions = [-1, 0, 1, 0, -1]
        while len(q) > 0:
            x, y = q.popleft()

            for k in range(4):
                dx = x + directions[k]
                dy = y + directions[k + 1]
                if 0 <= dx < m and 0 <= dy < n and mat[dx][dy] == -1:
                    mat[dx][dy] = mat[x][y] + 1
                    q.append((dx, dy))
        
        return mat