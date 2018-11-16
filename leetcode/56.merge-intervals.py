# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals.sort(key=lambda x: x.start)
        res = []
        
        for i in range(1, len(intervals) + 1):
            if i == len(intervals) or intervals[i].start > intervals[i - 1].end:
                res.append(intervals[i - 1])
            else:
                intervals[i].start = min(intervals[i].start, intervals[i - 1].start)
                intervals[i].end = max(intervals[i].end, intervals[i - 1].end)
                
        return res