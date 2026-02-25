//  Tag: Array, Dynamic Programming, Matrix
//  Time: O((K+logMN) * MN)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  You are given a m x n 2D integer array grid and an integer k. You start at the top-left cell (0, 0) and your goal is to reach the bottom‐right cell (m - 1, n - 1).
//  There are two types of moves available:
//  
//  
//  Normal move: You can move right or down from your current cell (i, j), i.e. you can move to (i, j + 1) (right) or (i + 1, j) (down). The cost is the value of the destination cell.
//  
//  
//  Teleportation: You can teleport from any cell (i, j), to any cell (x, y) such that grid[x][y] <= grid[i][j]; the cost of this move is 0. You may teleport at most k times.
//  
//  
//  Return the minimum total cost to reach cell (m - 1, n - 1) from (0, 0).
//   
//  Example 1:
//  
//  Input: grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2
//  Output: 7
//  Explanation:
//  Initially we are at (0, 0) and cost is 0.
//  
//  
//  
//  Current Position
//  Move
//  New Position
//  Total Cost
//  
//  
//  (0, 0)
//  Move Down
//  (1, 0)
//  0 + 2 = 2
//  
//  
//  (1, 0)
//  Move Right
//  (1, 1)
//  2 + 5 = 7
//  
//  
//  (1, 1)
//  Teleport to (2, 2)
//  (2, 2)
//  7 + 0 = 7
//  
//  
//  
//  The minimum cost to reach bottom-right cell is 7.
//  
//  Example 2:
//  
//  Input: grid = [[1,2],[2,3],[3,4]], k = 1
//  Output: 9
//  Explanation: 
//  Initially we are at (0, 0) and cost is 0.
//  
//  
//  
//  Current Position
//  Move
//  New Position
//  Total Cost
//  
//  
//  (0, 0)
//  Move Down
//  (1, 0)
//  0 + 2 = 2
//  
//  
//  (1, 0)
//  Move Right
//  (1, 1)
//  2 + 3 = 5
//  
//  
//  (1, 1)
//  Move Down
//  (2, 1)
//  5 + 4 = 9
//  
//  
//  
//  The minimum cost to reach bottom-right cell is 9.
//  
//   
//  Constraints:
//  
//  2 <= m, n <= 80
//  m == grid.length
//  n == grid[i].length
//  0 <= grid[i][j] <= 104
//  0 <= k <= 10
//  
//  

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(),
             [&](const auto& p1, const auto& p2) -> bool {
                 return grid[p1.first][p1.second] < grid[p2.first][p2.second];
             });
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int t = 0; t <= k; t++) {
            int minCost = INT_MAX;
            for (int i = 0, j = 0; i < points.size(); i++) {
                minCost = min(minCost, dp[points[i].first][points[i].second]);
                if (i + 1 < points.size() &&
                    grid[points[i].first][points[i].second] == grid[points[i + 1].first][points[i + 1].second]) {
                    continue;
                }
                for (int r = j; r <= i; r++) {
                    dp[points[r].first][points[r].second] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        dp[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j != n - 1) {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};