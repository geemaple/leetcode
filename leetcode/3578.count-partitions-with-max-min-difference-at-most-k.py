#  Tag: Array, Dynamic Programming, Queue, Sliding Window, Prefix Sum, Monotonic Queue
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.
#  Return the total number of ways to partition nums under this condition.
#  Since the answer may be too large, return it modulo 109 + 7.
#   
#  Example 1:
#  
#  Input: nums = [9,4,1,3,7], k = 4
#  Output: 6
#  Explanation:
#  There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:
#  
#  [[9], [4], [1], [3], [7]]
#  [[9], [4], [1], [3, 7]]
#  [[9], [4], [1, 3], [7]]
#  [[9], [4, 1], [3], [7]]
#  [[9], [4, 1], [3, 7]]
#  [[9], [4, 1, 3], [7]]
#  
#  
#  Example 2:
#  
#  Input: nums = [3,3,4], k = 0
#  Output: 2
#  Explanation:
#  There are 2 valid partitions that satisfy the given conditions:
#  
#  [[3], [3], [4]]
#  [[3, 3], [4]]
#  
#  
#   
#  Constraints:
#  
#  2 <= nums.length <= 5 * 104
#  1 <= nums[i] <= 109
#  0 <= k <= 109
#  
#  

from collections import deque
class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mod = 10**9 + 7
        dp = [1] + [0] * n
        prefix = 1
        minq = deque()
        maxq = deque()
        i = 0
        for j in range(n):
            while maxq and nums[j] > nums[maxq[-1]]:
                maxq.pop()
            maxq.append(j)
      
            while minq and nums[j] < nums[minq[-1]]:
                minq.pop()
            minq.append(j)

            while nums[maxq[0]] - nums[minq[0]] > k:
                prefix = (prefix - dp[i]) % mod
                i += 1
                if minq[0] < i:
                    minq.popleft()
                if maxq[0] < i:
                    maxq.popleft()
            dp[j + 1] = prefix
            prefix = (prefix + dp[j + 1]) % mod

        return dp[n]