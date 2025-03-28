//  Tag: Array, Two Pointers, Breadth-First Search, Union Find, Sorting, Heap (Priority Queue), Matrix
//  Time: O(KlogK + KNM * log(NM))
//  Space: O(K + NM)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/mg_R41oWzTM

//  You are given an m x n integer matrix grid and an array queries of size k.
//  Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
//  
//  If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
//  Otherwise, you do not get any points, and you end this process.
//  
//  After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
//  Return the resulting array answer.
//   
//  Example 1:
//  
//  
//  Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
//  Output: [5,8,1]
//  Explanation: The diagrams above show which cells we visit to get points for each query.
//  Example 2:
//  
//  
//  Input: grid = [[5,2,1],[1,1,2]], queries = [3]
//  Output: [0]
//  Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
//  
//   
//  Constraints:
//  
//  m == grid.length
//  n == grid[i].length
//  2 <= m, n <= 1000
//  4 <= m * n <= 105
//  k == queries.length
//  1 <= k <= 104
//  1 <= grid[i][j], queries[i] <= 106
//  
//  

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int directions[5] = {-1, 0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> index_queries;
        for (int i = 0; i < queries.size(); i++) {
            index_queries.emplace_back(queries[i], i);
        }
        sort(index_queries.begin(), index_queries.end());
        priority_queue<tuple<int, int, int>> q;
        q.push({-grid[0][0], 0, 0});
        grid[0][0] = 0;

        vector<int> res(queries.size(), 0);
        int count = 0;
        for (auto &p: index_queries) {
            while (!q.empty() && -get<0>(q.top()) < p.first) {
                auto [val, x, y] = q.top();
                q.pop();
                count += 1;
                for (int d = 0; d < 4; d++) {
                    int dx = x + directions[d];
                    int dy = y + directions[d + 1];
                    if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy]) {
                        q.push({-grid[dx][dy], dx, dy});
                        grid[dx][dy] = 0;
                    }
                }
            }
            
            res[p.second] = count;
        }
        return res;
    }
};