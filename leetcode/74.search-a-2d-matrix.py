# Your runtime beats 4.35 % of python submissions
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if matrix is None or len(matrix) == 0:
            return False

        row = len(matrix)
        column = len(matrix[0])

        if column == 0:
            return False

        start = 0
        end = row * column - 1

        while(start + 1 < end):
            mid = start + (end - start) / 2
            x = mid / column
            y = mid % column

            if matrix[x][y] == target:
                return True

            if matrix[x][y] > target:
                end = mid
            else:
                start = mid
        
        if matrix[start / column][start % column] == target:
            return True

        if matrix[end / column][end % column] == target:
            return True

        return False
