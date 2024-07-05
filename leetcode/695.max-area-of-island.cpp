//  Tag: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
//  Time: O(MN)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//  The area of an island is the number of cells with a value 1 in the island.
//  Return the maximum area of an island in grid. If there is no island, return 0.
//   
//  Example 1:
//  
//  
//  Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
//  Output: 6
//  Explanation: The answer is not 11, because the island must be connected 4-directionally.
//  
//  Example 2:
//  
//  Input: grid = [[0,0,0,0,0,0,0,0]]
//  Output: 0
//  
//   
//  Constraints:
//  
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n <= 50
//  grid[i][j] is either 0 or 1.
//  
//  

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    area = max(area, calculateArea(grid, i, j));
                }
            }
        }

        return area;
    }

    int calculateArea(vector<vector<int>>& grid, int i, int j) {
        int area = 0;
        int directions[] = {-1, 0, 1, 0, -1};
        deque<pair<int, int>> q;
        q.push_back(make_pair(i, j));
        grid[i][j] = 0;

        while (q.size() > 0) {
            auto p = q.front();
            q.pop_front();
            area += 1;

            for (int i = 0; i < 4; i++) {
                int x = p.first + directions[i];
                int y = p.second + directions[i + 1];
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size() && grid[x][y] == 1) {
                    q.push_back(make_pair(x, y));
                    grid[x][y] = 0;
                }
            }
        }

        return area;
    }
};