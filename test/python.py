
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


from typing import (
    List,
)
# from lintcode import (
#     Interval,
# )

"""
Definition of Interval:
"""
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    """
    @param schedule: a list schedule of employees
    @return: Return a list of finite intervals 
    """
    def employee_free_time(self, schedule: List[List[int]]) -> List[Interval]:
        # Write your code here
        works = []
        for s in schedule:
            for i in range(0, len(s), 2):
                works.append((s[i], 'start'))
                works.append((s[i + 1], 'end'))

        works.sort()
        count = 0
        low = None
        res = []
        for i in range(len(works)):
            if works[i][1] == 'start':
                count += 1
                if count == 1 and low is not None:
                    if low < works[i][0]:
                        res.append(Interval(low, works[i][0]))
            else:
                count -= 1
                if count == 0:
                    low = works[i][0]

        return res


s = Solution()
ts = datetime.now()

res = s.employee_free_time([[1,2,5,6],[1,3],[4,10]])

print(datetime.now() - ts)
print(res)
