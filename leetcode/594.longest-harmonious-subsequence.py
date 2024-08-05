#  Tag: Array, Hash Table, Sliding Window, Sorting, Counting
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
#  Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
#  A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.
#   
#  Example 1:
#  
#  Input: nums = [1,3,2,2,5,2,3,7]
#  Output: 5
#  Explanation: The longest harmonious subsequence is [3,2,2,2,3].
#  
#  Example 2:
#  
#  Input: nums = [1,2,3,4]
#  Output: 2
#  
#  Example 3:
#  
#  Input: nums = [1,1,1,1]
#  Output: 0
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 2 * 104
#  -109 <= nums[i] <= 109
#  

from collections import defaultdict
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        counter = defaultdict(int)
        for x in nums:
            counter[x] += 1

        res = 0
        for x in counter:
            if x + 1 in counter:
                res = max(res, counter[x + 1] + counter[x])

        return res
