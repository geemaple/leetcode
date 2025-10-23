#  Tag: Array, Binary Search, Sliding Window, Sorting, Prefix Sum
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/TXY2dRFzlQk

#  You are given an integer array nums and two integers k and numOperations.
#  You must perform an operation numOperations times on nums, where in each operation you:
#  
#  Select an index i that was not selected in any previous operations.
#  Add an integer in the range [-k, k] to nums[i].
#  
#  Return the maximum possible frequency of any element in nums after performing the operations.
#   
#  Example 1:
#  
#  Input: nums = [1,4,5], k = 1, numOperations = 2
#  Output: 2
#  Explanation:
#  We can achieve a maximum frequency of two by:
#  
#  Adding 0 to nums[1]. nums becomes [1, 4, 5].
#  Adding -1 to nums[2]. nums becomes [1, 4, 4].
#  
#  
#  Example 2:
#  
#  Input: nums = [5,11,20,20], k = 5, numOperations = 1
#  Output: 2
#  Explanation:
#  We can achieve a maximum frequency of two by:
#  
#  Adding 0 to nums[1].
#  
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  1 <= nums[i] <= 105
#  0 <= k <= 105
#  0 <= numOperations <= nums.length
#  
#  

from collections import defaultdict
class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()
        n = len(nums)
        counter = defaultdict(int)
        res = 0
        i = 0
        j = 0
        for x in nums:
            while j < n and nums[j] <= x + k:
                counter[nums[j]] += 1
                j += 1

            while i < n and nums[i] < x - k:
                counter[nums[i]] -= 1
                i += 1

            cur = min(j - i, counter[x] + numOperations)
            res = max(res, cur)

        i = 0
        for j in range(n):
            while nums[i] + k + k < nums[j]:
                i += 1

            cur = min(j - i + 1, numOperations)
            res = max(res, cur)
        return res