class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []
        
        x_directions = [0, 1, 0, -1]
        y_directions = [1, 0, -1, 0]
        shrink_bounds = [1, -1, -1, 1]
        
        top, left, bottom, right = 0, 0, len(matrix) - 1, len(matrix[0]) - 1
        bounds = [top, right, bottom, left]
        
        res = []
        i, j = top, left
        res.append(matrix[i][j])
        
        while bounds[0] <= bounds[2] and bounds[3] <= bounds[1]:
            
            for k in range(4):
                while bounds[0] <= i + x_directions[k] <= bounds[2] and bounds[3] <= j + y_directions[k] <= bounds[1]:
                    i += x_directions[k]
                    j += y_directions[k]
                    res.append(matrix[i][j])
            
                bounds[k] += shrink_bounds[k]
                
        return res