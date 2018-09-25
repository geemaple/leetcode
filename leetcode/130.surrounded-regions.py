class Solution(object):



    def check(self, board, x, y):
        return (0 <= x < len(board) and 0 <= y < len(board[x]))

    def bfs(self, board, visited, x, y):

        if board[x][y] == 'X':
            return

        if (x, y) in visited:
            return

        directions = [[0, 1], [-1, 0], [0, -1], [1, 0]]
        queue = [(x, y)]
        visited.add((x, y))


        while(len(queue) > 0):
            top = queue.pop(0)
            for direct in directions:
                new_x = top[0] + direct[0]
                new_y = top[1] + direct[1]

                if self.check(board, new_x, new_y) and (new_x, new_y) not in visited and board[new_x][new_y] == 'O':
                    visited.add((new_x, new_y))
                    queue.append((new_x, new_y))
            

    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """

        if board is None or len(board) == 0 or len(board[0]) == 0:
            return

        visited = set()

        for i in range(len(board)):
            self.bfs(board, visited, i, 0)
            self.bfs(board, visited, i, len(board[i]) - 1)

        for j in range(1, len(board[0]) - 1):
            self.bfs(board, visited, 0, j)
            self.bfs(board, visited, len(board) - 1, j)

        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 'O' and (i, j) not in visited:
                    board[i][j] = 'X'
