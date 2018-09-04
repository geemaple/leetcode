class Solution(object):

    directions = [(0, -1), (-1, 0), (0, 1), (1, 0)]

    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """

        visted = set()

        for i in range(len(board)):
            for j in range(len(board[i])):
                if self.search_dfs(board, i, j, visted, word, 0):
                    return True

        return False

    def check_in_board(self, board, x, y):
        return (0 <= x < len(board) and 0 <= y < len(board[x]))

    def search_dfs(self, board, x, y, visted, word, index):

        if board[x][y] != word[index]:
            return False

        if index == len(word) - 1:
            return True

        visted.add((x, y))
        for direction in self.directions:
            new_x = x + direction[0]
            new_y = y + direction[1]

            if self.check_in_board(board, new_x, new_y) and (new_x, new_y) not in visted:
                if (self.search_dfs(board, new_x, new_y, visted, word, index + 1)):
                    return True

        visted.remove((x, y))
        return False