from typing import List
import heapq
class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        res = 0
        for i in range(n):
            res += self.expand(s, i, i)
            res += self.expand(s, i, i + 1)

        return res

    def expand(self, s: str, left: int, right: int) -> int:
        count = 0
        print(left, right)
        while left >= 0 and right < len(s) and s[left] == s[right]:
            count += 1
            left -= 1
            right += 1

        return count        
        


s = Solution()
res = s.countSubstrings("abc")
print(res)