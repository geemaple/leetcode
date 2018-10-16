class Solution:
    """
    @param: A: An integer A
    @return: The index of the peak
    """
    def findPeakII(self, A):
        return self.find_peak(A, 0, len(A) - 1, 0, len(A[0]) - 1)
        
    def find_peak(self, A, top, bottom, left, right):
        if top + 1 >= bottom and left + 1 >= right:
            
            x, y = top, left
            if (A[top][right] > A[x][y]):
                x, y = top, right
                
            if (A[bottom][left] > A[x][y]):
                x, y = bottom, left       
                
            if (A[bottom][right] > A[x][y]):
                x, y = bottom, right
                
            return [x, y]
            
            
        horizontal = bottom - top + 1 >= right - left + 1
            
        if horizontal:
            row = (top + bottom) // 2
            col = self.find_row_peak(A, row, left, right)
            
            if self.is_peak(A, row, col):
                return [row, col]
            if A[row - 1][col] > A[row][col]:
                return self.find_peak(A, top, row, left, right)
            return self.find_peak(A, row, bottom, left, right)           
            
        else:
            col = (left + right) // 2
            row = self.find_col_peak(A, col, top, bottom)
            
            if self.is_peak(A, row, col):
                return [row, col]
            if A[row][col - 1] > A[row][col]:
                return self.find_peak(A, top, bottom, left, col)
            return self.find_peak(A, top, bottom, col, right)

        
    def is_peak(self, A, x, y):
        return A[x][y] == max(
            A[x][y],
            A[x - 1][y],
            A[x][y - 1],
            A[x][y + 1],
            A[x + 1][y],
        )

    def find_row_peak(self, A, row, left, right):
        peak = left
        for col in range(left + 1, right + 1):
            if A[row][col] > A[row][peak]:
                peak = col
        return peak
        
    def find_col_peak(self, A, col, top, bottom):
        peak = top
        for row in range(top + 1, bottom + 1):
            if A[row][col] > A[peak][col]:
                peak = row
        return peak