
from typing import List
from collections import defaultdict
import heapq
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        graph = defaultdict(dict)
        for i in range(len(edges)):
            x, y = edges[i]
            graph[x][y] = succProb[i]
            graph[y][x] = succProb[i]

        heap = [(-1, start_node)]
        visited = set()
        res = 0

        while len(heap) > 0:
            pro, cur = heapq.heappop(heap)


            if cur in visited:
                continue

            if cur == end_node:
                res = max(-pro, res)

            visited.add(cur)
            if cur == end_node:
                res = max(-pro, res)
            for node, node_pro in graph[cur].items():
                if node not in visited:
                    heapq.heappush(heap, (pro * node_pro, node))

        return res
            


s = Solution()
res = s.maxProbability(5, [[1,4],[2,4],[0,4],[0,3],[0,2],[2,3]], [0.37,0.17,0.93,0.23,0.39,0.04], 3, 4)
print(res)