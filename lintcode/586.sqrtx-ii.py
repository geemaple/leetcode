class Solution:
    """
    @param x: a double
    @return: the square root of x
    """
    def sqrt(self, x):
        # write your code here
        start = 1
        end = x
        
        if x < 1:
            start = x
            end = 1
            
        while (end - start > 1e-10):
            mid = start + (end - start) / 2
            
            if (mid * mid < x):
                start = mid
            elif (mid * mid > x):
                end = mid
            else:
                break
            
        return start