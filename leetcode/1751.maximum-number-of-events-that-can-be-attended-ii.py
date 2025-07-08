#  Tag: Array, Binary Search, Dynamic Programming, Sorting
#  Time: O(NlogN + NK)
#  Space: O(NK)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/FPO3W8l2Jjg

#  You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
#  You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
#  Return the maximum sum of values that you can receive by attending events.
#   
#  Example 1:
#  
#  
#  Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
#  Output: 7
#  Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
#  Example 2:
#  
#  
#  Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
#  Output: 10
#  Explanation: Choose event 2 for a total value of 10.
#  Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
#  Example 3:
#  
#  
#  Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
#  Output: 9
#  Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
#   
#  Constraints:
#  
#  1 <= k <= events.length
#  1 <= k * events.length <= 106
#  1 <= startDayi <= endDayi <= 109
#  1 <= valuei <= 106
#  
#  

import bisect
from functools import cache
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        n = len(events)
        events.sort()
        starts = [s for s, e, v in events]

        @cache
        def dfs(i: int, k: int) -> int:
            if k == 0 or i >= n:
                return 0

            end = events[i][1]
            val = events[i][2]
            j = bisect.bisect_right(starts, end)

            return max(val + dfs(j, k - 1), dfs(i + 1, k))

        return dfs(0, k)

import bisect
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort(key=lambda x: x[1])
        n = len(events)

        ends = [event[1] for event in events]

        dp = [[0] * (k + 1) for _ in range(n + 1)]

        for i in range(1, n + 1):
            start, end, value = events[i - 1]
            pre = bisect_right(ends, start - 1) # 1-based index for the dp

            for j in range(1, k + 1):
                dp[i][j] = max(dp[pre][j - 1] + value, dp[i - 1][j])

        return dp[n][k]

import bisect
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        n = len(events)
        events.sort(key = lambda x: x[1])
        
        dp = [[0, 0]]
        for _ in range(k):
            tmp = [[0, 0]]
            for s, e, v in events:
                i = bisect.bisect_right(dp, [s]) - 1
                if dp[i][1] + v > tmp[-1][1]:
                    tmp.append([e, dp[i][1] + v])

            dp = tmp

        return dp[-1][-1]