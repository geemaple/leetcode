MAX_INT = 2 ** 31 - 1
MIN_INT = - 2 ** 31
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT

        minus = (dividend > 0) ^ (divisor > 0)

        number = abs(dividend)
        div = abs(divisor)

        ans = 0
        while (number >= div):
            tmp = div
            mul = 1

            while(number >= (tmp << 1)):
                tmp <<= 1
                mul <<= 1

            number -= tmp
            ans += mul

        return -ans if minus else ans
