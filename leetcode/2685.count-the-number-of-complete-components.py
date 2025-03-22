#  Tag: Depth-First Search, Breadth-First Search, Union Find, Graph
#  Time: O(E + V)
#  Space: O(V)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/-ZFA0_oaUDo

#  You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
#  Return the number of complete connected components of the graph.
#  A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
#  A connected component is said to be complete if there exists an edge between every pair of its vertices.
#   
#  Example 1:
#  
#  
#  Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
#  Output: 3
#  Explanation: From the picture above, one can see that all of the components of this graph are complete.
#  
#  Example 2:
#  
#  
#  Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
#  Output: 1
#  Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
#  
#   
#  Constraints:
#  
#  1 <= n <= 50
#  0 <= edges.length <= n * (n - 1) / 2
#  edges[i].length == 2
#  0 <= ai, bi <= n - 1
#  ai != bi
#  There are no repeated edges.
#  
#  

from collections import defaultdict
class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for s, e in edges:
            graph[s].append(e)
            graph[e].append(s)

        res = 0
        visited = set()
        for i in range(n):
            if self.dfs(graph, i, visited):
                res += 1
        return res

    def dfs(self, graph: dict, node: int, visited: set) -> bool:
        if node in visited:
            return False

        stack = [node]
        visited.add(node)
        vertex = 0
        edge = 0
        while len(stack) > 0:
            cur = stack.pop()
            vertex += 1
            edge += len(graph[cur])

            for neighbor in graph[cur]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    stack.append(neighbor)

        return vertex * (vertex - 1) == edge

class UnionFind:
    def __init__(self, n: int):
        self.table = [i for i in range(n)]
        self.edges = [0 for i in range(n)]
        self.count = [1 for i in range(n)]

    def find(self, a: int) -> int:
        if a == self.table[a]:
            return a
        self.table[a] = self.find(self.table[a])
        return self.table[a]

    def connect(self, a: int, b: int):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.count[root_a] += self.count[root_b]
            self.edges[root_a] += self.edges[root_b]
            self.table[root_b] = root_a

        self.edges[root_a] += 1


class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        uf = UnionFind(n)
        for s, e in edges:
            uf.connect(s, e)

        visited = set()
        res = 0
        for node in range(n):
            root = uf.find(node)
            if root in visited:
                continue

            visited.add(root)
            count = uf.count[root] * (uf.count[root] - 1) // 2
            if count == uf.edges[root]:
                res += 1

        return res
