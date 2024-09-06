
from typing import List
from collections import defaultdict
import heapq

from collections import defaultdict
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
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
                    for number in range(9):
                        if row[i][number] or col[j][number] or zone[k][number]:
                            continue

                        row[i][number] = True
                        col[j][number] = True
                        zone[k][number] = True
                        board[i][j] = str(number + 1)
                        if self.helper(board, row, col, zone):
                            return True

                        board[i][j] = '.'
                        row[i][number] = False
                        col[j][number] = False
                        zone[k][number] = False
                
                    return False

        return True
        

s = Solution()
board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
res = s.solveSudoku(board)
print(board)