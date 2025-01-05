//  Tag: Array, Binary Search, Depth-First Search, Breadth-First Search, Union Find, Heap (Priority Queue), Matrix
//  Time: O(N^2 * logN)
//  Space: O(N^2)
//  Ref: -
//  Note: -

//  You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
//  The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
//  Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
//   
//  Example 1:
//  
//  
//  Input: grid = [[0,2],[1,3]]
//  Output: 3
//  Explanation:
//  At time 0, you are in grid location (0, 0).
//  You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
//  You cannot reach point (1, 1) until time 3.
//  When the depth of water is 3, we can swim anywhere inside the grid.
//  
//  Example 2:
//  
//  
//  Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
//  Output: 16
//  Explanation: The final route is shown.
//  We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
//  
//   
//  Constraints:
//  
//  n == grid.length
//  n == grid[i].length
//  1 <= n <= 50
//  0 <= grid[i][j] < n2
//  Each value grid[i][j] is unique.
//  
//  

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
        int res = 0;
        vector<vector<bool>> visited(n, vector<bool>(n , false));
        q.emplace(grid[0][0], 0, 0);
        int directions[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            auto [h, i, j] = q.top();
            q.pop();
            if (!visited[i][j]) {
                visited[i][j] = true;
                res = max(res, h);
                if (i == n - 1 && j == n - 1) {
                    return res;
                }

                for (int d = 0; d < 4; d++) {
                    int x = i + directions[d];
                    int y = j + directions[d + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]) {
                        q.emplace(grid[x][y], x, y);
                    }
                }
            }
        }

        return -1;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int left = 0;
        int right = 2500;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSwim(grid, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool canSwim(vector<vector<int>>& grid, int t) {
        if (grid[0][0] > t) {
            return false;
        }

        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;
        vector<int> directions = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == n - 1 && j == n - 1) {
                return true;
            }
            
            for (int d = 0; d < 4; d++) {
                int x = i + directions[d];
                int y = j + directions[d + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t && !visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }

        return false;
    }
};