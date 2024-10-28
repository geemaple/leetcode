#  Tag: Sort
#  Time: O(NlogN)
#  Space: O(1)
#  Ref: Leetcode-252
#  Note: -

#  Given an array of meeting time intervals consisting of start and end times `[(s1,e1),(s2,e2),...] (si < ei)`, determine if a person could attend all meetings.
#  
#  **Example1**
#  
#  ```
#  Input: intervals = [(0,30),(5,10),(15,20)]
#  Output: false
#  Explanation: 
#  (0,30), (5,10) and (0,30),(15,20) will conflict
#  ```
#  
#  **Example2**
#  
#  ```
#  Input: intervals = [(5,8),(9,15)]
#  Output: true
#  Explanation: 
#  Two times will not conflict 
#  ```
#  
#  - $0 \leq intervals .length \leq 10^4$
#  - $intervals[i].length == 2$
#  - $0 \leq start_i < end_i \leq 10^6$
#  - `[(0,8), (8,10)]` is not conflict at **8**

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
    @param intervals: an array of meeting time intervals
    @return: if a person could attend all meetings
    """
    def can_attend_meetings(self, intervals: List[Interval]) -> bool:
        # Write your code here
        n = len(intervals)
        intervals.sort(key=lambda x: (x.start, x.end))
        for i in range(1, n):
            if intervals[i].start < intervals[i - 1].end:
                return False

        return True



