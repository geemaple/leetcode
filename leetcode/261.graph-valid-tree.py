class UnionFind:
    def __init__(self, n):
        self.size = n
        self.graph = {}

        for i in range(n):
            self.graph[i] = i
    
    def find(self, node):
        if self.graph[node] == node:
            return node

        self.graph[node] = self.find(self.graph[node])
        return self.graph[node]

    def union(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.size -= 1
            self.graph[root_a] = root_b

    def all_connected(self):
        return self.size == 1

class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        
        if n - 1 != len(edges):
            return False

        uf = UnionFind(n)
        for e in edges:
            uf.union(e[0], e[1])

        return uf.all_connected()


class Solution2(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        if n != 1 + len(edges):
            return False
        
        graph = {i : [] for i in range(n)}
        for i in range(len(edges)):
            graph[edges[i][0]].append(edges[i][1])
            graph[edges[i][1]].append(edges[i][0])
            
        visted = set()
        queue = [0]
        
        while len(queue) > 0:
            tmp = queue.pop(0)
            visted.add(tmp)
            
            for neighbor in graph[tmp]:
                if neighbor not in visted:
                    queue.append(neighbor)
                    
        return len(visted) == n
