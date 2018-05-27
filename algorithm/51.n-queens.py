class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        
        if n <= 0:
            return []

        # if cols = [3, 2, 1, 0]
        # cols[0] = 3 means 0th row, 3th colomn, (0, 3), (1, 2), (2, 1), (3, 0)

        cols = []
        results = []
        self.helper(n, cols, results)
        return results
    
    # dfs traversal
    def helper(self, n, cols, results):
        if len(cols) == n:
            results.append(self.draw_chessbord(cols))
            return

        for i in range(n):
            if not self.is_valid(cols, i):
                continue

            cols.append(i)
            self.helper(n, cols, results)
            cols.pop()


    def is_valid(self, cols, column):
        row = len(cols)

        # since index in cols is different, it is sure that each queen is not in the same row
        for row_index in range(row):

            # check if queue are in the same column
            if cols[row_index] == column:
                return False

            # check if queun are in diagonal position
            if row_index + cols[row_index] == row + column: 
                return False

            # mind the order of row minus column when subtraction
            if row_index - cols[row_index] == row - column:
                return False

        return True

    def draw_chessbord(self, cols):
        size = len(cols)
        chessboard = []
        for row in range(size):
            result = ''
            for column in range(size):
                result += 'Q' if column == cols[row] else '.'
            chessboard.append(result)

        return chessboard