#  Tag: Array, Hash Table, Matrix
#  Time: O(N^2)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/uTGP_TbEE2g

#  Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
#  
#  Each row must contain the digits 1-9 without repetition.
#  Each column must contain the digits 1-9 without repetition.
#  Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
#  
#  Note:
#  
#  A Sudoku board (partially filled) could be valid but is not necessarily solvable.
#  Only the filled cells need to be validated according to the mentioned rules.
#  
#   
#  Example 1:
#  
#  
#  Input: board = 
#  [["5","3",".",".","7",".",".",".","."]
#  ,["6",".",".","1","9","5",".",".","."]
#  ,[".","9","8",".",".",".",".","6","."]
#  ,["8",".",".",".","6",".",".",".","3"]
#  ,["4",".",".","8",".","3",".",".","1"]
#  ,["7",".",".",".","2",".",".",".","6"]
#  ,[".","6",".",".",".",".","2","8","."]
#  ,[".",".",".","4","1","9",".",".","5"]
#  ,[".",".",".",".","8",".",".","7","9"]]
#  Output: true
#  
#  Example 2:
#  
#  Input: board = 
#  [["8","3",".",".","7",".",".",".","."]
#  ,["6",".",".","1","9","5",".",".","."]
#  ,[".","9","8",".",".",".",".","6","."]
#  ,["8",".",".",".","6",".",".",".","3"]
#  ,["4",".",".","8",".","3",".",".","1"]
#  ,["7",".",".",".","2",".",".",".","6"]
#  ,[".","6",".",".",".",".","2","8","."]
#  ,[".",".",".","4","1","9",".",".","5"]
#  ,[".",".",".",".","8",".",".","7","9"]]
#  Output: false
#  Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
#  
#   
#  Constraints:
#  
#  board.length == 9
#  board[i].length == 9
#  board[i][j] is a digit 1-9 or '.'.
#  
#  

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)

        row = [0] * n
        col = [0] * n
        sec = [0] * n

        for i in range(n):
            for j in range(n):
                if board[i][j] != '.':
                    
                    num = ord(board[i][j]) - ord('0')
                    bit = 1 << num
                    s = (i // 3) * 3 + (j // 3)

                    if bit & row[i] or bit & col[j] or bit & sec[s]:
                        return False

                    row[i] |= bit
                    col[j] |= bit
                    sec[s] |= bit

        return True

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)
        row = [[False] * n for i in range(n)]
        col = [[False] * n for i in range(n)]
        zone = [[False] * n for i in range(n)]

        for i in range(n):
            for j in range(n):
                if board[i][j] == '.':
                    continue
                k = i // 3 * 3 + j // 3
                number = int(board[i][j]) - 1

                if row[i][number] or col[j][number] or zone[k][number]:
                    return False

                row[i][number] = True
                col[j][number] = True
                zone[k][number] = True
                
        return True   