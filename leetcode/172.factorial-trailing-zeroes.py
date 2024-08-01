#  Tag: Math
#  Time: O(logN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer n, return the number of trailing zeroes in n!.
#  Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
#   
#  Example 1:
#  
#  Input: n = 3
#  Output: 0
#  Explanation: 3! = 6, no trailing zero.
#  
#  Example 2:
#  
#  Input: n = 5
#  Output: 1
#  Explanation: 5! = 120, one trailing zero.
#  
#  Example 3:
#  
#  Input: n = 0
#  Output: 0
#  
#   
#  Constraints:
#  
#  0 <= n <= 104
#  
#   
#  Follow up: Could you write a solution that works in logarithmic time complexity?
#  
    
class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0
        for i in range(5, n + 1, 5):
            while i % 5 == 0:
                res += 1
                i = i // 5

        return res
    
class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0
        factor = 5
        while factor <= n:
            res += n // factor
            factor *= 5

        return res

class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0
        while n > 0:
            res += n // 5
            n = n // 5

        return res