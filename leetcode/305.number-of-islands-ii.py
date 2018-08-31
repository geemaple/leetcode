class UnionFind(object):
    def __init__(self):
        self.graph = {}
    
    def add(self, node):
        self.graph[node] = node
    
    def find(self, node):
        if self.graph[node] == node:
            return node
        
        self.graph[node] = self.find(self.graph[node])
        return self.graph[node]
    
    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.graph[root_a] = root_b
            return True
        
        return False

DIRECTIONS = [[0, 1],[-1, 0],[0, -1],[1, 0]]

class Solution(object):
    def numIslands2(self, m, n, positions):
        """
            :type m: int
            :type n: int
            :type positions: List[List[int]]
            :rtype: List[int]
            """
        
        islands = set()
        uf = UnionFind()
        size = 0
        res = []
        
        for pos in positions:
            x = pos[0]
            y = pos[1]
            
            if (x, y) not in islands:
                islands.add((x, y))
                uf.add((x, y))
                size += 1
                
                for direction in DIRECTIONS:
                    new_x = x + direction[0]
                    new_y = y + direction[1]
                    
                    if (0 <= new_x < m and 0 <= new_y < n):
                        if (new_x, new_y) in islands:
                            if (uf.connect((x, y), (new_x, new_y))):
                                size -= 1
            
        res.append(size)
        
    return res
