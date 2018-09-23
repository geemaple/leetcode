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
        
        intervals.sort(key = lambda inter: inter.start)
        res = []

        if intervals is None or len(intervals) == 0:
            return res

        start = intervals[0].start
        end = intervals[0].end

        for i in range(1, len(intervals)):
            if end >= intervals[i].start:
                end = max(end, intervals[i].end)
            else:
                ans = Interval(start, end)
                res.append(ans)
                start = intervals[i].start
                end = intervals[i].end

        ans = Interval(start, end)
        res.append(ans)

        return res