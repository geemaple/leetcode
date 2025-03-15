#  Tag: Heap, Greedy, Sweep Line, Sort
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: Leetcode-253
#  Note: -

#  Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...] (si < ei)`, find the minimum number of conference rooms required.
#  
#  **Example1**
#  
#  ```
#  Input: intervals = [(0,30),(5,10),(15,20)]
#  Output: 2
#  Explanation:
#  We need two meeting rooms
#  room1: (0,30)
#  room2: (5,10),(15,20)
#  ```
#  
#  **Example2**
#  
#  ```
#  Input: intervals = [(2,7)]
#  Output: 1
#  Explanation: 
#  Only need one meeting room
#  ```
#  
#  (0,8),(8,10) is not conflict at 8

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

from collections import defaultdict
class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: the minimum number of conference rooms required
    """
    def min_meeting_rooms(self, intervals: List[Interval]) -> int:
        # Write your code here
        n = len(intervals)
        lines = defaultdict(int)
        for interval in intervals:
            lines[interval.start] += 1
            lines[interval.end] -= 1

        prefix = 0
        res = 0
        for t in sorted(lines.keys()):
            prefix += lines[t]
            res = max(res, prefix)

        return res

class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: the minimum number of conference rooms required
    """
    def min_meeting_rooms(self, intervals: List[Interval]) -> int:
        # Write your code here
        meetings = []
        for x in intervals:
            meetings.append((x.start, 1))
            meetings.append((x.end, -1))

        meetings.sort()
        count = 0
        res = 0
        for i in range(len(meetings)):
            count += meetings[i][1]
            res = max(res, count)
        return res 