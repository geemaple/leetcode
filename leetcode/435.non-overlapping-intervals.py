#  Tag: Greedy, Array, Dynamic Programming, Sorting
#  Time: O(NlogN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
#   
#  Example 1:
#  
#  Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
#  Output: 1
#  Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
#  
#  Example 2:
#  
#  Input: intervals = [[1,2],[1,2],[1,2]]
#  Output: 2
#  Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
#  
#  Example 3:
#  
#  Input: intervals = [[1,2],[2,3]]
#  Output: 0
#  Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
#  
#   
#  Constraints:
#  
#  1 <= intervals.length <= 105
#  intervals[i].length == 2
#  -5 * 104 <= starti < endi <= 5 * 104
#  
#  

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        n = len(intervals)
        intervals.sort(key=lambda item: item[1])
        
        pre = intervals[0][1]
        count = 0

        for i in range(1, n):
            if intervals[i][0] >= pre:
                pre = intervals[i][1]
            else:
                count += 1

        return count