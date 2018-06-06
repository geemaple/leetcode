class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        #search from top-right to bottom-left
        if matrix is None or len(matrix) == 0:
            return False

        x = 0
        y = len(matrix[0]) - 1

        while(x < len(matrix) and y >= 0):
            
            if matrix[x][y] == target:
                return True

            if matrix[x][y] > target:
                y -= 1
            else:
                x += 1

        return False