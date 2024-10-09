#  Tag: Union Find
#  Time: O(K)
#  Space: O(NM + K)
#  Ref: -
#  Note: Leetcode-305

#  Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k).
#  Originally, the 2D matrix is all 0 which means there is only sea in the matrix.
#  The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island.
#  Return how many island are there in the matrix after each operator.You need to return an array of size K.
#  
#  **Example 1:**
#  
#  ```
#  Input: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
#  Output: [1,1,2,2]
#  Explanation:
#  0.  00000
#      00000
#      00000
#      00000
#  1.  00000
#      01000
#      00000
#      00000
#  2.  01000
#      01000
#      00000
#      00000
#  3.  01000
#      01000
#      00000
#      00010
#  4.  01000
#      01000
#      00000
#      00011
#  ```
#  
#  **Example 2:**
#  
#  ```
#  Input: n = 3, m = 3, A = [[0,0],[0,1],[2,2],[2,1]]
#  Output: [1,1,2,2]
#  ```
#  
#  0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

from typing import (
    List,
)
from lintcode import (
    Point,
)

"""
Definition for a point:
class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
"""
class UnionFind:
    def __init__(self, n):
        self.table = [i for i in range(n)]

    def find(self, a):
        if a == self.table[a]:
            return a

        self.table[a] = self.find(self.table[a])
        return self.table[a]

    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)

        if root_a != root_b:
            self.table[root_a] = root_b
            return True
        return False

class Solution:
    """
    @param n: An integer
    @param m: An integer
    @param operators: an array of point
    @return: an integer array
    """
    def num_islands2(self, n: int, m: int, operators: List[Point]) -> List[int]:
        # write your code here
        uf = UnionFind(n * m)
        directions = [-1, 0, 1, 0, -1]
        islands = set()
        res = []

        count = 0
        for p in operators:
            i, j = p.x, p.y
            islands.add((i, j))
            for d in range(4):
                x = i + directions[d]
                y = j + directions[d + 1]

                if 0 <= x < n and 0 <= y < m and (x, y) in islands:
                    if uf.connect(i * m + j, x * m + y):
                        count += 1

            res.append(len(islands) - count)

        return res