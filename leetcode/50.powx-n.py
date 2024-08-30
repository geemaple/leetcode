#  Tag: Math, Recursion
#  Time: O(logN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
#   
#  Example 1:
#  
#  Input: x = 2.00000, n = 10
#  Output: 1024.00000
#  
#  Example 2:
#  
#  Input: x = 2.10000, n = 3
#  Output: 9.26100
#  
#  Example 3:
#  
#  Input: x = 2.00000, n = -2
#  Output: 0.25000
#  Explanation: 2-2 = 1/22 = 1/4 = 0.25
#  
#   
#  Constraints:
#  
#  -100.0 < x < 100.0
#  -231 <= n <= 231-1
#  n is an integer.
#  Either x is not zero or n > 0.
#  -104 <= xn <= 104
#  
#  

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n > 0:
            return self.pow(x, n)
        else:
            return self.pow(1/x, -n)

    def pow(self, x: float, n: int) -> float:
        res = 1
        product = x
        times = 1
        count = 0
        while count < n:
            if times + count > n:
                times = 1
                product = x

            res *= product
            count += times
            times = times * 2
            product = product * product

        return res
    
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n > 0:
            return self.pow(x, n)
        else:
            return self.pow(1/x, -n)

    def pow(self, x: float, n: int) -> float:
        res = 1
        product = x
        while n > 0:
            if n % 2 == 1:
                res *= product

            product = product * product

            n = n // 2

        return res

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n > 0:
            return self.pow(x, n)
        else:
            return self.pow(1/x, -n)

    def pow(self, x: float, n: int) -> float:
        if n == 1:
            return x

        half = self.pow(x, n // 2)
        if n % 2 == 0:
            return half * half
        else:
            return half * half * x

from functools import lru_cache
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n > 0:
            return self.pow(x, n)
        else:
            return self.pow(1/x, -n)

    @lru_cache()
    def pow(self, x: float, n: int) -> float:
        if n == 1:
            return x

        return self.pow(x, n // 2) * self.pow(x, n - n//2)