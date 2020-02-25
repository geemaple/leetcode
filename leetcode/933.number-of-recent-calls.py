#
# [969] Number of Recent Calls
#
# https://leetcode.com/problems/number-of-recent-calls/description/
#
# algorithms
# Easy (59.00%)
# Total Accepted:    37.2K
# Total Submissions: 52.8K
# Testcase Example:  '["RecentCounter","ping","ping","ping","ping"]\n[[],[1],[100],[3001],[3002]]'
#
# Write a class RecentCounter to count recent requests.
# 
# It has only one method: ping(int t), where t represents some time in
# milliseconds.
# 
# Return the number of pings that have been made from 3000 milliseconds ago
# until now.
# 
# Any ping with time in [t - 3000, t] will count, including the current ping.
# 
# It is guaranteed that every call to ping uses a strictly larger value of t
# than before.
# 
# 
# 
# Example 1:
# 
# 
# Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs =
# [[],[1],[100],[3001],[3002]]
# Output: [null,1,2,3,3]
# 
# 
# 
# Note:
# 
# 
# Each test case will have at most 10000 calls to ping.
# Each test case will call ping with strictly increasing values of t.
# Each call to ping will have 1 <= t <= 10^9.
# 
# 
# 
# 
# 
#
import collections
class RecentCounter(object):

    def __init__(self):
        self.queue = collections.deque()

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        self.queue.append(t)
        
        while self.queue[0] < t - 3000:
            self.queue.popleft()
            
        return len(self.queue)       


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
