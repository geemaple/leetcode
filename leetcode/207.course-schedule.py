class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        indegree = {i:0 for i in range(numCourses)}
        graph = {i:[] for i in range(numCourses)}
        take = 0
        
        for pair in prerequisites:
            indegree[pair[0]] += 1
            graph[pair[1]].append(pair[0])
                
        q = []
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
                
        while(len(q) > 0):
            c = q.pop(0)
            take += 1
            
            for neighbor in graph[c]:
                if indegree.get(neighbor, 0) > 0:
                    indegree[neighbor] -= 1
                    if indegree[neighbor] == 0:
                        q.append(neighbor)
                        del indegree[neighbor]
                        
        return take == numCourses