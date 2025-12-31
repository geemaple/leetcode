//  Tag: Array, Binary Search, Depth-First Search, Breadth-First Search, Union Find, Matrix
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: UnionFind

//  There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
//  Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
//  You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
//  Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.
//   
//  Example 1:
//  
//  
//  Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
//  Output: 2
//  Explanation: The above image depicts how the matrix changes each day starting from day 0.
//  The last day where it is possible to cross from top to bottom is on day 2.
//  
//  Example 2:
//  
//  
//  Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
//  Output: 1
//  Explanation: The above image depicts how the matrix changes each day starting from day 0.
//  The last day where it is possible to cross from top to bottom is on day 1.
//  
//  Example 3:
//  
//  
//  Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
//  Output: 3
//  Explanation: The above image depicts how the matrix changes each day starting from day 0.
//  The last day where it is possible to cross from top to bottom is on day 3.
//  
//   
//  Constraints:
//  
//  2 <= row, col <= 2 * 104
//  4 <= row * col <= 2 * 104
//  cells.length == row * col
//  1 <= ri <= row
//  1 <= ci <= col
//  All the values of cells are unique.
//  
//  

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0;
        int r = cells.size() - 1;

        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(row, col, cells, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l + 1;
    }

private:
    bool check(int row, int col, vector<vector<int>>& cells, int k) {
        vector<vector<int>> matrix(row, vector<int>(col, 0));
        
        for (int i = 0; i <= k; ++i) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            matrix[x][y] = 1;
        }

        vector<int> directions = {-1, 0, 1, 0, -1};
        queue<pair<int,int>> q;
        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == 0) {
                q.emplace(0, j);
                matrix[0][j] = 2;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == row - 1) {
                return true;
            }

            for (int i = 0; i < 4; ++i) {
                int dx = x + directions[i];
                int dy = y + directions[i + 1];
                if (dx >= 0 && dx < row && dy >= 0 && dy < col && matrix[dx][dy] == 0) {
                    q.emplace(dx, dy);
                    matrix[dx][dy] = 2;
                }
            }
        }

        return false;
    }
};