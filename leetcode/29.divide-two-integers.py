MAX_INT = 2147483647
MIN_INT = -2147483648

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:

        if dividend == MIN_INT and divisor == -1:
            return MAX_INT

        res = 0
        minus = (dividend > 0) ^ (divisor > 0)

        dividend = abs(dividend)
        divisor = abs(divisor)
        
        while dividend >= divisor:
            tmp = divisor
            scale = 1
            while (dividend >= (tmp << 1)):
                tmp = tmp << 1
                scale = scale << 1
                
            res += scale
            dividend -= tmp

        return -res if minus > 0 else res