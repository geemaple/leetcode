#  Tag: Array, Matrix, Simulation
#  Time: O(NM)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/saqXlKaw0Qs

#  Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
#   
#  Example 1:
#  
#  
#  Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
#  Output: [1,2,4,7,5,3,6,8,9]
#  
#  Example 2:
#  
#  Input: mat = [[1,2],[3,4]]
#  Output: [1,2,3,4]
#  
#   
#  Constraints:
#  
#  m == mat.length
#  n == mat[i].length
#  1 <= m, n <= 104
#  1 <= m * n <= 104
#  -105 <= mat[i][j] <= 105
#  
#  

class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        n = len(mat)
        m = len(mat[0])

        res = []
        i, j = 0, 0
        
        for k in range(m * n):
            res.append(mat[i][j])
            if (i + j) % 2 == 0:  # up direction
                if j == m - 1:
                    i += 1
                elif i == 0:
                    j += 1
                else:
                    i -= 1
                    j += 1
            else:  # down direction
                if i == n - 1:
                    j += 1
                elif j == 0:
                    i += 1
                else:
                    i += 1
                    j -= 1

        return res

class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        n = len(mat)
        m = len(mat[0])

        up = True
        res = []
        for k in range(m + n - 1):
            if up:
                for i in range(min(n - 1, k), -1, -1):
                    j = k - i
                    if j < m:
                        res.append(mat[i][j])
                    else:
                        break
            else:
                for j in range(min(m - 1, k), -1, -1):
                    i = k - j
                    if i < n:
                        res.append(mat[i][j])
                    else:
                        break

            up = not up
        return res
