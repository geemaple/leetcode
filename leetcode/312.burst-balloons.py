#  Tag: Array, Dynamic Programming
#  Time: O(N^3)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
#  If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
#  Return the maximum coins you can collect by bursting the balloons wisely.
#   
#  Example 1:
#  
#  Input: nums = [3,1,5,8]
#  Output: 167
#  Explanation:
#  nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
#  coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
#  Example 2:
#  
#  Input: nums = [1,5]
#  Output: 10
#  
#   
#  Constraints:
#  
#  n == nums.length
#  1 <= n <= 300
#  0 <= nums[i] <= 100
#  
#  

from collections import defaultdict
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        balloons = [1] + nums + [1]
        cache = defaultdict(dict)
        return self.burst(balloons, 1, len(nums), cache)

    def burst(self, nums: List[int], left: int, right:int, cache: dict) -> int:

        if left > right:
            return 0

        if right in cache[left]:
            return cache[left][right]

        res = 0
        for i in range(left, right + 1):
            p = nums[left - 1] * nums[i] * nums[right + 1] + self.burst(nums, left, i - 1, cache) + self.burst(nums, i + 1, right, cache)
            if p > res:
                res = p

        cache[left][right] = res
        return res
    
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)
        dp = [[0] * n for i in range(n)]

        # how to init l = 1 if do it seperately?

        for l in range(1, n - 1):
            for i in range(1, n - l):
                j = i + l - 1
                for k in range(i, j + 1):
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1])

        return dp[1][n - 2]