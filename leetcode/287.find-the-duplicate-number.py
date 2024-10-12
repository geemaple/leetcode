#  Tag: Array, Two Pointers, Binary Search, Bit Manipulation
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
#  There is only one repeated number in nums, return this repeated number.
#  You must solve the problem without modifying the array nums and uses only constant extra space.
#   
#  Example 1:
#  
#  Input: nums = [1,3,4,2,2]
#  Output: 2
#  
#  Example 2:
#  
#  Input: nums = [3,1,3,4,2]
#  Output: 3
#  
#  Example 3:
#  
#  Input: nums = [3,3,3,3,3]
#  Output: 3
#   
#  Constraints:
#  
#  1 <= n <= 105
#  nums.length == n + 1
#  1 <= nums[i] <= n
#  All the integers in nums appear only once except for precisely one integer which appears two or more times.
#  
#   
#  Follow up:
#  
#  How can we prove that at least one duplicate number must exist in nums?
#  Can you solve the problem in linear runtime complexity?
#  
#  

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        for x in nums:
            x = abs(x)
            if nums[x - 1] > 0:
                nums[x - 1] = -nums[x - 1]
            else:
                return x

        return -1
        
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = nums[0]
        fast = nums[0]

        slow = nums[slow]
        fast = nums[fast]
        fast = nums[fast]

        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
            fast = nums[fast]

        fast = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]

        return fast
    
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        left = 1
        right = len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2
            if self.count_less_equal(nums, mid) <= mid:
                left = mid + 1
            else:
                right = mid
        return left
                

    def count_less_equal(self, nums:list, target: int) -> int:
        count = 0
        for x in nums:
            if x <= target:
                count += 1
        return count