#  Tag: Array, Binary Search, Breadth-First Search, Matrix
#  Time: O(MNlog(MN))
#  Space: O(MN)
#  Ref: -
#  Note: -

#  You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:
#  
#  0 represents grass,
#  1 represents fire,
#  2 represents a wall that you and fire cannot pass through.
#  
#  You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.
#  Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.
#  Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.
#  A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
#   
#  Example 1:
#  
#  
#  Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
#  Output: 3
#  Explanation: The figure above shows the scenario where you stay in the initial position for 3 minutes.
#  You will still be able to safely reach the safehouse.
#  Staying for more than 3 minutes will not allow you to safely reach the safehouse.
#  Example 2:
#  
#  
#  Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
#  Output: -1
#  Explanation: The figure above shows the scenario where you immediately move towards the safehouse.
#  Fire will spread to any cell you move towards and it is impossible to safely reach the safehouse.
#  Thus, -1 is returned.
#  
#  Example 3:
#  
#  
#  Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
#  Output: 1000000000
#  Explanation: The figure above shows the initial grid.
#  Notice that the fire is contained by walls and you will always be able to safely reach the safehouse.
#  Thus, 109 is returned.
#  
#   
#  Constraints:
#  
#  m == grid.length
#  n == grid[i].length
#  2 <= m, n <= 300
#  4 <= m * n <= 2 * 104
#  grid[i][j] is either 0, 1, or 2.
#  grid[0][0] == grid[m - 1][n - 1] == 0
#  
#  

import heapq
from collections import deque
class Solution:
    def maximumMinutes(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        directions = [-1, 0, 1, 0, -1]

        fire = [[float('inf')] * m for i in range(n)]
        visited = [[False] * m for i in range(n)]
        q = deque()
    
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    q.append((i, j))

        t = 0
        while len(q) > 0:
            size = len(q)
            for _ in range(size):
                i, j = q.popleft()
                fire[i][j] = t
                for d in range(4):
                    dx = i + directions[d]
                    dy = j + directions[d + 1]
                    if 0 <= dx < n and 0 <= dy < m and grid[dx][dy] == 0 and not visited[dx][dy]:
                        q.append((dx, dy))
                        visited[dx][dy] = True

            t += 1

        heap = [(-fire[0][0], 0, 0, 0)]
        
        res = float('inf')
        while len(heap) > 0:
            left, i, j, t = heapq.heappop(heap)
            if fire[i][j] == -1:
                continue

            fire[i][j] = -1
            res = min(res, -left)
            if i == n - 1 and j == m - 1:
                return res if res < float('inf') else 10 ** 9
            elif -left < 0:
                return -1

            for d in range(4):
                dx = i + directions[d]
                dy = j + directions[d + 1]
                if 0 <= dx < n and 0 <= dy < m and grid[dx][dy] == 0 and fire[dx][dy] != -1:
                    if dx == n - 1 and dy == m - 1:
                        heapq.heappush(heap, (-(fire[dx][dy] - t - 1) , dx, dy, t + 1))
                    else:
                        heapq.heappush(heap, (-(fire[dx][dy] - t - 2), dx, dy, t + 1))

        return -1
