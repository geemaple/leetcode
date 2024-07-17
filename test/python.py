from typing import List

class Solution:
    def minSteps(self, n: int) -> int:
        return self.helper(n, 1, 0)

    def helper(self, n: int, screen: int, pasteboard: int):
        if screen == n:
            return 0
        
        if screen > n:
            return float('inf')

        result = float('inf')
        if pasteboard > 0:
            result = self.helper(n, screen + pasteboard, pasteboard) + 1

        if pasteboard < screen:
            result = min(result, self.helper(n, screen, screen) + 1)

        return result


s = Solution()
t = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
res = s.minSteps(6)
print(res)