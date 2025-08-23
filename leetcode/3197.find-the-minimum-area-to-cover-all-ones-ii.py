#  Tag: Array, Matrix, Enumeration
#  Time: O(N^2M^2)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/2xIqXuUSS-o

#  You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.
#  Return the minimum possible sum of the area of these rectangles.
#  Note that the rectangles are allowed to touch.
#   
#  Example 1:
#  
#  Input: grid = [[1,0,1],[1,1,1]]
#  Output: 5
#  Explanation:
#  
#  
#  The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
#  The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
#  The 1 at (1, 1) is covered by a rectangle of area 1.
#  
#  
#  Example 2:
#  
#  Input: grid = [[1,0,1,0],[0,1,0,1]]
#  Output: 5
#  Explanation:
#  
#  
#  The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
#  The 1 at (1, 1) is covered by a rectangle of area 1.
#  The 1 at (1, 3) is covered by a rectangle of area 1.
#  
#  
#   
#  Constraints:
#  
#  1 <= grid.length, grid[i].length <= 30
#  grid[i][j] is either 0 or 1.
#  The input is generated such that there are at least three 1's in grid.
#  
#  

class Solution:
    def minimumSum(self, grid: List[List[int]]) -> int:
        res = float('inf')
        n = len(grid)
        m = len(grid[0])
        for i in range(n - 1):
            res = min(res,
                self.cal(grid, 0, 0, i, m - 1) + self.h_split(grid, i + 1, 0, n - 1, m - 1),
                self.cal(grid, 0, 0, i, m - 1) + self.v_split(grid, i + 1, 0, n - 1, m - 1),
                self.v_split(grid, 0, 0, i, m - 1) + self.cal(grid, i + 1, 0, n - 1, m - 1)
            )

        for j in range(m - 1):
            res = min(res,
                self.cal(grid, 0, 0, n - 1, j) + self.h_split(grid, 0, j + 1, n - 1, m - 1),
                self.cal(grid, 0, 0, n - 1, j) + self.v_split(grid, 0, j + 1, n - 1, m - 1),
                self.h_split(grid, 0, 0, n - 1, j) + self.cal(grid, 0, j + 1, n - 1, m - 1)
            )

        return res

    def h_split(self, grid: list, t: int, l: int, b: int, r: int) -> int:
        res = float('inf')
        for i in range(t, b + 1):
            res = min(res, self.cal(grid, t, l, i, r) + self.cal(grid, i + 1, l, b, r))

        return res

    def v_split(self, grid: list, t: int, l: int, b: int, r: int) -> int:
        res = float('inf')
        for j in range(l, r + 1):
            res = min(res, self.cal(grid, t, l, b, j) + self.cal(grid, t, j + 1, b, r))
        return res

    def cal(self, grid: list, t: int, l: int, b: int, r: int) -> int:
        
        top = b
        bottom = t
        left = r
        right = l
        for i in range(t, b + 1):
            for j in range(l, r + 1):
                if grid[i][j] == 1:
                    top = min(top, i)
                    bottom = max(bottom, i)
                    left = min(left, j)
                    right = max(right, j)

        res = (right - left + 1) * (bottom - top + 1)
        return res if res >= 1 else float('inf')