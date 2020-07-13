class Solution:
    def reverse(self, x: int) -> int:
 
        max_integer = 2 ** 31 - 1
        min_integer = - 2 ** 31

        sign = 1 if x >= 0 else -1
        x = abs(x)
        reverse = 0
        
        while x > 0:
            reverse = reverse * 10 + x % 10
            x = x // 10
            
        res = sign * reverse
        return res if res >= min_integer and res <= max_integer else 0