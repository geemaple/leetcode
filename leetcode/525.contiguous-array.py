#  Tag: Array, Hash Table, Prefix Sum
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
#   
#  Example 1:
#  
#  Input: nums = [0,1]
#  Output: 2
#  Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
#  
#  Example 2:
#  
#  Input: nums = [0,1,0]
#  Output: 2
#  Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  nums[i] is either 0 or 1.
#  
#  

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        preifx_sum = 0
        res = 0
        table = {0: -1}

        for i in range(n):
            if nums[i] == 0:
                preifx_sum -= 1
            else:
                preifx_sum += 1

            if preifx_sum in table:
                res = max(res, i - table[preifx_sum])
            else:
                table[preifx_sum] = i

        return res