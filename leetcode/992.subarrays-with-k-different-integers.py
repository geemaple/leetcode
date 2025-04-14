#  Tag: Array, Hash Table, Sliding Window, Counting
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer array nums and an integer k, return the number of good subarrays of nums.
#  A good array is an array where the number of different integers in that array is exactly k.
#  
#  For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
#  
#  A subarray is a contiguous part of an array.
#   
#  Example 1:
#  
#  Input: nums = [1,2,1,2,3], k = 2
#  Output: 7
#  Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
#  
#  Example 2:
#  
#  Input: nums = [1,2,1,3,4], k = 3
#  Output: 3
#  Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 2 * 104
#  1 <= nums[i], k <= nums.length
#  
#  

from collections import defaultdict
class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        return self.count(nums, k) - self.count(nums, k + 1)

    def count(self, nums: list, k: int) -> int:
        n = len(nums)
        i = 0
        counter = defaultdict(int)
        res = 0
        for j in range(n):
            counter[nums[j]] += 1
            while len(counter) >= k:
                res += n - j
                counter[nums[i]] -= 1
                if counter[nums[i]] == 0:
                    del counter[nums[i]]
                i += 1

        return res