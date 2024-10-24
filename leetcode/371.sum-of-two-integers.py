#  Tag: Math, Bit Manipulation
#  Time: O(1)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given two integers a and b, return the sum of the two integers without using the operators + and -.
#   
#  Example 1:
#  Input: a = 1, b = 2
#  Output: 3
#  Example 2:
#  Input: a = 2, b = 3
#  Output: 5
#  
#   
#  Constraints:
#  
#  -1000 <= a, b <= 1000
#  
#  

class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xffffffff
        if (b & mask) == 0:
            return (a & mask) if b > 0 else a
        else:
            return self.getSum(a ^ b, (a & b) << 1)
    
class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xffffffff
        while ((b & mask) != 0):
            sum_without_carry = a ^ b
            carry = (a & b) << 1

            a = sum_without_carry
            b = carry

        return (a & mask) if b > 0 else a
        