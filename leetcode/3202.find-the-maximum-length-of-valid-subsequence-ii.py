#  Tag: Array, Dynamic Programming
#  Time: O(NK)
#  Space: O(K^2)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/pqTXjIuY5vw

#  You are given an integer array nums and a positive integer k.
#  A subsequence sub of nums with length x is called valid if it satisfies:
#  
#  (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
#  
#  Return the length of the longest valid subsequence of nums.
#   
#  Example 1:
#  
#  Input: nums = [1,2,3,4,5], k = 2
#  Output: 5
#  Explanation:
#  The longest valid subsequence is [1, 2, 3, 4, 5].
#  
#  Example 2:
#  
#  Input: nums = [1,4,2,3,1,4], k = 3
#  Output: 4
#  Explanation:
#  The longest valid subsequence is [1, 4, 1, 4].
#  
#   
#  Constraints:
#  
#  2 <= nums.length <= 103
#  1 <= nums[i] <= 107
#  1 <= k <= 103
#  
#  

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        dp = [[0] * k for i in range(k)]
        res = 0
        for a in nums:
            for b in range(k):
                dp[b][a % k] = dp[a % k][b] + 1
                res = max(res, dp[b][a % k])

        return res
    
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        res = 0
        for add in range(k):
            dp = [0] * k
            for a in nums:
                dp[a % k] = dp[(add - a) % k] + 1

            res = max(res, max(dp))
        return res