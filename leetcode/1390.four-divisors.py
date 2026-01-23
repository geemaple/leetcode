#  Tag: Array, Math
#  Time: O(NsqrtN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.
#   
#  Example 1:
#  
#  Input: nums = [21,4,7]
#  Output: 32
#  Explanation: 
#  21 has 4 divisors: 1, 3, 7, 21
#  4 has 3 divisors: 1, 2, 4
#  7 has 2 divisors: 1, 7
#  The answer is the sum of divisors of 21 only.
#  
#  Example 2:
#  
#  Input: nums = [21,21]
#  Output: 64
#  
#  Example 3:
#  
#  Input: nums = [1,2,3,4,5]
#  Output: 0
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 104
#  1 <= nums[i] <= 105
#  
#  

class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        res = 0
        for x in nums:
            res += self.divisors(x)
        return res


    def divisors(self, x: int) -> int:

        divs = set()
        num = 1
        while num * num <= x:
            if x % num == 0:
                divs.add(num)
                divs.add(x // num)

            if len(divs) > 4:
                return 0

            num += 1

        return sum(divs) if len(divs) == 4 else 0