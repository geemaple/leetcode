#  Tag: Depth-First Search, Breadth-First Search, Graph, Heap (Priority Queue), Shortest Path
#  Time: O(ElogE)
#  Space: O(E+V)
#  Ref: -
#  Note: -

#  You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
#  We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
#   
#  Example 1:
#  
#  
#  Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
#  Output: 2
#  
#  Example 2:
#  
#  Input: times = [[1,2,1]], n = 2, k = 1
#  Output: 1
#  
#  Example 3:
#  
#  Input: times = [[1,2,1]], n = 2, k = 2
#  Output: -1
#  
#   
#  Constraints:
#  
#  1 <= k <= n <= 100
#  1 <= times.length <= 6000
#  times[i].length == 3
#  1 <= ui, vi <= n
#  ui != vi
#  0 <= wi <= 100
#  All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
#  
#  

from collections import defaultdict
import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = defaultdict(dict)
        for u, v, w in times:
            graph[u][v] = w

        heap = [(0, k)]
        visited = set()
        res = 0
        while len(heap) > 0:
            delay, cur = heapq.heappop(heap)
            if cur in visited:
                continue

            visited.add(cur)
            res = delay

            for node, time in graph[cur].items():
                if node not in visited:
                    heapq.heappush(heap, (time + delay, node))

        return res if len(visited) == n else -1