#  Tag: Union Find, Breadth First Search/BFS
#  Time: O(N)
#  Space: O(N)
#  Ref: LeetCode-261
#  Note: -

#  Given `n` nodes labeled from `0` to `n - 1` and a list of `undirected` edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
#  
#  **Example 1:**
#  ```
#  Input: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
#  Output: true.
#  ```
#  
#  **Example 2:**
#  ```
#  Input: n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
#  Output: false.
#  ```
#  
#  You can assume that no duplicate edges will appear in edges. Since all edges are `undirected`, `[0, 1]` is the same as `[1, 0]` and thus will not appear together in edges.

from typing import (
    List,
)

class UnionFind:
    def __init__(self, n):
        self.table = [i for i in range(n)]

    def find(self, a) -> int:
        if a == self.table[a]:
            return a

        self.table[a] = self.find(self.table[a])
        return self.table[a]

    def connect(self, a, b) -> bool:
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.table[root_a] = root_b
            return True
        return False

class Solution:
    """
    @param n: An integer
    @param edges: a list of undirected edges
    @return: true if it's a valid tree, or false
    """
    def valid_tree(self, n: int, edges: List[List[int]]) -> bool:
        # write your code here
        if len(edges) != n - 1:
            return False

        count = n
        uf = UnionFind(n)
        for x, y in edges:
            if uf.connect(x, y):
                count -= 1

        return count == 1
    

from typing import (
    List,
)
from collections import defaultdict, deque
class Solution:
    """
    @param n: An integer
    @param edges: a list of undirected edges
    @return: true if it's a valid tree, or false
    """
    def valid_tree(self, n: int, edges: List[List[int]]) -> bool:
        # write your code here
        if len(edges) != n - 1:
            return False

        graph = defaultdict(list)
        for x, y in edges:
            graph[x].append(y)
            graph[y].append(x)

        q = deque([0])
        visited = set([0])

        while len(q) > 0:
            cur = q.popleft()
            for next_node in graph[cur]:
                if next_node not in visited:
                    q.append(next_node)
                    visited.add(next_node)

        return len(visited) == n



