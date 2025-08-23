#  Tag: Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
#  Time: O(MN)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/ZlmQt7M5HUg

#  Given an m x n binary matrix mat, return the number of submatrices that have all ones.
#   
#  Example 1:
#  
#  
#  Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
#  Output: 13
#  Explanation: 
#  There are 6 rectangles of side 1x1.
#  There are 2 rectangles of side 1x2.
#  There are 3 rectangles of side 2x1.
#  There is 1 rectangle of side 2x2. 
#  There is 1 rectangle of side 3x1.
#  Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
#  
#  Example 2:
#  
#  
#  Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
#  Output: 24
#  Explanation: 
#  There are 8 rectangles of side 1x1.
#  There are 5 rectangles of side 1x2.
#  There are 2 rectangles of side 1x3. 
#  There are 4 rectangles of side 2x1.
#  There are 2 rectangles of side 2x2. 
#  There are 2 rectangles of side 3x1. 
#  There is 1 rectangle of side 3x2. 
#  Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
#  
#   
#  Constraints:
#  
#  1 <= m, n <= 150
#  mat[i][j] is either 0 or 1.
#  
#  

class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        dp = [0] * n

        res = 0
        for i in range(m):
            for j in range(n):
                dp[j] = dp[j] + 1 if mat[i][j] == 1 else 0

            res += self.count(dp)

        return res
    
    def count(self, dp: list):
        res = [0] * len(dp)
        stack = []
        
        for i in range(len(dp)):
            while stack and dp[stack[-1]] >= dp[i]:
                stack.pop()
            
            if len(stack) > 0:
                l = stack[-1]
                res[i] = res[l]
                res[i] += dp[i] * (i - l)
            else:
                res[i] = dp[i] * (i + 1)
            
            stack.append(i)
        
        return sum(res)
    
class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])

        res = 0
        for i in range(m):
            arr = [1] * n
            for j in range(i, m):
                for k in range(n):
                    arr[k] &= mat[j][k]

                res += self.count(arr)

        return res
    
    def count(self, arr: list) -> int:
        n = len(arr)
        res = 0
        length = 0
        for i in range(n):
            length = 0 if arr[i] == 0 else length + 1
            res += length

        return res
