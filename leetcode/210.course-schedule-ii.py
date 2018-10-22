class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        graph = {i : [] for i in range(numCourses)}
        indegree = {i : 0 for i in range(numCourses)}
        
        for item in prerequisites:
            indegree[item[0]] += 1
            graph[item[1]].append(item[0])
            
        q = []
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
                
        res = []
        while (len(q) > 0):
            tmp = q.pop(0)
            res.append(tmp)
            
            for neighbor in graph[tmp]:
                if indegree[neighbor] > 0:
                    indegree[neighbor] -= 1
                    if indegree[neighbor] == 0:
                        q.append(neighbor)
        
        return res if len(res) == numCourses else []