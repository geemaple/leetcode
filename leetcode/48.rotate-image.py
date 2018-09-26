# m row X n col
# Quadrant 1 | Quadrant 2
# --------------------->
# Quadrant 4 | Quadrant 3
# Q1: (x, y)
# Q2: (y, m - 1 - x)
# Q3: (m - 1 - x, n - 1 - y)
# Q4: (n - 1 - y, x) in Q4

# rotate +90 mirror up and down, and switch x and y
# rotate -90 mirror left and right, and switch x and y

class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        # mirror upside down matrix[::-1]
        # zip switch x and y
        matrix[:] = zip(*matrix[::-1])

class Solution2(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if matrix is None or len(matrix) == 0:
            return
        
        # mirror up and down
        up = 0
        down = len(matrix) - 1

        while(up < down):
            for j in range(len(matrix[0])):
                matrix[up][j], matrix[down][j] = matrix[down][j], matrix[up][j]
            up += 1
            down -= 1

        for i in range(len(matrix)):
            for j in range(i + 1, len(matrix[i])):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]