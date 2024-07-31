#  Tag: Bit Manipulation
#  Time: O(1)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
#   
#  Example 1:
#  
#  Input: n = 5
#  Output: true
#  Explanation: The binary representation of 5 is: 101
#  
#  Example 2:
#  
#  Input: n = 7
#  Output: false
#  Explanation: The binary representation of 7 is: 111.
#  Example 3:
#  
#  Input: n = 11
#  Output: false
#  Explanation: The binary representation of 11 is: 1011.
#   
#  Constraints:
#  
#  1 <= n <= 231 - 1
#  
#  

class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        n = n ^ (n >> 2)
        return n & (n - 1) == 0

class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        n = n ^ (n >> 1)
        return (n & (n + 1)) == 0

class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        pre = n & 1
        n = n >> 1
        while n > 0:
            cur = n & 1
            if pre == cur:
                return False
            n = n >> 1
            pre = cur
        return True
            