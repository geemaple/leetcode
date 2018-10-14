class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        start = 0
        end = x

        while (start + 1 < end):
            mid = start + (end - start) / 2

            if (mid * mid > x):
                end = mid
            elif (mid * mid < x):
                start = mid
            else:
                return mid

        return end if (end * end <= x) else start        
