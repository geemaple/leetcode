import collections
class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        direction = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
        
        
        for i in range(len(board)):
            for j in range(len(board[i])):
                count = 0
                
                for x, y in direction:
                    if 0 <= i + x < len(board) and 0 <= j + y < len(board[i]):
                        count += (board[i + x][j + y] & 1)
                
                # condition 2
                if (board[i][j] & 1) == 1 and (count == 2 or count == 3):
                    board[i][j] = 0b11
                    
                # condition 4
                if (board[i][j] & 1) == 0 and count == 3:
                    board[i][j] = 0b10
                    
                    
        for i in range(len(board)):
            for j in range(len(board[i])):
                board[i][j] >>= 1