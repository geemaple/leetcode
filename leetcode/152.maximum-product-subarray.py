#  Tag: Array, Dynamic Programming
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer array nums, find a subarray that has the largest product, and return the product.
#  The test cases are generated so that the answer will fit in a 32-bit integer.
#   
#  Example 1:
#  
#  Input: nums = [2,3,-2,4]
#  Output: 6
#  Explanation: [2,3] has the largest product 6.
#  
#  Example 2:
#  
#  Input: nums = [-2,0,-1]
#  Output: 0
#  Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 2 * 104
#  -10 <= nums[i] <= 10
#  The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
#  
#  

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        min_pre = nums[0]
        max_pre = nums[0]
        res = nums[0]

        for i in range(1, n):
            if nums[i] < 0:
                max_pre, min_pre = min_pre, max_pre

            max_pre = max(nums[i], nums[i] * max_pre)
            min_pre = min(nums[i], nums[i] * min_pre)
   
            res = max(res, max_pre)

        return res

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        min_pre = nums[0]
        max_pre = nums[0]
        res = nums[0]

        for i in range(1, n):
            if nums[i] >= 0:
                max_pre = max(nums[i], nums[i] * max_pre)
                min_pre = min(nums[i], nums[i] * min_pre)
            else:
                max_pre, min_pre = max(nums[i], nums[i] * min_pre), min(nums[i], nums[i] * max_pre)

            res = max(res, max_pre)

        return res

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[float('-inf')] * n for i in range(n)]
        res = float('-inf')
        for i in range(n):
            dp[i][i] = nums[i]
            res = max(res, dp[i][i])

        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i +l - 1
                dp[i][j] = max(dp[i + 1][j] * nums[i], dp[i][j - 1] * nums[j])
                res = max(res, dp[i][j])

        return res