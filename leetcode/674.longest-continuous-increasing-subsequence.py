#  Tag: Array
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.
#  A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].
#   
#  Example 1:
#  
#  Input: nums = [1,3,5,4,7]
#  Output: 3
#  Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
#  Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
#  4.
#  
#  Example 2:
#  
#  Input: nums = [2,2,2,2,2]
#  Output: 1
#  Explanation: The longest continuous increasing subsequence is [2] with length 1. Note that it must be strictly
#  increasing.
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 104
#  -109 <= nums[i] <= 109
#  
#  

class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1 for i in range(n)]

        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                dp[i] = dp[i - 1] + 1

        return max(dp)
    
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        n = len(nums)
        cur = 1
        res = 1

        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                cur += 1
            else:
                cur = 1
            res = max(res, cur)

        return res

class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        res = 1
        i = 0
        for j in range(1, len(nums)):
            if nums[j] <= nums[j - 1]:
                i = j
            
            res = max(res, j - i + 1)
                
        return res
