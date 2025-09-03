//  Tag: Array, Binary Search, Breadth-First Search, Matrix
//  Time: O(MNlog(MN))
//  Space: O(MN)
//  Ref: -
//  Note: -

//  You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:
//  
//  0 represents grass,
//  1 represents fire,
//  2 represents a wall that you and fire cannot pass through.
//  
//  You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.
//  Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.
//  Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.
//  A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
//   
//  Example 1:
//  
//  
//  Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
//  Output: 3
//  Explanation: The figure above shows the scenario where you stay in the initial position for 3 minutes.
//  You will still be able to safely reach the safehouse.
//  Staying for more than 3 minutes will not allow you to safely reach the safehouse.
//  Example 2:
//  
//  
//  Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
//  Output: -1
//  Explanation: The figure above shows the scenario where you immediately move towards the safehouse.
//  Fire will spread to any cell you move towards and it is impossible to safely reach the safehouse.
//  Thus, -1 is returned.
//  
//  Example 3:
//  
//  
//  Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
//  Output: 1000000000
//  Explanation: The figure above shows the initial grid.
//  Notice that the fire is contained by walls and you will always be able to safely reach the safehouse.
//  Thus, 109 is returned.
//  
//   
//  Constraints:
//  
//  m == grid.length
//  n == grid[i].length
//  2 <= m, n <= 300
//  4 <= m * n <= 2 * 104
//  grid[i][j] is either 0, 1, or 2.
//  grid[0][0] == grid[m - 1][n - 1] == 0
//  
//  

class Solution {
public:
   int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int directions[5] = {-1, 0, 1, 0, -1};

        vector<vector<int>> fire(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        int t = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto [i, j] = q.front(); 
                q.pop();
                fire[i][j] = t;
                for (int d = 0; d < 4; d++) {
                    int dx = i + directions[d];
                    int dy = j + directions[d + 1];
                    if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] == 0 && !visited[dx][dy]) {
                        q.push({dx, dy});
                        visited[dx][dy] = true;
                    }
                }
            }
            t++;
        }

        priority_queue<tuple<int,int,int,int>> heap;

        heap.push({fire[0][0], 0, 0, 0});
        int res = INT_MAX;

        while (!heap.empty()) {
            auto [wait, i, j, t] = heap.top(); 
            heap.pop();
            if (fire[i][j] == -1) {
                continue;
            }

            fire[i][j] = -1;
            res = min(res, wait);
            if (i == n - 1 && j == m - 1) {
                return res < INT_MAX ? res : 1000000000;
            } else if (wait < 0) {
                return -1;
            }

            for (int d = 0; d < 4; d++) {
                int dx = i + directions[d];
                int dy = j + directions[d + 1];
                if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] == 0 && fire[dx][dy] != -1) {
                    if (dx == n - 1 && dy == m - 1) {
                        heap.push({fire[dx][dy] == INT_MAX ? INT_MAX: fire[dx][dy] - t - 1, dx, dy, t + 1});
                    } else {
                        heap.push({fire[dx][dy] == INT_MAX ? INT_MAX: fire[dx][dy] - t - 2, dx, dy, t + 1});
                    }
                }
            }
        }

        return -1;
    }
};