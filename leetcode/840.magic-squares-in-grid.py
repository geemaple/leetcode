#  Tag: Array, Hash Table, Math, Matrix
#  Time: O(NM)
#  Space: O(1)
#  Ref: -
#  Note: -

#  A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
#  Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?
#  Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
#   
#  Example 1:
#  
#  
#  Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
#  Output: 1
#  Explanation: 
#  The following subgrid is a 3 x 3 magic square:
#  
#  while this one is not:
#  
#  In total, there is only one magic square inside the given grid.
#  
#  Example 2:
#  
#  Input: grid = [[8]]
#  Output: 0
#  
#   
#  Constraints:
#  
#  row == grid.length
#  col == grid[i].length
#  1 <= row, col <= 10
#  0 <= grid[i][j] <= 15
#  
#  

class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        res = 0
        for i in range(n - 2):
            for j in range(m - 2):
                res += self.check(grid, i, j)
        return res

                
    def check(self, grid: List, x: int, y: int) -> bool:
        if x + 2 >= len(grid) or y + 2 >= len(grid[0]):
            return False

        number = set()
        for i in range(3):
            for j in range(3):
                if grid[x + i][y + j] < 1 or grid[x + i][y + j] > 9:
                    return False

                if grid[x + i][y + j] in number:
                    return False
                number.add(grid[x + i][y + j])

        dig = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2]
        rev = grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y]
        if dig != rev:
            return False

        for i in range(3):
            if grid[x + i][y] + grid[x + i][y + 1] + grid[x + i][y + 2] != dig:
                return False

        for j in range(3):
            if grid[x][y + j] + grid[x + 1][y + j] + grid[x + 2][y + j] != dig:
                return False

        return True



    

