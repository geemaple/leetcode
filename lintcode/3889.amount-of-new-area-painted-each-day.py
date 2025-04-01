#  Tag: Segment Tree, Array, Line Sweep
#  Time: O(N + L)
#  Space: O(L)
#  Ref: Leetcode-2158
#  Note: -

#  There is a long, thin painting that can be represented by an array of numbers.
#  Given a two-dimensional array of integers $paint$ of length $n$ with subscripts starting at **0**, where $paint[i] = [start_i, end_i]$ means that the region between $start_i$ and $end_i$ needs to be painted on day $i$.
#  
#  Painting the same area multiple times will destroy the painting frame, **so each area can only be painted once.**
#  
#  Returns an integer array `worklog` of length `n`, where `worklog[i]` is the number of **new regions to be drawn on day `i`.**
#  
#  Example 1:
#  
#  ```
#  Input:
#  paint = [[1, 4], [4, 7], [5, 8]]
#  Output:
#  [3, 3, 1]
#  Explanation:
#  The figure below illustrates this:
#  On day 0, the content between 1 and 4 is plotted and the number of new areas is 3
#  On day 1, the content between 4 and 7 is plotted and the number of new areas is 3
#  On day 2, the content between 7 and 8 is plotted. The content between 5 and 7 was already plotted on day 1, so the number of new areas is 1
#  ```
#  
#  ![021901.png](https://media-cn.lintcode.com/new_storage_v2/public/202502/736cd225d9934629ba346086a97b7c3f/021901.png)
#  
#  Example 2:
#  
#  ```
#  Input:
#  paint = [[1, 4], [5, 8], [4, 7]]
#  Output:
#  [3, 3, 1]
#  Explanation:
#  The figure below illustrates this:
#  On day 0, the content between 1 and 4 is plotted and the number of new areas is 3
#  On day 1, the content between 5 and 8 is plotted and the number of new areas is 3
#  On day 2, the content between 4 and 5 is plotted. The content between 5 and 7 was already plotted on day 1, so the number of new areas is 1
#  ```
#  
#  ![021902.png](https://media-cn.lintcode.com/new_storage_v2/public/202502/8fa11f7dbd304ed69ae844f28f2707a1/021902.png)
#  
#  Example 3:
#  
#  ```
#  Input:
#  paint = [[1, 8], [1, 4], [5, 8]]
#  Output:
#  [7, 0, 0]
#  Explanation:
#  The figure below illustrates this:
#  On day 0, content between 1 and 8 is plotted and the number of new areas is 7
#  On day 1, the content between 1 and 4 was already plotted on day 0, so the number of new areas is 0
#  On day 2, the content between 5 and 8 was already plotted on day 0, so the number of new areas is 0
#  ```
#  
#  ![021903.png](https://media-cn.lintcode.com/new_storage_v2/public/202502/98576eb18f9d4f2980df73e8296cf29e/021903.png)
#  
#  - $ 1 \leq paint.length \leq 10^4$
#  - $paint[i].length == 2$
#  - $ 0 \leq start_i < end_i \leq 5 \times 10^4$

from typing import (
    List,
)

class Solution:
    """
    @param paint: Areas plotted on each day
    @return: New areas painted on each day
    """
    def amount_painted(self, paint: List[List[int]]) -> List[int]:
        # write your code here
        n = len(paint)
        line = [0] * 50001
        res = [0 for i in range(n)]
        for i in range(n):
            start, end = paint[i]
            while start < end:
                jump = max(start + 1, line[start])
                res[i] += 1 if line[start] == 0 else 0
                line[start] = max(line[start], end)
                start = jump
        return res

from collections import defaultdict
from sortedcontainers import SortedSet
class Solution:
    """
    @param paint: Areas plotted on each day
    @return: New areas painted on each day
    """
    def amount_painted(self, paint: List[List[int]]) -> List[int]:
        # write your code here
        n = len(paint)
        lines = defaultdict(list)
        length = 0
        for i in range(n):
            lines[paint[i][0]].append((i, 1))
            lines[paint[i][1]].append((i, 0))
            length = max(length, paint[i][1])

        days = SortedSet()
        res = [0 for i in range(n)]
        for i in range(length + 1):
            if i in lines:
                for day, status in lines[i]:
                    if status:
                        days.add(day)
                    elif day in days:
                        days.remove(day)
            if len(days) > 0:
                res[days[0]] += 1
        
        return res

from sortedcontainers import SortedList
class Solution:
    """
    @param paint: Areas plotted on each day
    @return: New areas painted on each day
    """
    def amountPainted(self, paint: List[List[int]]) -> List[int]:
        intervals = SortedList()
        res = []
        
        for l, r in paint:
            i = intervals.bisect_left([l, r])
            if i > 0 and intervals[i - 1][1] >= l:
                i -= 1
                l = intervals[i][1]
            else:
                intervals.add([l, r])
            
            paint_len = r - l
            j = i + 1
            while j < len(intervals) and intervals[j][0] <= r:
                start, end = intervals[j]
                paint_len -= min(r, end) - start
                r = max(r, end)
                intervals.pop(j)
            
            intervals[i][1] = max(intervals[i][1], r)
            res.append(max(0, paint_len))
        
        return res