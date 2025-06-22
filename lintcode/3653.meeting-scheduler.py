#  Tag: Same Direction Two Pointers, Two Pointers, Sort, Line Sweep
#  Time: O(N + M)
#  Space: O(1)
#  Ref: Leetcode-1229
#  Note: -

#  Given the availability schedules `slots1` and `slots2` of two people, and the expected `duration` of the meeting, you are asked to schedule **the earliest and appropriate** meeting time in the interval for them.
#  
#  The format of an **availability schedules** is an ***Interval*** consisting of a `start` time and an `end` time, i.e., `(start, end)`, which means that it starts at `start` and ends at `end`.
#  
#  
#  If the required meeting time is not met, return to the interval `(-1, -1)`.
#  
#  **Example 1**
#  
#  Input
#  ```
#  slots1 = [(10,50),(60,120),(140,210)]
#  slots2 = [(0,15),(60,70)]
#  duration = 8
#  ```
#  
#  Output
#  ```
#  (60,68)
#  ```
#  
#  **Example 2**
#  
#  Input
#  ```
#  slots1 = [(10,50),(60,120),(140,210)]
#  slots2 = [(0,15),(60,70)]
#  duration = 12
#  ```
#  
#  Output
#  ```
#  (-1,-1)
#  ```
#  
#  $1 <= slots1.length, slots2.length <= 10^4$
#  
#  $slots1[i].length, slots2[i].length == 2$
#  
#  $slots1[i].start < slots1[i].end$
#  
#  $slots2[i].start < slots2[i].end$
#  
#  $0 <= slots1[i][j], slots2[i][j] <= 10^9$
#  
#  $1 <= duration <= 10^6$

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
    @param slots1: The availability schedule of one.
    @param slots2: The availability schedule of one.
    @param duration: The expected duration of the meeting.
    @return: The earliest and appropriate meeting time in the interval for them.
    """
    def earliest_appropriate_duration(self, slots1: List[Interval], slots2: List[Interval], duration: int) -> Interval:
        # --- write your code here ---
        n = len(slots1)
        m = len(slots2)
        # slots1.sort(key=lambda x: (x.start, x.end))
        # slots2.sort(key=lambda x: (x.start, x.end))

        i = 0
        j = 0

        while i < n and j < m:
            print(i, j)
            start = max(slots1[i].start, slots2[j].start)
            end = min(slots1[i].end, slots2[j].end)
            if end - start >= duration:
                return Interval(start, start + duration)
       
            if slots1[i].end < slots2[j].end:
                i += 1
            else:
                j += 1


        return Interval(-1, -1)
    
from collections import defaultdict
class Solution:
    """
    @param slots1: The availability schedule of one.
    @param slots2: The availability schedule of one.
    @param duration: The expected duration of the meeting.
    @return: The earliest and appropriate meeting time in the interval for them.
    """
    def earliest_appropriate_duration(self, slots1: List[Interval], slots2: List[Interval], duration: int) -> Interval:
        # --- write your code here ---
        lines = defaultdict(int)
        for interval in slots1:
            lines[interval.start] += 1
            lines[interval.end] -= 1

        for interval in slots2:
            lines[interval.start] += 1
            lines[interval.end] -= 1

        prefix = 0
        begin = False
        start = 0
        for t in sorted(lines.keys()):
            prefix += lines[t]

            if prefix == 2:
                begin = True
                start = t

            if prefix < 2 and begin:
                if t - start >= duration:
                    return Interval(start, start + duration)
                begin = False

        return Interval(-1, -1)
