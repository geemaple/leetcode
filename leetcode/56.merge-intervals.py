#  Tag: Array, Sorting, Line Sweep
#  Time: O(NlogN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
#   
#  Example 1:
#  
#  Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
#  Output: [[1,6],[8,10],[15,18]]
#  Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
#  
#  Example 2:
#  
#  Input: intervals = [[1,4],[4,5]]
#  Output: [[1,5]]
#  Explanation: Intervals [1,4] and [4,5] are considered overlapping.
#  
#   
#  Constraints:
#  
#  1 <= intervals.length <= 104
#  intervals[i].length == 2
#  0 <= starti <= endi <= 104
#  
#  

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        intervals.sort()

        res = []
        low, high = intervals[0]

        for i in range(1, n):
            if intervals[i][0] <= high:
                high = max(high, intervals[i][1])
            else:
                res.append((low, high))
                low, high = intervals[i]

        res.append((low, high))
        return res

from collections import defaultdict
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        lines = defaultdict(int)
        for s, e in intervals:
            lines[s] += 1
            lines[e] -= 1

        prefix = 0
        start = 0
        res = []
        for num in sorted(lines.keys()):
            if prefix == 0:
                start = num

            prefix += lines[num]
            if prefix == 0:
                res.append([start, num])

        return res