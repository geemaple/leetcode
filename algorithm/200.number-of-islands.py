'''
[200] Number of Islands  

https://leetcode.com/problems/number-of-islands/description/

* algorithms
* Medium (36.87%)
* Source Code:       200.number-of-islands.py
* Total Accepted:    179.4K
* Total Submissions: 486.3K
* Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
* Avail Languages:   c, cpp, csharp, golang, java, javascript, kotlin, python, python3, ruby, scala, swift

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:


Input:
11110
11010
11000
00000

Output: 1


Example 2:


Input:
11000
11000
00100
00011

Output: 3
'''

'''
------------------------->
|
|          top
|           |    
|    left <- -> right
|           |
|         bottom
|
V
'''

# class Solution(object):

#     MOVE_LEFT = (0, -1)
#     MOVE_RIGHT = (0, 1)
#     MOVE_TOP = (-1, 0)
#     MOVE_BOTTOM = (1, 0)

#     def numIslands(self, grid):
#         """
#         :type grid: List[List[str]]
#         :rtype: int
#         """
        
#         # corner case
#         if grid is None or len(grid) == 0:
#             return 0

#         row  = len(grid)
#         column = len(grid[0])

#         # find all node = '1'
#         candidates = set()
#         for i in range(row):
#             for j in range(column):
#                 if grid[i][j] is '1':
#                     candidates.add((i, j))

#         visted = set()
