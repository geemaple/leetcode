#  Tag: Bit Manipulation
#  Time: O(1)
#  Space: O(1)
#  Ref: -
#  Note: -

#  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
#  Given two integers x and y, return the Hamming distance between them.
#   
#  Example 1:
#  
#  Input: x = 1, y = 4
#  Output: 2
#  Explanation:
#  1   (0 0 0 1)
#  4   (0 1 0 0)
#         ↑   ↑
#  The above arrows point to positions where the corresponding bits are different.
#  
#  Example 2:
#  
#  Input: x = 3, y = 1
#  Output: 1
#  
#   
#  Constraints:
#  
#  0 <= x, y <= 231 - 1
#  
#  

class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        n = x ^ y
        res = 0
        while n > 0:
            n = n & (n - 1)
            res += 1
        return res
    
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        diff = x ^ y
        res = 0
        while diff > 0:
            res += diff & 1
            diff = diff >> 1
        return res