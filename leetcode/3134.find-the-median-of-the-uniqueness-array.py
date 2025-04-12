#  Tag: Array, Hash Table, Binary Search, Sliding Window
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given an integer array nums. The uniqueness array of nums is the sorted array that contains the number of distinct elements of all the subarrays of nums. In other words, it is a sorted array consisting of distinct(nums[i..j]), for all 0 <= i <= j < nums.length.
#  Here, distinct(nums[i..j]) denotes the number of distinct elements in the subarray that starts at index i and ends at index j.
#  Return the median of the uniqueness array of nums.
#  Note that the median of an array is defined as the middle element of the array when it is sorted in non-decreasing order. If there are two choices for a median, the smaller of the two values is taken.
#   
#  Example 1:
#  
#  Input: nums = [1,2,3]
#  Output: 1
#  Explanation:
#  The uniqueness array of nums is [distinct(nums[0..0]), distinct(nums[1..1]), distinct(nums[2..2]), distinct(nums[0..1]), distinct(nums[1..2]), distinct(nums[0..2])] which is equal to [1, 1, 1, 2, 2, 3]. The uniqueness array has a median of 1. Therefore, the answer is 1.
#  
#  Example 2:
#  
#  Input: nums = [3,4,3,4,5]
#  Output: 2
#  Explanation:
#  The uniqueness array of nums is [1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3]. The uniqueness array has a median of 2. Therefore, the answer is 2.
#  
#  Example 3:
#  
#  Input: nums = [4,3,5,4]
#  Output: 2
#  Explanation:
#  The uniqueness array of nums is [1, 1, 1, 1, 2, 2, 2, 3, 3, 3]. The uniqueness array has a median of 2. Therefore, the answer is 2.
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  1 <= nums[i] <= 105
#  
#  

from collections import defaultdict
class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:
        n = len(nums)
        l = 1
        r = len(set(nums))
        total = n * (n + 1) // 2
        while l < r:
            mid = l + (r - l) // 2
            if self.count(nums, mid) * 2 >= total:
                r = mid
            else:
                l = mid + 1
        return l

    def count(self, nums: list,  k: int) -> int:
        n = len(nums)
        res = 0
        i = 0
        counter = defaultdict(int)
        for j in range(n):
            counter[nums[j]] += 1
            while len(counter) > k:
                counter[nums[i]] -= 1
                if counter[nums[i]] == 0:
                    del counter[nums[i]]
                i += 1

            res += j - i + 1
        return res