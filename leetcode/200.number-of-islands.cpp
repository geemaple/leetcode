//  Tag: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
//  Time: O(MN)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//  An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//   
//  Example 1:
//  
//  Input: grid = [
//    ["1","1","1","1","0"],
//    ["1","1","0","1","0"],
//    ["1","1","0","0","0"],
//    ["0","0","0","0","0"]
//  ]
//  Output: 1
//  
//  Example 2:
//  
//  Input: grid = [
//    ["1","1","0","0","0"],
//    ["1","1","0","0","0"],
//    ["0","0","1","0","0"],
//    ["0","0","0","1","1"]
//  ]
//  Output: 3
//  
//   
//  Constraints:
//  
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n <= 300
//  grid[i][j] is '0' or '1'.
//  
//  

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int directions[] = {-1, 0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';
                    count++;
                    while (!q.empty()) {
                        pair<int, int> coords = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int x = coords.first + directions[k];
                            int y = coords.second + directions[k + 1];
                            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1') {
                                grid[x][y] = '0';
                                q.push(make_pair(x, y));
                            }
                        }
                    }
                }
            }
        }   

        return count;
    }
};

class UnionFind {
public:
    vector<int> table;
    UnionFind(int n) {
        table.resize(n);
        for (int i = 0; i < n; i++) {
            table[i] = i;
        }
    }

    int find(int a) {
        if (a == table[a]) {
            return a;
        }

        table[a] = find(table[a]);
        return table[a];
    }

    bool connect(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            table[root_a] = root_b;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int directions[] = {-1, 0, 1, 0, -1};
        UnionFind uf = UnionFind(n * m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                }
            }
        }   

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    if (j + 1 < m && grid[i][j + 1] == '1' && uf.connect(i * m + j, i * m + j + 1)) {
                        count--;
                    }

                    if (i + 1 < n && grid[i + 1][j] == '1' && uf.connect(i * m + j, (i + 1) * m + j)) {
                        count--;
                    }
                }
            }
        }  

        return count;
    }
};