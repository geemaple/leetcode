import collections
k_board_row = 2
k_board_col = 3
class Solution(object):
    def slidingPuzzle(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        start = self.to_state(board)
        target = 123450

        q = collections.deque()
        q.append(start)
        visited = set([start])
        steps = 0

        while q:
            size = len(q)
            for i in range(size):
                state = q.popleft()
                if state == target:
                    return steps

                for neighbor in self.get_neighbors(state):
                    if neighbor not in visited:
                        visited.add(neighbor)
                        q.append(neighbor)

            steps += 1

        return -1

    def get_neighbors(self, state):
        res = []
        board = self.to_board(state)
        row = 0
        col = 0

        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 0:
                    row, col = i, j
                    break

        directions = [[-1, 0], [0, -1], [1, 0], [0, 1]]
        for i in range(len(directions)):
  
            x = row + directions[i][0]
            y = col + directions[i][1]
            if 0 <= x < k_board_row and 0 <= y < k_board_col:
                # swap change
                board[x][y], board[row][col] = board[row][col], board[x][y]
                new_state = self.to_state(board)
                res.append(new_state)

                # recover back
                board[x][y], board[row][col] = board[row][col], board[x][y]

        return res

    def to_state(self, board):
        state = 0
        for row in board:
            for num in row:
                state = state * 10 + num
                
        return state
        
    def to_board(self, state):
        board = [[0, 0, 0] for i in range(k_board_row)]
        
        index = k_board_row * k_board_col - 1
        while state > 0:
            num = state % 10
            state = state // 10
            board[index // k_board_col][index % k_board_col] = num
            index -= 1

        return board