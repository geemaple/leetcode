
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math

import heapq

from typing import (
    List,
)


import heapq
from collections import defaultdict
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        heap = []
        counter = defaultdict(int)
        for x in tasks:
            counter[x] += 1

        for task, count in counter.items():
            heapq.heappush(heap, (-count, task))

        res = 0
        while len(heap) > 0:
            visited = {}
            for i in range(n + 1):
                if len(heap) == 0:
                    break

                top = heapq.heappop(heap)
                count, task = -top[0], top[1]
                
                visited[task] = count

            for task, count in visited.items():
                if count > 1:
                    heapq.heappush(heap, (-(count - 1), task))

            res += len(visited) if len(heap) == 0 else n + 1

        return res


s = Solution()
ts = datetime.now()

res = s.leastInterval(["A","B","A"], 2)

print(datetime.now() - ts)
print(res)
