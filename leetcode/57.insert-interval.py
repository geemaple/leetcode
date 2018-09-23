# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        
        res = []
        st = 0

        while(st < len(intervals)):
            if intervals[st].start < newInterval.start:
                res.append(intervals[st])
            else:
                break

            st += 1

        if len(res) != 0 and res[-1].end >= newInterval.start:
            res[-1].end = max(res[-1].end, newInterval.end)
        else:
            res.append(newInterval)

        for i in range(st, len(intervals)):
            if res[-1].end >= intervals[i].start:
                res[-1].end = max(res[-1].end, intervals[i].end)
            else:
                res.append(intervals[i])

        return res