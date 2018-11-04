import heapq
import collections
class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, K):
        graph = collections.defaultdict(dict)
        for u, v, w in flights:
            graph[u][v] = w

        best = {}
        pq = [(0, 0, src)]
        while pq:
            cost, k, place = heapq.heappop(pq)
            if k > K+1 or cost > best.get((k, place), float('inf')): continue
            if place == dst: return cost

            for nei, wt in graph[place].iteritems():
                newcost = cost + wt
                if newcost < best.get((k+1, nei), float('inf')):
                    heapq.heappush(pq, (newcost, k+1, nei))
                    best[k+1, nei] = newcost

        return -1

class Solution2(object):
    def findCheapestPrice(self, n, flights, src, dst, K):
        table = [[float('inf')] * n for _ in range(2)]

        table[0][src] = 0
        table[1][src] = 0
        cur = 0

        for i in range(K + 1):
            pre = cur
            cur = 1 - cur
            for u, v, w in flights:
                table[cur][v] = min(table[cur][v], table[pre][u] + w)

        return table[cur][dst] if table[cur][dst] < float('inf') else -1