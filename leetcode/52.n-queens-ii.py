#  Tag: Backtracking, Bitmask
#  Time: O(N!)
#  Space: O(N)
#  Ref: -
#  Note: -

#  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
#  Given an integer n, return the number of distinct solutions to the n-queens puzzle.
#   
#  Example 1:
#  
#  
#  Input: n = 4
#  Output: 2
#  Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
#  
#  Example 2:
#  
#  Input: n = 1
#  Output: 1
#  
#   
#  Constraints:
#  
#  1 <= n <= 9
#  
#  

class Solution:
    def totalNQueens(self, n: int) -> int:
        return  self.helper(0, n, set(), set(), set())

    def helper(self, i:int, n:int, col: set, dia: set, anti_dia: set) -> int:

        if i == n:
            return 1

        count = 0
        for j in range(n):
            if j in col or i + j in dia or i - j in anti_dia:
                continue

            col.add(j)
            dia.add(i + j)
            anti_dia.add(i - j)
            count += self.helper(i + 1, n, col, dia, anti_dia)
            col.remove(j)
            dia.remove(i + j)
            anti_dia.remove(i - j)

        return count
    
class Solution:
    def totalNQueens(self, n: int) -> int:
        self.res = 0
        self.helper(n, 0, 0, 0, 0)
        return self.res
        
    def helper(self, n: int, row: int, cols: int, left:int, right:int) -> None:
        
        if row == n:
            self.res += 1
            return
        
        # (cols | left | right) 三个方向取或，0就是没有占用的位置
        # ～取反，1就是没有占用的位置, 但是32位的头部0也会变成1 
        # 所以, ((1 << n) - 1)只有后这些位置是有意义的。
        taken = cols | left | right
        mask = ~taken & ((1 << n) - 1) 

        while mask > 0:
            
            # 得到末尾的1(负数的表示正数取反+1), 获得放置位置
            p = mask & -mask 
            
            # 往下递归时，列垂直向下, ↖️↘️往右移一位, ↙️↗️往左移一位
            self.helper(n, row + 1, cols | p, (left | p) >> 1, (right | p) << 1)
            
            # 消掉末尾的1
            mask &= mask - 1 