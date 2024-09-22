#  Tag: Array, Binary Search, Sliding Window, Prefix Sum
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
#   
#  Example 1:
#  
#  Input: target = 7, nums = [2,3,1,2,4,3]
#  Output: 2
#  Explanation: The subarray [4,3] has the minimal length under the problem constraint.
#  
#  Example 2:
#  
#  Input: target = 4, nums = [1,4,4]
#  Output: 1
#  
#  Example 3:
#  
#  Input: target = 11, nums = [1,1,1,1,1,1,1,1]
#  Output: 0
#  
#   
#  Constraints:
#  
#  1 <= target <= 109
#  1 <= nums.length <= 105
#  1 <= nums[i] <= 104
#  
#   
#  Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        i = 0
        total = 0
        res = float('inf')
        for j in range(n):
            total += nums[j]
            while total >= target:
                res = min(res, j - i + 1)
                total -= nums[i]
                i += 1

        return res if res < float('inf') else 0

# follow up
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        
        prefix = [0 for i in range(len(nums) + 1)]
        n = len(prefix)
        for i in range(1, n):
            prefix[i] = nums[i - 1] + prefix[i - 1]

        res = float('inf')
        for i in range(n):
            x = prefix[i]
            j = self.binary_search(prefix,  x + target)
            if j != len(prefix):
                res = min(res, j - i)

        return res if res < float('inf') else 0

    def binary_search(self, array:list, target:int):
        
        left = 0
        right = len(array)
        while left < right:
            mid = (left + right) >> 1
            if array[mid] == target:
                return mid

            if array[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left