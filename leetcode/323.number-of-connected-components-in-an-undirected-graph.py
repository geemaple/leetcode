class Solution(object):
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        graph = {i:[] for i in range(n)}
        
        for pair in edges:
            graph[pair[0]].append(pair[1])
            graph[pair[1]].append(pair[0])
            
        visited = set()
        count = 0
        for i in range(n):
            if i not in visited:
                count += 1
                self.dfs(graph, i, visited)
                
        return count
                
    def dfs(self, graph, start, visited):
        queue = [start]
        visited.add(start)
        
        while len(queue) > 0:
            tmp = queue.pop(0)
            
            for neighbor in graph[tmp]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)