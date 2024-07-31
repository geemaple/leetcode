#  Tag: Array, Hash Table
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
#   
#  Example 1:
#  Input: nums = [4,3,2,7,8,2,3,1]
#  Output: [5,6]
#  Example 2:
#  Input: nums = [1,1]
#  Output: [2]
#  
#   
#  Constraints:
#  
#  n == nums.length
#  1 <= n <= 105
#  1 <= nums[i] <= n
#  
#   
#  Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
#  

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n):
            pos = abs(nums[i]) - 1
            if nums[pos] > 0:
                nums[pos] = -nums[pos]

        res = []
        for i in range(1, n + 1):
            if nums[i - 1] > 0:
                res.append(i)

        return res

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        cache = set(nums)
        return [x for x in range(1, len(nums) + 1) if x not in cache]