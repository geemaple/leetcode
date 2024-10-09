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
        n = len(meetings)
        for i in range(n):
            count += meetings[i][1]
            if i == n - 1 or meetings[i][0] != meetings[i + 1][0]: # second -1 comes first after sorting, this is not necessary
                res = max(res, count)
        return res 