#  Tag: Array, Sliding Window, Sorting, Bucket Sort, Ordered Set
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given an integer array nums and two integers indexDiff and valueDiff.
#  Find a pair of indices (i, j) such that:
#  
#  i != j,
#  abs(i - j) <= indexDiff.
#  abs(nums[i] - nums[j]) <= valueDiff, and
#  
#  Return true if such pair exists or false otherwise.
#   
#  Example 1:
#  
#  Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
#  Output: true
#  Explanation: We can choose (i, j) = (0, 3).
#  We satisfy the three conditions:
#  i != j --> 0 != 3
#  abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
#  abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
#  
#  Example 2:
#  
#  Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
#  Output: false
#  Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
#  
#   
#  Constraints:
#  
#  2 <= nums.length <= 105
#  -109 <= nums[i] <= 109
#  1 <= indexDiff <= nums.length
#  0 <= valueDiff <= 109
#  
#  

from sortedcontainers import SortedList
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        n = len(nums)
        window = SortedList()
        k = indexDiff
        for i in range(n):
            pos = window.bisect_left(nums[i] - valueDiff)
            if pos < len(window) and abs(window[pos] - nums[i]) <= valueDiff:
                return True

            window.add(nums[i])
            if len(window) > k:
                window.remove(nums[i - k])
        return False
    
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        n = len(nums)
        bucket = {}
        width = valueDiff + 1
        k = indexDiff
        for i in range(n):
            bucket_id = nums[i] // width

            if bucket_id in bucket:
                return True

            if bucket_id - 1 in bucket and abs(nums[i] - bucket[bucket_id - 1]) <= valueDiff:
                return True

            if bucket_id + 1 in bucket and abs(nums[i] - bucket[bucket_id + 1]) <= valueDiff:
                return True

            bucket[bucket_id] = nums[i]
            if i >= k:
                pre_id = nums[i - k] // width
                del bucket[pre_id]

        return False