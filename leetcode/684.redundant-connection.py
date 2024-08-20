#  Tag: Depth-First Search, Breadth-First Search, Union Find, Graph
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  In this problem, a tree is an undirected graph that is connected and has no cycles.
#  You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
#  Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
#   
#  Example 1:
#  
#  
#  Input: edges = [[1,2],[1,3],[2,3]]
#  Output: [2,3]
#  
#  Example 2:
#  
#  
#  Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
#  Output: [1,4]
#  
#   
#  Constraints:
#  
#  n == edges.length
#  3 <= n <= 1000
#  edges[i].length == 2
#  1 <= ai < bi <= edges.length
#  ai != bi
#  There are no repeated edges.
#  The given graph is connected.
#  
#  

class UnionFind:
    def __init__(self, n):
        self.nodes = [i for i in range(n + 1)]

    def find(self, a: int) ->int:
        if self.nodes[a] == a:
            return a
        self.nodes[a] = self.find(self.nodes[a])
        return self.nodes[a]

    def connect(self, a: int, b: int) -> bool:
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a == root_b:
            return False
        else:
            self.nodes[root_a] = root_b
            return True

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        uf = UnionFind(n)

        for x in edges:
            if not uf.connect(x[0], x[1]):
                return x