#  Tag: Array, Two Pointers, Binary Search, Prefix Sum
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  A split of an integer array is good if:
#  
#  The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
#  The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
#  
#  Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
#   
#  Example 1:
#  
#  Input: nums = [1,1,1]
#  Output: 1
#  Explanation: The only good way to split nums is [1] [1] [1].
#  Example 2:
#  
#  Input: nums = [1,2,2,2,5,0]
#  Output: 3
#  Explanation: There are three good ways of splitting nums:
#  [1] [2] [2,2,5,0]
#  [1] [2,2] [2,5,0]
#  [1,2] [2,2] [5,0]
#  
#  Example 3:
#  
#  Input: nums = [3,2,1]
#  Output: 0
#  Explanation: There is no good way to split nums.
#   
#  Constraints:
#  
#  3 <= nums.length <= 105
#  0 <= nums[i] <= 104
#  
#  

class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        n = len(nums)
        mod = 10 ** 9 + 7
        prefix = [0 for i in range(n + 1)]
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        res = 0
        l = 0
        r = 0
        for i in range(0, n - 2):
            l = max(l, i + 1)
            while l < n - 1 and prefix[l + 1] - prefix[i + 1] < prefix[i + 1]:
                l += 1

            r = max(l, r)
            while r < n - 1 and prefix[r + 1] - prefix[i + 1] <= prefix[n] - prefix[r + 1]:
                r += 1

            res = (res + r - l) % mod
        return res