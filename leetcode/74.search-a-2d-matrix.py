class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        
        if matrix is None or len(matrix) == 0 or len(matrix[0]) == 0:
            return False

        row = len(matrix)
        col = len(matrix[0])

        start = 0
        end = row * col - 1

        while(start + 1 < end):
            mid = start + (end - start) / 2
            val = matrix[mid / col][mid % col]
        
            if val > target:
                end = mid
            elif val < target:
                start = mid
            else:
                return True
        
        return (matrix[start / col][start % col] == target or matrix[end / col][end % col] == target)
