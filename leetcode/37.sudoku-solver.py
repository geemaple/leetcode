#
# @lc app=leetcode id=37 lang=python3
#
# [37] Sudoku Solver
#
# https://leetcode.com/problems/sudoku-solver/description/
#
# algorithms
# Hard (42.48%)
# Total Accepted:    194K
# Total Submissions: 442.6K
# Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
#
# Write a program to solve a Sudoku puzzle by filling the empty cells.
# 
# A sudoku solution must satisfy all of the following rules:
# 
# 
# Each of the digits 1-9 must occur exactly once in each row.
# Each of the digits 1-9 must occur exactly once in each column.
# Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
# sub-boxes of the grid.
# 
# 
# Empty cells are indicated by the character '.'.
# 
# 
# A sudoku puzzle...
# 
# 
# ...and its solution numbers marked in red.
# 
# Note:
# 
# 
# The given board contain only digits 1-9 and the character '.'.
# You may assume that the given Sudoku puzzle will have a single unique
# solution.
# The given board size is always 9x9.
# 
# 
#
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        n = len(board)
        
        row = [[False for j in range(n)] for i in range(n)]
        col = [[False for j in range(n)] for i in range(n)]
        zone = [[False for j in range(n)] for i in range(n)]
        
        for i in range(n):
            for j in range(n):
                if board[i][j] == '.':
                    continue
                    
                z = i // 3 * 3 + j // 3
                num = int(board[i][j]) - 1
                row[i][num] = True
                col[j][num] = True
                zone[z][num] = True
                     
        self.helper(board, 0, row, col, zone, n)
               
    def helper(self, board:List[List[str]], index:int, row:List[List[bool]], col:List[List[bool]], zone:List[List[bool]], n:int) -> bool:

        if index == n * n:
            return True
        
        i = index // n
        j = index % n
        z = i // 3 * 3 + j // 3
        
        if board[i][j] == '.':
            for num in range(n):
                if row[i][num] or col[j][num] or zone[z][num]:
                    continue

                board[i][j] = str(num + 1)
                row[i][num] = col[j][num] = zone[z][num] = True

                if self.helper(board, index + 1, row, col, zone, n):
                    return True
                
                board[i][j] = '.'
                row[i][num] = col[j][num] = zone[z][num] = False
        else:
            if self.helper(board, index + 1, row, col, zone, n):
                return True