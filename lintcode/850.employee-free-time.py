#  Tag: Sweep Line
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: Leetcode-759
#  Note: -

#  We are given a list `schedule` of employees, which represents the working time for each employee.
#  
#  Each employee has a list of non-overlapping `Intervals`, and these intervals are in sorted order.
#  
#  Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.
#  
#  The `Intervals` is an 1d-array.
#  Each two numbers shows an interval.
#  For example, `[1,2,8,10]` represents that the employee works in `[1,2]` and `[8,10]`.
#  
#  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
#  
#  **Example 1:**
#  ```
#  Input：schedule = [[1,2,5,6],[1,3],[4,10]]
#  Output：[(3,4)]
#  Explanation:
#  There are a total of three employees, and all common
#  free time intervals would be [-inf, 1], [3, 4], [10, inf].
#  We discard any intervals that contain inf as they aren't finite.
#  ```
#  
#  
#  **Example 2:**
#  ```
#  Input：schedule = [[1,3,6,7],[2,4],[2,5,9,12]]
#  Output：[(5,6),(7,9)]
#  Explanation：
#  There are a total of three employees, and all common
#  free time intervals would be [-inf, 1], [5, 6], [7, 9],[12,inf].
#  We discard any intervals that contain inf as they aren't finite.
#  ```
#  
#  1.schedule and schedule[i] are lists with lengths in range [1, 100].
#  2.0 <= schedule[i].start < schedule[i].end <= 10^8.

from typing import (
    List,
)
from lintcode import (
    Interval,
)

"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

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
                works.append([s[i], s[i + 1]])

        works.sort()
        merge = []
        for inter in works:
            if len(merge) == 0 or merge[-1][1] < inter[0]:
                merge.append(inter)
            else:
                merge[-1][1] = max(merge[-1][1], inter[1])
  
        res = []
        for i in range(1, len(merge)):
            res.append(Interval(merge[i - 1][1], merge[i][0]))

        return res