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

        start = 0
        end = row * column - 1

        while(start + 1 < end):
            mid = start + (end - start) / 2
            if matrix[mid / column][mid % column] == target:
                return True

            if matrix[mid / column][mid % column] > target:
                end = mid
            else:
                start = mid
        
        if matrix[start / column][start % column] == target:
            return True

        if matrix[end / column][end % column] == target:
            return True

        return False
