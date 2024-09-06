#  Tag: Backtracking
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