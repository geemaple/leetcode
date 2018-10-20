# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if node is None:
            return None
        
        mappings = {}
        queue = [node]
        visited = set([node])
        
        while len(queue) > 0:
            cur = queue.pop(0)
            
            if cur not in mappings:
                mappings[cur] = UndirectedGraphNode(cur.label)
                
            for neighbor in cur.neighbors:
                if neighbor not in mappings:
                    mappings[neighbor] = UndirectedGraphNode(neighbor.label)
                
                mappings[cur].neighbors.append(mappings[neighbor])
                
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
                    
        return mappings[node]