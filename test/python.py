
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math

import heapq

from typing import (
    List,
)


import heapq
from collections import Counter
from collections import defaultdict
class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        n = len(edges1)
        m = len(edges2)

        graph1 = defaultdict(list)
        for u, v in edges1:
            graph1[u].append(v)
            graph1[v].append(u)

        graph2 = defaultdict(list)
        for u, v in edges2:
            graph2[u].append(v)
            graph2[v].append(u)

        distance = 0
        for i in range(len(graph2)):
            distance = max(distance, self.search_target(graph2, i, k - 1)) 

        count = min(len(graph1), len(graph2))
        res = []
        for i in range(count):
            res.append(self.search_target(graph1, i, k) + distance)
    
        return res

    
    def search_target(self, graph: dict, node: int, k: int) -> int:
        stack = [(node, 0)]
        res = 0
        visited = set([node])
        while len(stack) > 0:
            cur, dist = stack.pop()
            res += 1
            if dist < k:
                for neighbor in graph[cur]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        stack.append((neighbor, dist + 1))

        return res


s = Solution()
ts = datetime.now()

res = s.maxTargetNodes([[0,1],[0,2],[2,3],[2,4]], [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], 2)

print(datetime.now() - ts)
print(res)
