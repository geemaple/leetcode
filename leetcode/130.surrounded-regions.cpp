//  Tag: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
//  Time: O(MN)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
//  
//  Connect: A cell is connected to adjacent cells horizontally or vertically.
//  Region: To form a region connect every 'O' cell.
//  Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
//  
//  A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.
//   
//  Example 1:
//  
//  Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
//  Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//  Explanation:
//  
//  In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
//  
//  Example 2:
//  
//  Input: board = [["X"]]
//  Output: [["X"]]
//  
//   
//  Constraints:
//  
//  m == board.length
//  n == board[i].length
//  1 <= m, n <= 200
//  board[i][j] is 'X' or 'O'.
//  
//  

//  Tag: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
//  Time: O(MN)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
//  
//  Connect: A cell is connected to adjacent cells horizontally or vertically.
//  Region: To form a region connect every 'O' cell.
//  Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
//  
//  A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.
//   
//  Example 1:
//  
//  Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
//  Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//  Explanation:
//  
//  In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
//  
//  Example 2:
//  
//  Input: board = [["X"]]
//  Output: [["X"]]
//  
//   
//  Constraints:
//  
//  m == board.length
//  n == board[i].length
//  1 <= m, n <= 200
//  board[i][j] is 'X' or 'O'.
//  
//  

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
 
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') {
            return;
        }

        int directions[] = {-1, 0, 1, 0, -1};
        stack<pair<int, int>> st;
        st.push(make_pair(i, j));
        while (!st.empty()) {
            pair<int, int> p = st.top();
            st.pop();
            board[p.first][p.second] = 'T';

            for (int k = 0; k < 4; k++) {
                int dx = p.first + directions[k];
                int dy = p.second + directions[k + 1];
                if (dx >= 0 && dx < board.size() && dy >= 0 && dy < board[dx].size() && board[dx][dy] == 'O') {
                    st.push(make_pair(dx, dy));
                }
            }
        }
    }
};