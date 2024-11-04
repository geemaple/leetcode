#  Tag: Array, Binary Search, Matrix
#  Time: O(log(m * n))
#  Space: O(1)
#  Ref: -
#  Note: Matrix;

#  You are given an m x n integer matrix matrix with the following two properties:
#  
#  Each row is sorted in non-decreasing order.
#  The first integer of each row is greater than the last integer of the previous row.
#  
#  Given an integer target, return true if target is in matrix or false otherwise.
#  You must write a solution in O(log(m * n)) time complexity.
#   
#  Example 1:
#  
#  
#  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
#  Output: true
#  
#  Example 2:
#  
#  
#  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
#  Output: false
#  
#   
#  Constraints:
#  
#  m == matrix.length
#  n == matrix[i].length
#  1 <= m, n <= 100
#  -104 <= matrix[i][j], target <= 104
#  
#  

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])
        left = 0
        right = n * m - 1

        while left < right:
            mid = left + (right - left) // 2
            i, j = mid // m, mid % m
            if matrix[i][j] == target:
                return True

            if matrix[i][j] < target:
                left = mid + 1
            else:
                right = mid

        i, j = left // m, left % m
        return matrix[i][j] == target