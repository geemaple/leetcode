//  Tag: Array, Depth-First Search, Breadth-First Search, Matrix
//  Time: O(N^2)
//  Space: O(N^2)
//  Ref: -
//  Note: -

//  You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//  An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//  You may change 0's to 1's to connect the two islands to form one island.
//  Return the smallest number of 0's you must flip to connect the two islands.
//   
//  Example 1:
//  
//  Input: grid = [[0,1],[1,0]]
//  Output: 1
//  
//  Example 2:
//  
//  Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
//  Output: 2
//  
//  Example 3:
//  
//  Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//  Output: 1
//  
//   
//  Constraints:
//  
//  n == grid.length == grid[i].length
//  2 <= n <= 100
//  grid[i][j] is either 0 or 1.
//  There are exactly two islands in grid.
//  
//  

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        dfs(grid, q);

        int directions[] = {-1, 0, 1, 0, -1};
        int res = 0;
        while (!q.empty()) {
            res ++;
            int count = q.size();
            for (int i = 0; i < count; i++) {
                pair<int, int>p = q.front();
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int dx = p.first + directions[k];
                    int dy = p.second + directions[k + 1];
                    if (dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[dx].size()) {
                        if (grid[dx][dy] == 0) {
                            grid[dx][dy] = 2;
                            q.push(make_pair(dx, dy));
                        } else if (grid[dx][dy] == 1) {
                            return res;
                        }
                    }
                }
            }
        }

        return -1;
    }

    void dfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        int directions[] = {-1, 0, 1, 0, -1};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    stack<pair<int, int>> st;
                    st.push(make_pair(i, j));

                    while (!st.empty()) {
                        pair<int, int> p = st.top();
                        st.pop();
                        grid[p.first][p.second] = 2;
                        for (int k = 0; k < 4; k++) {
                            int dx = p.first + directions[k];
                            int dy = p.second + directions[k + 1];
                            if (dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[dx].size()) {
                                if (grid[dx][dy] == 0) {
                                    q.push(make_pair(dx, dy));
                                } else if (grid[dx][dy] ==  1) {
                                    st.push(make_pair(dx, dy));
                                }
                            }
                        }
                    }
                    return;
                }
            }
        }
    }
};