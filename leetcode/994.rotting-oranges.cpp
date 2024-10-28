//  Tag: Array, Breadth-First Search, Matrix
//  Time: O(NM)
//  Space: O(NM)
//  Ref: -
//  Note: -

//  You are given an m x n grid where each cell can have one of three values:
//  
//  0 representing an empty cell,
//  1 representing a fresh orange, or
//  2 representing a rotten orange.
//  
//  Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
//  Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
//   
//  Example 1:
//  
//  
//  Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
//  Output: 4
//  
//  Example 2:
//  
//  Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
//  Output: -1
//  Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
//  
//  Example 3:
//  
//  Input: grid = [[0,2]]
//  Output: 0
//  Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
//  
//   
//  Constraints:
//  
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n <= 10
//  grid[i][j] is 0, 1, or 2.
//  
//  

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh += 1;
                } else if (grid[i][j] == 2){
                    q.emplace(i, j);
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }
        int res = 0;
        int directions[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int size = q.size();
            res += 1;
            for (int k = 0; k < size; k++) {
                pair<int, int> p = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int x = p.first + directions[d];
                    int y = p.second + directions[d + 1];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                        fresh -= 1;
                        grid[x][y] = 2;
                        q.emplace(x, y);
                    }
                }
            }
        }

        return fresh == 0 ? res - 1 : -1;
    }
};