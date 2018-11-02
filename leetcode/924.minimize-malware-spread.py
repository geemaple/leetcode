import collections
class UnionFind(object):
    def __init__(self, n):
        self.nodes = []
        self.count = []
        
        for i in range(n):
            self.nodes.append(i)
            self.count.append(1)
    
    def find(self, a):
        if self.nodes[a] == a:
            return a
        self.nodes[a] = self.find(self.nodes[a])
        return self.nodes[a]
    
    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.nodes[root_a] = root_b
            self.count[root_b] += self.count[root_a]
    
    def nodes_contaminate(self, a):
        root_a = self.find(a)
        return self.count[root_a]
    
    def is_connected(self, a, b):
        return self.find(a) == self.find(b)

class Solution(object):
    def minMalwareSpread(self, graph, initial):
        """
        :type graph: List[List[int]]
        :type initial: List[int]
        :rtype: int
        """
        if len(initial) == 1:
            return initial[0]
        
        size = len(graph)
        uf = UnionFind(size)
        
        for i in range(len(graph)):
            for j in range(i + 1, len(graph[i])):
                if graph[i][j] == 1:
                    uf.connect(i, j)
                
        counter = collections.Counter([uf.find(n) for n in initial])
        res = min(initial)
        save = uf.nodes_contaminate(res) if counter[uf.find(res)] == 1 else 0
        
        for n in initial:
            if counter[uf.find(n)] == 1 and uf.nodes_contaminate(n) > save:
                save, res = uf.nodes_contaminate(n), n                

        return res