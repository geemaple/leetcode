class Solution(object):

    count = 0
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.count = 0
        cols = []
        self.helper(n, cols)

        return self.count

    def helper(self, n, cols):
        if len(cols) == n:
            self.count += 1
            return

        for column in range(n):
            if not self.is_valid(cols, column):
                continue

            cols.append(column)
            self.helper(n, cols)
            cols.pop()


    def is_valid(self, cols, column):
        row = len(cols)

        for row_index in range(row):
            if cols[row_index] == column:
                return False

            if row_index + cols[row_index] == row + column:
                return False

            if row_index - cols[row_index] == row - column:
                return False

        return True