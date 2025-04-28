#  Tag: Math, Two Pointers, Binary Search
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
#   
#  Example 1:
#  
#  Input: c = 5
#  Output: true
#  Explanation: 1 * 1 + 2 * 2 = 5
#  
#  Example 2:
#  
#  Input: c = 3
#  Output: false
#  
#   
#  Constraints:
#  
#  0 <= c <= 231 - 1
#  
#  

import math
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        l = 0
        r = math.floor(math.sqrt(c))

        while l <= r:
            if l * l + r * r == c:
                return True

            if l * l + r * r > c:
                r -= 1
            else:
                l += 1
        return False
        