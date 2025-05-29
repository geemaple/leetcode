#  Tag: Tree, Depth-First Search, Breadth-First Search
#  Time: O(N + M)
#  Space: O(N + M)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/SAe04vIvjB8

#  There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
#  You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
#  Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
#  Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
#  Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
#   
#  Example 1:
#  
#  Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
#  Output: [8,7,7,8,8]
#  Explanation:
#  
#  For i = 0, connect node 0 from the first tree to node 0 from the second tree.
#  For i = 1, connect node 1 from the first tree to node 4 from the second tree.
#  For i = 2, connect node 2 from the first tree to node 7 from the second tree.
#  For i = 3, connect node 3 from the first tree to node 0 from the second tree.
#  For i = 4, connect node 4 from the first tree to node 4 from the second tree.
#  
#  
#  Example 2:
#  
#  Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]
#  Output: [3,6,6,6,6]
#  Explanation:
#  For every i, connect node i of the first tree with any node of the second tree.
#  
#   
#  Constraints:
#  
#  2 <= n, m <= 105
#  edges1.length == n - 1
#  edges2.length == m - 1
#  edges1[i].length == edges2[i].length == 2
#  edges1[i] = [ai, bi]
#  0 <= ai, bi < n
#  edges2[i] = [ui, vi]
#  0 <= ui, vi < m
#  The input is generated such that edges1 and edges2 represent valid trees.
#  
#  

from collections import defaultdict, deque
class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        graph1 = defaultdict(list)
        for u, v in edges1:
            graph1[u].append(v)
            graph1[v].append(u)

        graph2 = defaultdict(list)
        for u, v in edges2:
            graph2[u].append(v)
            graph2[v].append(u)

        color2 = [0 for i in range(len(graph2))]
        distance2 = self.count(graph2, 0, color2)
        distance = max(distance2)

        color1 = [0 for i in range(len(graph1))]
        distance1 = self.count(graph1, 0, color1)

        res = []
        for i in range(len(graph1)):
            color = color1[i]
            res.append(distance1[color] +  distance)

        return res
    
    def count(self, graph: dict, node: int, color: list) -> list:
        q = deque([(node, 0)])
        visited = set([node])
        res = [0, 0]
        while len(q) > 0:
            cur, depth = q.popleft()
            res[depth] += 1
            color[cur] = depth
            for neighbor in graph[cur]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    q.append((neighbor, (depth + 1) % 2))

        return res

