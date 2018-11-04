import collections
class Solution(object):
    def numBusesToDestination(self, routes, S, T):
        """
        :type routes: List[List[int]]
        :type S: int
        :type T: int
        :rtype: int
        """
        
        if S == T:
            return 0
        
        routes = map(set, routes)
        graph = collections.defaultdict(list)
        
        start = []
        end = set()
        
        for i in range(len(routes)):
            if S in routes[i]:
                start.append(i)
                
            if T in routes[i]:
                end.add(i)
            
            for j in range(i + 1, len(routes)):
                if len(routes[i] & routes[j]) > 0:
                    graph[i].append(j)
                    graph[j].append(i)
                    
                    
        if len(start) == 0 or len(end) == 0:
            return -1
        
        q = collections.deque()
        q.extend(start)
        visited = set(start)
        nums = 0

        while q:
            nums += 1
            size = len(q)
            
            for i in range(size):
                bus = q.popleft()
                if bus in end:
                    return nums
                
                for next_bus in graph[bus]:
                    if next_bus not in visited:
                        visited.add(next_bus)
                        q.append(next_bus)
                
        return -1