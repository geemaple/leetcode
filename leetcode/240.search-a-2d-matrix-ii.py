#  Tag: Array, Binary Search, Divide and Conquer, Matrix
#  Time: O(M + N)
#  Space: O(1)
#  Ref: -
#  Note: Matrix

#  Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
#  
#  Integers in each row are sorted in ascending from left to right.
#  Integers in each column are sorted in ascending from top to bottom.
#  
#   
#  Example 1:
#  
#  
#  Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
#  Output: true
#  
#  Example 2:
#  
#  
#  Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
#  Output: false
#  
#   
#  Constraints:
#  
#  m == matrix.length
#  n == matrix[i].length
#  1 <= n, m <= 300
#  -109 <= matrix[i][j] <= 109
#  All the integers in each row are sorted in ascending order.
#  All the integers in each column are sorted in ascending order.
#  -109 <= target <= 109
#  
#  

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])

        i = 0
        j = n - 1

        while i < m and j >= 0:
            
            if target == matrix[i][j]:
                return True
            
            if target > matrix[i][j]:
                i += 1
            else:
                j -= 1

        return False
    
