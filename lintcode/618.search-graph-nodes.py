"""
Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []
"""


class Solution:
    """
    @param: graph: a list of Undirected graph node
    @param: values: a hash mapping, <UndirectedGraphNode, (int)value>
    @param: node: an Undirected graph node
    @param: target: An integer
    @return: a node
    """
    def searchNode(self, graph, values, node, target):
        # write your code here
        if node is None or len(graph) == 0 or len(values) == 0:
            return None
            
        queue = [node]
        visited = set([node])
        
        while (len(queue) > 0):
            
            size = len(queue)
            
            for i in range(size):
            
                tmp = queue.pop(0)
                
                if values[tmp] == target:
                    return tmp
                    
                for neighbor in tmp.neighbors:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
                        
        return None