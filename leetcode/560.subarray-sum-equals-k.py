#  Tag: Array, Hash Table, Prefix Sum
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
#  A subarray is a contiguous non-empty sequence of elements within an array.
#   
#  Example 1:
#  Input: nums = [1,1,1], k = 2
#  Output: 2
#  Example 2:
#  Input: nums = [1,2,3], k = 3
#  Output: 2
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 2 * 104
#  -1000 <= nums[i] <= 1000
#  -107 <= k <= 107
#  
#  

from collections import defaultdict
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefix = 0
        mapping = defaultdict(int)
        mapping[0] = 1

        res = 0
        for n in nums:
            prefix += n
            res += mapping[prefix - k]
            mapping[prefix] += 1

        return res