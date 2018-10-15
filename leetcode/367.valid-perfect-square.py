class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        start = 0
        end = num
        
        while start + 1 < end:
            mid = start + (end - start) // 2
            
            if (mid * mid < num):
                start = mid
            elif (mid * mid > num):
                end = mid
            else:
                return True
            
        return start * start == num or end * end == num