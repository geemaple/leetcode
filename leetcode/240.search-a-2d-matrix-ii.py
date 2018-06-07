class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        
        if matrix is None:
            return False

        row = len(matrix)
        if row == 0:
            return False

        column = len(matrix[0])
        if column == 0:
            return False

        x = 0
        y = column - 1

        while(x < row and y >= 0):
            if matrix[x][y] == target:
                return True

            if matrix[x][y] > target:
                y -= 1
            else:
                x += 1

        return False