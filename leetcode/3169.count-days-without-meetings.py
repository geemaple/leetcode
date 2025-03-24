#  Tag: Array, Sorting, Line Sweep
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/iLEeUsBBcZE

#  You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
#  Return the count of days when the employee is available for work but no meetings are scheduled.
#  Note: The meetings may overlap.
#   
#  Example 1:
#  
#  Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
#  Output: 2
#  Explanation:
#  There is no meeting scheduled on the 4th and 8th days.
#  
#  Example 2:
#  
#  Input: days = 5, meetings = [[2,4],[1,3]]
#  Output: 1
#  Explanation:
#  There is no meeting scheduled on the 5th day.
#  
#  Example 3:
#  
#  Input: days = 6, meetings = [[1,6]]
#  Output: 0
#  Explanation:
#  Meetings are scheduled for all working days.
#  
#   
#  Constraints:
#  
#  1 <= days <= 109
#  1 <= meetings.length <= 105
#  meetings[i].length == 2
#  1 <= meetings[i][0] <= meetings[i][1] <= days
#  
#  

from collections import defaultdict
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        lines = defaultdict(int)
        for s,e in meetings:
            lines[s] += 1
            lines[e + 1] -= 1

        prefix = 0
        res = 0
        start = 0
        for day in sorted(lines.keys()):
            if prefix == 0:
                start = day

            prefix += lines[day]
            if prefix == 0:
                res += day - start

        return days - res
    
from collections import defaultdict
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        res = 0
        cur = 1
        meetings.sort()
        for l, r in meetings:
            res += max(0, l - cur)
            cur = max(cur, r + 1)
            if cur > days:
                break

        return res + (days - cur + 1)