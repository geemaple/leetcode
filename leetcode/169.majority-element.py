#  Tag: Array, Hash Table, Divide and Conquer, Sorting, Counting
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an array nums of size n, return the majority element.
#  The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
#   
#  Example 1:
#  Input: nums = [3,2,3]
#  Output: 3
#  Example 2:
#  Input: nums = [2,2,1,1,1,2,2]
#  Output: 2
#  
#   
#  Constraints:
#  
#  n == nums.length
#  1 <= n <= 5 * 104
#  -109 <= nums[i] <= 109
#  
#   
#  Follow-up: Could you solve the problem in linear time and in O(1) space?

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        res = 0
        for x in nums:
            if count == 0:
                res = x

            if x == res:
                count += 1
            else:
                count -= 1
                
        return res
    
from collections import Counter
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counter = Counter(nums)
        for key in counter:
            if counter[key] > len(nums)//2:
                return key
            
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        mid = len(nums)//2
        return nums[mid]
    
class Solution:
    def majorityElement(self, nums):
        return self.majorityElementRec(nums, 0, len(nums) - 1)

    def helper(self, nums, left, right):
        if left == right:
            return nums[left]

        # divide
        mid = (left + right) // 2
        left_majority = self.helper(nums, left, mid)
        right_majority = self.helper(nums, mid + 1, right)

        # conquer
        if left_majority == right_majority:
            return left_majority

        left_count = nums[left:right + 1].count(left_majority)
        right_count = nums[left:right + 1].count(right_majority)

        return left_majority if left_count > right_count else right_majority
