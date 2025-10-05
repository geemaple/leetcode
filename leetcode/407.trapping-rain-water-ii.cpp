//  Tag: Array, Breadth-First Search, Heap (Priority Queue), Matrix
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/v_pHAOp1Fzc

//  Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
//   
//  Example 1:
//  
//  
//  Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
//  Output: 4
//  Explanation: After the rain, water is trapped between the blocks.
//  We have two small ponds 1 and 3 units trapped.
//  The total volume of water trapped is 4.
//  
//  Example 2:
//  
//  
//  Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
//  Output: 10
//  
//   
//  Constraints:
//  
//  m == heightMap.length
//  n == heightMap[i].length
//  1 <= m, n <= 200
//  0 <= heightMap[i][j] <= 2 * 104
//  
//  

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            heap.emplace(heightMap[i][0], i, 0);
            heap.emplace(heightMap[i][m - 1], i, m - 1);
            visited[i][0] = visited[i][m - 1] = true;
        }

        for (int j = 0; j < m; j++) {
            heap.emplace(heightMap[0][j], 0, j);
            heap.emplace(heightMap[n - 1][j], n - 1, j);
            visited[0][j] = visited[n - 1][j] = true;
        }

        int res = 0;
        int directions[5] = {-1, 0, 1, 0, -1};
        while (!heap.empty()) {
            auto [h, i, j] = heap.top();
            heap.pop();

            for (int d = 0; d < 4; d++) {
                int x = i + directions[d];
                int y = j + directions[d + 1];
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    heap.emplace(max(heightMap[x][y], h), x, y);
                    res += max(0, h - heightMap[x][y]);
                }
            }
        }

        return res;
    }
};