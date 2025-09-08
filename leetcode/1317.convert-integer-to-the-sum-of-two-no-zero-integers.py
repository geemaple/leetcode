#  Tag: Math
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/Fen3cNUNyyk

#  No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
#  Given an integer n, return a list of two integers [a, b] where:
#  
#  a and b are No-Zero integers.
#  a + b = n
#  
#  The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.
#   
#  Example 1:
#  
#  Input: n = 2
#  Output: [1,1]
#  Explanation: Let a = 1 and b = 1.
#  Both a and b are no-zero integers, and a + b = 2 = n.
#  
#  Example 2:
#  
#  Input: n = 11
#  Output: [2,9]
#  Explanation: Let a = 2 and b = 9.
#  Both a and b are no-zero integers, and a + b = 11 = n.
#  Note that there are other valid answers as [8, 3] that can be accepted.
#  
#   
#  Constraints:
#  
#  2 <= n <= 104
#  
#  

class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1, n):
            if self.check(i) and self.check(n - i):
                return [i, n - i]

    def check(self, num: int) -> bool:
        while num > 0:
            if num % 10 == 0:
                return False

            num = num // 10

        return True
    
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        a = 0
        b = 0
        base = 1
        while n > 0:
            d = n % 10
            if d == 0:
                a += 5 * base
                b += 5 * base
                n -= 10
            elif d == 1 and n >= 10:
                a += 6 * base
                b += 5 * base
                n -= 10
            else:
                a += (d - d // 2) * base
                b += (d // 2) * base

            n = n // 10
            base = base * 10
        return [a, b]