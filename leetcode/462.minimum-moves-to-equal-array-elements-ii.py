#  Tag: Array, Math, Sorting
#  Time: O(NlogN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
#  In one move, you can increment or decrement an element of the array by 1.
#  Test cases are designed so that the answer will fit in a 32-bit integer.
#   
#  Example 1:
#  
#  Input: nums = [1,2,3]
#  Output: 2
#  Explanation:
#  Only two moves are needed (remember each move increments or decrements one element):
#  [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
#  
#  Example 2:
#  
#  Input: nums = [1,10,2,9]
#  Output: 16
#  
#   
#  Constraints:
#  
#  n == nums.length
#  1 <= nums.length <= 105
#  -109 <= nums[i] <= 109
#  
#  

class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        median = nums[n // 2]
        res = 0
        for x in nums:
            res += abs(x - median)
        return res

import random
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        n = len(nums)
        median = self.quick_select(nums, 0, n - 1, n // 2)
        res = 0
        for x in nums:
            res += abs(x - median)
        return res

    def quick_select(self, nums: list, left:int, right: int, nth: int) -> int:
        select = random.randint(left, right)
        value = nums[select]
        nums[left], nums[select] = nums[select], nums[left]
        l = left + 1
        r = right

        while l <= r:
            while l <= r and nums[l] < value:
                l += 1
            
            while l <= r and nums[r] >= value:
                r -= 1

            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]

        nums[r], nums[left] = nums[left], nums[r]

        if r < nth:
            return self.quick_select(nums, r + 1, right, nth)
        elif r > nth:
            return self.quick_select(nums, left, r - 1, nth)
        else:
            return nums[r]
 