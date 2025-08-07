#  Tag: Array, Dynamic Programming
#  Time: O(N^2)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/gZNCnr7jzJk

#  Given an integer numRows, return the first numRows of Pascal's triangle.
#  In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
#  
#   
#  Example 1:
#  Input: numRows = 5
#  Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
#  Example 2:
#  Input: numRows = 1
#  Output: [[1]]
#  
#   
#  Constraints:
#  
#  1 <= numRows <= 30
#  
#  

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for row in range(0, numRows):
            tmp = [1] * (row + 1)
            for j in range(1, row):
                tmp[j] = level[j] + level[j - 1]

            level = tmp
            res.append(level)

        return res