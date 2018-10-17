# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        times = []
        for i in range(len(intervals)):
            times.append([intervals[i].start, 1])
            times.append([intervals[i].end, -1])
            
        times.sort()
        res = 0
        count = 0
        
        for i in range(len(times)):
            count += times[i][1]
            res = max(res, count)
            
        return res
            