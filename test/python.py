
from typing import List
from collections import defaultdict
import heapq

from collections import defaultdict
class Solution:
    def totalNQueens(self, n: int) -> int:
        self.res = 0
        self.helper(n, 0, 0, 0, 0)
        return self.res
        
    def helper(self, n: int, row: int, cols: int, rd:int, ld:int) -> None:
        if row == n:
            self.res += 1
            return
        
        # (cols | rd | ld) 三个方向取或，0就是没有占用的位置
        # ～取反，1就是没有占用的位置, 但是32位的头部0也会变成1 
        # 所以, ((1 << n) - 1)只有后这些位置是有意义的。
        candidate = ~(cols | rd | ld) & ((1 << n) - 1) 


        while candidate > 0:
            
            # 得到末尾的1(负数的表示正数取反+1), 获得放置位置
            p = candidate & -candidate 
            
            # 往下递归时，列垂直向下, ↖️↘️往右移一位, ↙️↗️往左移一位
            self.helper(n, row + 1, cols | p, (rd | p) >> 1, (ld | p) << 1)
            
            # 消掉末尾的1
            candidate &= candidate - 1  

s = Solution()
res = s.totalNQueens(8)
print(res)