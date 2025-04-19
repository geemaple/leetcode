#  Tag: Array, Two Pointers, Binary Search, Sorting
#  Time: O(NlogN)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/fS6nh4pm-wY

#  Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
#  A pair (i, j) is fair if:
#  
#  0 <= i < j < n, and
#  lower <= nums[i] + nums[j] <= upper
#  
#   
#  Example 1:
#  
#  Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
#  Output: 6
#  Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
#  
#  Example 2:
#  
#  Input: nums = [1,7,9,2,5], lower = 11, upper = 11
#  Output: 1
#  Explanation: There is a single fair pair: (2,3).
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  nums.length == n
#  -109 <= nums[i] <= 109
#  -109 <= lower <= upper <= 109
#  
#  

import bisect
class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        return self.count(nums, upper) - self.count(nums, lower - 1)

    def count(self, nums: list, k: int) -> int:
        n = len(nums)
        res = 0
        j = n - 1

        for i in range(n):
            while i < j and nums[i] + nums[j] > k:
                j -= 1

            if i < j:
                res += j - i
            else:
                break
                
        return res

import bisect
class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        return self.count(nums, upper) - self.count(nums, lower - 1)

    def count(self, nums: list, k: int) -> int:
        n = len(nums)
        res = 0
        for i in range(n):
            if nums[i] * 2 > k:
                break

            j = bisect.bisect_right(nums, k - nums[i]) - 1
            res += j - i

        return res
        