
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

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        index = n - 1
        pre = -1
        cur = 0

        for i in range(n - 1, -1, -1):
            
            cur = max(0, pre) + gas[i] - cost[i]
            print(pre, cur)
            if cur < 0:
                return -1
            if cur > pre:
                index = i
            pre = cur

        return index




        
            

s = Solution()
ts = datetime.now()

res = s.canCompleteCircuit([5,1,2,3,4], [4,4,1,5,1])

print(datetime.now() - ts)
print(res)
