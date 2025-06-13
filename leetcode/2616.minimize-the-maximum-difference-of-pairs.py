#  Tag: Array, Binary Search, Greedy
#  Time: O(NlogN)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/P7Kotc-ntP8

#  You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.
#  Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
#  Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.
#   
#  Example 1:
#  
#  Input: nums = [10,1,2,7,1,3], p = 2
#  Output: 1
#  Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
#  The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
#  
#  Example 2:
#  
#  Input: nums = [4,2,1,2], p = 1
#  Output: 0
#  Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  0 <= nums[i] <= 109
#  0 <= p <= (nums.length)/2
#  
#  

import bisect
class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        l = 0
        r = nums[-1] - nums[0]
        while l < r:
            mid = l + (r - l) // 2
            if self.fit(nums, p, mid):
                r = mid
            else:
                l = mid + 1

        return l

    def fit(self, nums: list, p: int, k: int) -> bool:
        n = len(nums)
        i = 0
        count = 0
        while i < n - 1 and count < p:
            if nums[i + 1] - nums[i] <= k:
                count += 1
                i += 2
            else:
                i += 1

        return count == p

from functools import cache
class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        n = len(nums)
        nums.sort()

        @cache
        def dp(i: int, k: int) -> int:
            if k == 0:
                return 0
            if i >= n - 1:
                return float('inf')

            use = max(nums[i + 1] - nums[i], dp(i + 2, k - 1))
            skip = dp(i + 1, k)
            return min(use, skip)

        return dp(0, p)