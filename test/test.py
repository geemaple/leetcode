from typing import (
    List,
)


from collections import defaultdict
import heapq
class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        graph = defaultdict(list)
        for i, j, w in edges:
            graph[i].append((j, w))
            graph[j].append((i, w))

        visited = {}
        heap = [(0, 0)]

        while len(heap) > 0:
            cost, city = heapq.heappop(heap)
            if city in visited:
                continue
        
            visited[city] = cost
            for node, node_cost in graph[city]:
                if node not in visited and cost + node_cost + 1 <= maxMoves:
                    heapq.heappush(heap, (cost + node_cost + 1, node))

        print(visited)
        res = len(visited)
        for i, j, w in edges:
            if i in visited and j in visited:
                moves = min(visited[i], visited[j])
                res += min(maxMoves - moves, w)

        return res


s = Solution()
res = s.reachableNodes([[0,1,10],[0,2,1],[1,2,2]], 6, 3)
print(res)