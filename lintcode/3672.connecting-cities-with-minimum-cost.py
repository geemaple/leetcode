#  Tag: Graph, Greedy, Union Find
#  Time: O(ElogE)
#  Space: O(E+V)
#  Ref: Leetcode-1135
#  Note: -

#  There are `n` cities in this question, and their numbers range from 1 to n.
#  
#  At the same time, there is a `connections` array and $connections[i] = [a_i, b_i, c_i]$, which means that the cost of connecting cities $a_i$ and $b_i$ is $c_i$.
#  
#  Please return the minimum cost required to connect all cities.
#  If all cities cannot be connected, return **-1**.
#  
#  **Example 1**
#  
#  Input:
#  
#  ```plaintext
#  3
#  [[1,2,1], [2,3,2], [1,3,3]]
#  ```
#  
#  Ouput:
#  
#  ```plaintext
#  3
#  ```
#  
#  Explanation:
#  
#  Choose `[1,2,1]` and `[2,3,2]` to connect all n cities. At this time, the cost is the least, which is 3.
#  
#  **Example 2**
#  
#  Input:
#  
#  ```plaintext
#  3
#  [[1,2,1]]
#  ```
#  
#  Output:
#  
#  ```plaintext
#  -1
#  ```
#  
#  Explanation:
#  
#  Unable to connect all cities according to `connections`.
#  
#  

from typing import (
    List,
)

from collections import defaultdict
import heapq
class Solution:
    """
    @param n: the number of cities
    @param connections: the connection info between cities
    @return: 
    """
    def minimum_cost(self, n: int, connections: List[List[int]]) -> int:
        # write your code here
        graph = defaultdict(list)
        for x in connections:
            graph[x[0]].append((x[1], x[2]))
            graph[x[1]].append((x[0], x[2]))

        heap = [(0, connections[0][0])]
        visited = set()
        res = 0

        while len(heap) > 0:
            cost, city = heapq.heappop(heap)
            if city in visited:
                continue
            visited.add(city)
            res += cost
            for node, node_cost in graph[city]:
                if node not in visited:
                    heapq.heappush(heap, (node_cost, node))

        return res if len(visited) == n else -1
    
class UnionFind:
    def __init__(self, n):
        self.nodes = [i for i in range(n + 1)]
        self.count = [1 for i in range(n + 1)]
        self.max_count = 1

    def find(self, a):
        if self.nodes[a] == a:
            return a

        self.nodes[a] = self.find(self.nodes[a])
        return self.nodes[a]

    def union(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.nodes[root_a] = root_b
            self.count[root_b] += self.count[root_a]
            self.max_count = max(self.max_count, self.count[root_b])
            print(self.max_count)
            return True
        else:
            return False
    
class Solution:
    """
    @param n: the number of cities
    @param connections: the connection info between cities
    @return: 
    """
    def minimum_cost(self, n: int, connections: List[List[int]]) -> int:
        # write your code here
        connections.sort(key=lambda x: x[2])
        uf = UnionFind(n)
        res = 0    
    
        for x in connections:
            if uf.union(x[0], x[1]):
                res += x[2]

        return res if uf.max_count == n else -1