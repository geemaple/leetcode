#  Tag: Array, String, Greedy, Sorting
#  Time: O(NlogN * K)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
#  Since the result may be very large, so you need to return a string instead of an integer.
#   
#  Example 1:
#  
#  Input: nums = [10,2]
#  Output: "210"
#  
#  Example 2:
#  
#  Input: nums = [3,30,34,5,9]
#  Output: "9534330"
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 100
#  0 <= nums[i] <= 109
#  
#  

class Solution:
    def largestNumber(self, nums):
        nums = [str(x) for x in nums]
        nums.sort(key=lambda x: x * 9, reverse=True)
        result = ''.join(nums)
        return '0' if result[0] == '0' else result
    
from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums):
        def compare(x, y):
            if x + y > y + x:
                return 1
            elif x + y < y + x:
                return -1
            else:
                return 0
        
        nums = map(str, nums)
        nums = sorted(nums, key=cmp_to_key(compare), reverse=True)
        result = ''.join(nums)
        return '0' if result[0] == '0' else result