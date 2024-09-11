
from typing import List
from collections import defaultdict
import heapq

from collections import defaultdict
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



s = Solution()
res = s.numIslands([["1","0"]])
print(res)