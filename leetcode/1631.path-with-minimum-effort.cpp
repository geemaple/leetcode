//  Tag: Array, Binary Search, Depth-First Search, Breadth-First Search, Union Find, Heap (Priority Queue), Matrix
//  Time: O(NMlogNM)
//  Space: O(NM)
//  Ref: -
//  Note: -

//  You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
//  A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
//  Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
//   
//  Example 1:
//  
//  
//  Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
//  Output: 2
//  Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
//  This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
//  
//  Example 2:
//  
//  
//  Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
//  Output: 1
//  Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
//  
//  Example 3:
//  
//  
//  Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
//  Output: 0
//  Explanation: This route does not require any effort.
//  
//   
//  Constraints:
//  
//  rows == heights.length
//  columns == heights[i].length
//  1 <= rows, columns <= 100
//  1 <= heights[i][j] <= 106
//  
//  

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int directions[5] = {-1, 0, 1, 0, -1};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({0, 0, 0});

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        while (!q.empty()) {
            auto [cost, x, y] = q.top();
            q.pop();

            if (x == n - 1 && y == m - 1) {
                return cost;
            }

            if (visited[x][y]) {
                continue;
            }
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int next_x = x + directions[i];
                int next_y = y + directions[i + 1];
                if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !visited[next_x][next_y]) {
                    int next_cost = max(abs(heights[x][y] - heights[next_x][next_y]), cost);
                    q.push({next_cost, next_x, next_y});
                } 
            }
        }

        return -1;
    }
};