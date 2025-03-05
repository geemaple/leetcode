#  Tag: Mathmatics
#  Time: O(NMK)
#  Space: O(NM)
#  Ref: Leetcode-311
#  Note: -

#  Given two [Sparse Matrix](https://en.wikipedia.org/wiki/Sparse_matrix "Sparse Matrix") A and B, return the result of AB.
#  
#  You may assume that A's column number is equal to B's row number.
#  
#  **Example1**
#  ```
#  Input: 
#  [[1,0,0],[-1,0,3]]
#  [[7,0,0],[0,0,0],[0,0,1]]
#  Output:
#  [[7,0,0],[-7,0,3]]
#  Explanation:
#  A = [
#    [ 1, 0, 0],
#    [-1, 0, 3]
#  ]
#  
#  B = [
#    [ 7, 0, 0 ],
#    [ 0, 0, 0 ],
#    [ 0, 0, 1 ]
#  ]
#  
#  
#       |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
#  AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
#                    | 0 0 1 |
#  ```
#  **Example2**
#  ```
#  Input:
#  [[1,0],[0,1]]
#  [[0,1],[1,0]]
#  Output:
#  [[0,1],[1,0]]
#  ```
#  
#  

from typing import (
    List,
)

class Solution:
    """
    @param a: a sparse matrix
    @param b: a sparse matrix
    @return: the result of A * B
    """
    def multiply(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        # write your code here
        n = len(a)
        k = len(b)
        m = len(b[0])

        res = [[0] * m for i in range(n)]
        for i in range(n):
            for j in range(m):
                for d in range(k):
                    res[i][j] += a[i][d] * b[d][j]
                
        return res
    
class Solution:
    """
    @param a: a sparse matrix
    @param b: a sparse matrix
    @return: the result of A * B
    """
    def multiply(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        # write your code here
        n = len(a)
        m = len(b[0])
        
        sparseB = [[] for i in range(len(b))]
        res = [[0] * m for i in range(n)]
   
        for i in range(len(b)):
            for j in range(m):
                if b[i][j] != 0:
                    sparseB[i].append((j, b[i][j]))

        for i in range(n):
            for k in range(len(a[i])):
                if a[i][k] == 0:
                    continue

                for j, v in sparseB[k]:
                    res[i][j] += a[i][k] * v
        return res