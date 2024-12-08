
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
from collections import Counter
from collections import defaultdict
class Solution:
    def maxRectangleArea(self, points: List[List[int]]) -> int:
        n = len(points)
        
        table = set([(p[0], p[1]) for p in points])

        res = -1
        for i in range(n):
            for j in range(i, n):
                x1, y1 = points[i]
                x2, y2 = points[j]
                
                if (x1 != x2 and y1 != y2 and (x2, y1) in table and (x1, y2) in table):
                    is_valid = True
                    for k in range(n):
                        if  k == i or k == j or points[k] == [x2, y1] or points[k] == [x1, y2]:
                            continue

                        if min(x1, x2) <= points[k][0] <= max(x1, x2) and min(y1, y2) <= points[k][1] <= max(y1, y2):
                            is_valid = False
                            break
                            
                    if is_valid:  
                        res = max(res, abs(x2 - x1) * abs(y2 - y1))
                    
        return res


s = Solution()
ts = datetime.now()

res = s.maxRectangleArea([[1,1],[1,3],[3,1],[3,3],[1,2],[3,2]])

print(datetime.now() - ts)
print(res)
