#  Tag: Array, Hash Table, Sliding Window, Prefix Sum
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
#  A subarray is a contiguous part of the array.
#   
#  Example 1:
#  
#  Input: nums = [1,0,1,0,1], goal = 2
#  Output: 4
#  Explanation: The 4 subarrays are bolded and underlined below:
#  [1,0,1,0,1]
#  [1,0,1,0,1]
#  [1,0,1,0,1]
#  [1,0,1,0,1]
#  
#  Example 2:
#  
#  Input: nums = [0,0,0,0,0], goal = 0
#  Output: 15
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 3 * 104
#  nums[i] is either 0 or 1.
#  0 <= goal <= nums.length
#  
#  

class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        return self.count(nums, goal) - self.count(nums, goal - 1)

    def count(self, nums: List[int], k: int) -> int:
        n = len(nums)
        i = 0
        total = 0
        res = 0
        for j in range(n):
            total += nums[j]
            while i <= j and total > k:
                total -= nums[i]
                i += 1

            res += j - i + 1
        return res
    
from collections import defaultdict
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        n = len(nums)
        counter = defaultdict(int)
        counter[0] = 1
        total = 0
        res = 0
        for i in range(n):
            total += nums[i]
            res += counter[total - goal]
            counter[total] += 1

        return res