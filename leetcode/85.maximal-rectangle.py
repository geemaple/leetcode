#  Tag: Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
#  Time: O(NM)
#  Space: O(M)
#  Ref: -
#  Note: -

#  Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
#   
#  Example 1:
#  
#  
#  Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
#  Output: 6
#  Explanation: The maximal rectangle is shown in the above picture.
#  
#  Example 2:
#  
#  Input: matrix = [["0"]]
#  Output: 0
#  
#  Example 3:
#  
#  Input: matrix = [["1"]]
#  Output: 1
#  
#   
#  Constraints:
#  
#  rows == matrix.length
#  cols == matrix[i].length
#  1 <= row, cols <= 200
#  matrix[i][j] is '0' or '1'.
#  
#  

# Based On 84
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        dp = [0 for i in range(m + 1)]
        res = 0
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '1':
                    dp[j] += 1
                else:
                    dp[j] = 0

            res = max(res, self.cal(dp))

        return res
                
    def cal(self, dp: list) -> int:
        res = 0
        stack = []
        for i in range(len(dp)):
            while len(stack) > 0 and dp[i] < dp[stack[-1]]:
                height = dp[stack[-1]]
                stack.pop()
                left = 0 if len(stack) == 0 else stack[-1] + 1
                res = max(res, (i - left) * height)

            stack.append(i)

        return res
    
# 3 dp
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        
        left = [0] * n
        right = [n] * n
        height = [0] * n
        
        res = 0
        for i in range(m):
            cur_left = 0
            cur_right = n
            
            # height dp
            for j in range(n):
                if matrix[i][j] == '1':
                    height[j] += 1
                else:
                    height[j] = 0
            
            # left dp
            for j in range(n):
                if matrix[i][j] == '1':
                    left[j] = max(left[j], cur_left)
                else:
                    left[j] = 0
                    cur_left = j + 1

            # right dp
            for j in range(n - 1, -1, -1):
                if matrix[i][j] == '1':
                    right[j] = min(right[j], cur_right)
                else:
                    right[j] = n
                    cur_right = j

            # area
            for j in range(n):
                res = max(res, (right[j] - left[j]) * height[j])
        
        return res
