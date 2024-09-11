#  Tag: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
#  Time: O(MN)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
#  An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
#   
#  Example 1:
#  
#  Input: grid = [
#    ["1","1","1","1","0"],
#    ["1","1","0","1","0"],
#    ["1","1","0","0","0"],
#    ["0","0","0","0","0"]
#  ]
#  Output: 1
#  
#  Example 2:
#  
#  Input: grid = [
#    ["1","1","0","0","0"],
#    ["1","1","0","0","0"],
#    ["0","0","1","0","0"],
#    ["0","0","0","1","1"]
#  ]
#  Output: 3
#  
#   
#  Constraints:
#  
#  m == grid.length
#  n == grid[i].length
#  1 <= m, n <= 300
#  grid[i][j] is '0' or '1'.
#  
#  

from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])

        directions = [-1, 0, 1, 0, -1]
        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    count += 1
                    q = deque()
                    q.append((i, j))
                    grid[i][j] = '0'
                    while(len(q) > 0):
                        x, y = q.popleft()
                        for k in range(4):
                            new_x = x + directions[k]
                            new_y = y + directions[k + 1]
                            if 0 <= new_x < n and 0 <= new_y < m and grid[new_x][new_y] == '1':
                                grid[new_x][new_y] = '0'
                                q.append((new_x, new_y))

        return count

class UnionFind:
    def __init__(self, n):
        self.table = [i for i in range(n)]

    def find(self, a):
        if a == self.table[a]:
            return a

        self.table[a] = self.find(self.table[a])
        return self.table[a]

    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.table[root_a] = root_b
            return True
        return False

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])

        uf = UnionFind(n * m)
        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    count += 1

        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    if j + 1 < m and grid[i][j + 1] == '1' and uf.connect(i * m + j, i * m + j + 1):
                        count -= 1
                    if i + 1 < n and grid[i + 1][j] == '1' and uf.connect(i * m + j, (i + 1) * m + j):
                        count -= 1

        return count