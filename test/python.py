
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)


from collections import defaultdict, deque
class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        for x in invocations:
            graph[x[0]].append(x[1])

        suspicious = set()
        q = deque([k])
        visited = set([k])
        while len(q):
            cur = q.popleft()
            suspicious.add(cur)
            for node in graph[cur]:
                if node not in visited:
                    visited.add(node)
                    q.append(node)

        for x in invocations:
            if x[0] not in suspicious and x[1] in suspicious:
                return [i for i in range(n)]

        return [i for i in range(n) if i not in suspicious]
        

s = Solution()
a = [["a","b","c","e"],["x","x","c","d"],["x","x","b","a"]]
ts = datetime.now()
res = s.remainingMethods(4, 1, [[1,2],[0,1],[3,2]])
print(datetime.now() - ts)
print(res)
