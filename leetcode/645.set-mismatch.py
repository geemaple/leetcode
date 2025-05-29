#  Tag: Array, Hash Table, Bit Manipulation, Sorting, Index Sort
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
#  You are given an integer array nums representing the data status of this set after the error.
#  Find the number that occurs twice and the number that is missing and return them in the form of an array.
#   
#  Example 1:
#  Input: nums = [1,2,2,4]
#  Output: [2,3]
#  Example 2:
#  Input: nums = [1,1]
#  Output: [1,2]
#  
#   
#  Constraints:
#  
#  2 <= nums.length <= 104
#  1 <= nums[i] <= 104
#  
#  

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums = [0] + nums
        n = len(nums)
        i = 1
        while i < n:
            j = nums[i]
            if j > 0 and j < n and nums[i] != nums[j]:
                nums[i], nums[j] = nums[j], nums[i]
            else:
                i += 1

        res = []
        for i in range(1, n):
            if nums[i] != i:
                res.append(nums[i])
                res.append(i)
            
        return res