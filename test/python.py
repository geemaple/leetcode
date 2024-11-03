
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math

import heapq

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n = len(moveTime)
        m = len(moveTime[0])

        heap = [(0, 0, 0, 0)]
        directions = [-1, 0, 1, 0, -1]
        visited = set()

        res = float('inf')
        while len(heap) > 0:
            cost, i, j, delta = heapq.heappop(heap)
            if (i, j) in visited:
                continue

            visited.add((i, j))
            if i == n - 1 and j == m - 1:
                return cost

            for d in range(4):
                x = i + directions[d]
                y = j + directions[d + 1]
                if 0 <= x < n and 0 <= y < m and (x, y) not in visited:
                    next_cost = max(moveTime[x][y], cost) + delta + 1
                    heapq.heappush(heap, (next_cost, x, y, 1 - delta))
            

s = Solution()
ts = datetime.now()

res = s.minTimeToReach([[0,1],[1,2]])

print(datetime.now() - ts)
print(res)
