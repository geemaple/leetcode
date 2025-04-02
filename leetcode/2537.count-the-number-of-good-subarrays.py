#  Tag: Array, Hash Table, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an integer array nums and an integer k, return the number of good subarrays of nums.
#  A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
#  A subarray is a contiguous non-empty sequence of elements within an array.
#   
#  Example 1:
#  
#  Input: nums = [1,1,1,1,1], k = 10
#  Output: 1
#  Explanation: The only good subarray is the array nums itself.
#  
#  Example 2:
#  
#  Input: nums = [3,1,4,3,2,2,4], k = 2
#  Output: 4
#  Explanation: There are 4 different good subarrays:
#  - [3,1,4,3,2,2] that has 2 pairs.
#  - [3,1,4,3,2,2,4] that has 3 pairs.
#  - [1,4,3,2,2,4] that has 2 pairs.
#  - [4,3,2,2,4] that has 2 pairs.
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  1 <= nums[i], k <= 109
#  
#  

from collections import defaultdict
class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        n = len(nums)
        counter = defaultdict(int)
        count = 0
        res = 0
        i = 0
        for j in range(n):
            count += counter[nums[j]]
            counter[nums[j]] += 1
            while count >= k:
                res += n - j
                counter[nums[i]] -= 1
                count -= counter[nums[i]]
                i += 1

        return res

