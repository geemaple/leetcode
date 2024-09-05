
from typing import List
from collections import defaultdict
import heapq

from collections import defaultdict
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        self.helper(0, 0, n, "", res)
        return res

    def helper(self, left:int, right: int, n:int, ans: str, res:list):
        if left + right == n:
            res.append(ans)
            print(ans)
            return

        if left < n // 2:
            self.helper(left + 1, right, n, ans + '(', res)

        if right < left:
            self.helper(left, right + 1,  n, ans + ')', res)

        

s = Solution()
res = s.generateParenthesis(3)
print(res)