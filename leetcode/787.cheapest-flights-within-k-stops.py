#  Tag: Dynamic Programming, Depth-First Search, Breadth-First Search, Graph, Heap (Priority Queue), Shortest Path
#  Time: O(ElogV)
#  Space: O(E+V)
#  Ref: -
#  Note: -

#  There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
#  You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
#   
#  Example 1:
#  
#  
#  Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
#  Output: 700
#  Explanation:
#  The graph is shown above.
#  The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
#  Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
#  
#  Example 2:
#  
#  
#  Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
#  Output: 200
#  Explanation:
#  The graph is shown above.
#  The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
#  
#  Example 3:
#  
#  
#  Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
#  Output: 500
#  Explanation:
#  The graph is shown above.
#  The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
#  
#   
#  Constraints:
#  
#  1 <= n <= 100
#  0 <= flights.length <= (n * (n - 1) / 2)
#  flights[i].length == 3
#  0 <= fromi, toi < n
#  fromi != toi
#  1 <= pricei <= 104
#  There will not be any multiple flights between two cities.
#  0 <= src, dst, k < n
#  src != dst
#  
#  

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        cost = [float('inf') for i in range(n)]
        cost[src] = 0
        for i in range(k + 1):
            tmp = list(cost)
            for u, v, w in flights:
                if cost[u] < float('inf') and cost[u] + w < tmp[v]:
                    tmp[v] = cost[u] + w
            cost = tmp
                
        return cost[dst] if cost[dst] < float('inf') else -1

from collections import defaultdict
import heapq
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = defaultdict(dict)
        for x, y, p in flights:
            graph[x][y] = p

        cost_map = {}
        stop_map = {}
        heap = [(0, src, 0)]
        while len(heap) > 0:
            cost, cur, stop = heapq.heappop(heap)
    
            if cur == dst:
                return cost

            if stop == k + 1:
                continue

            cost_map[cur] = cost
            stop_map[cur] = stop

            for node, node_cost in graph[cur].items():
                if node not in cost_map or cost + node_cost < cost_map[node] or stop + 1 < stop_map[node]:
                    heapq.heappush(heap, (node_cost + cost, node, stop + 1))

        return -1