#  Tag: Array, Dynamic Programming, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a binary array nums, you should delete one element from it.
#  Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
#   
#  Example 1:
#  
#  Input: nums = [1,1,0,1]
#  Output: 3
#  Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
#  
#  Example 2:
#  
#  Input: nums = [0,1,1,1,0,1,1,0,1]
#  Output: 5
#  Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
#  
#  Example 3:
#  
#  Input: nums = [1,1,1]
#  Output: 2
#  Explanation: You must delete one element.
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  nums[i] is either 0 or 1.
#  
#  

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        counter = [0, 0]
        i = 0
        res = 0
        for j in range(n):
            while nums[j] == 0 and counter[0] == 1:
                counter[nums[i]] -= 1
                i += 1

            counter[nums[j]] += 1
            res = max(res, j - i + 1)

        return res - 1

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        zero = 0
        i = 0
        res = 0
        for j in range(n):
            while nums[j] == 0 and zero == 1:
                zero -= nums[i] == 0
                i += 1

            zero += nums[j] == 0
            res = max(res, j - i + 1)

        return res - 1