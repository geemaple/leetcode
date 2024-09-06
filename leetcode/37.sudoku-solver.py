#  Tag: Array, Hash Table, Backtracking, Matrix
#  Time: O(N^(N^2))
#  Space: O(N)
#  Ref: -
#  Note: -

#  Write a program to solve a Sudoku puzzle by filling the empty cells.
#  A sudoku solution must satisfy all of the following rules:
#  
#  Each of the digits 1-9 must occur exactly once in each row.
#  Each of the digits 1-9 must occur exactly once in each column.
#  Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
#  
#  The '.' character indicates empty cells.
#   
#  Example 1:
#  
#  
#  Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
#  Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
#  Explanation: The input board is shown above and the only valid solution is shown below:
#  
#  
#  
#   
#  Constraints:
#  
#  board.length == 9
#  board[i].length == 9
#  board[i][j] is a digit or '.'.
#  It is guaranteed that the input board has only one solution.
#  
#  

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n = len(board)
        row = [[False] * (n + 1) for i in range(n)]
        col = [[False] * (n + 1) for i in range(n)]
        zone = [[False] * (n + 1) for i in range(n)]
        
        for i in range(n):
            for j in range(n):
                if board[i][j] == '.':
                    continue
                k = i // 3 * 3 + j // 3
                number = int(board[i][j])
                row[i][number] = True
                col[j][number] = True
                zone[k][number] = True

        self.helper(board, row, col, zone)

    def helper(self, board: list, row: list, col: list, zone: list) -> bool:
        n = len(board)
        for i in range(n):
            for j in range(n):
                if board[i][j] == '.':
                    k = i // 3 * 3 + j // 3
                    for number in range(1, 10):
                        if row[i][number] or col[j][number] or zone[k][number]:
                            continue

                        row[i][number] = True
                        col[j][number] = True
                        zone[k][number] = True
                        board[i][j] = str(number)
                        if self.helper(board, row, col, zone):
                            return True

                        board[i][j] = '.'
                        row[i][number] = False
                        col[j][number] = False
                        zone[k][number] = False
                
                    return False

        return True