//  Tag: Array, Hash Table, Backtracking, Matrix
//  Time: O(N^(N^2))
//  Space: O(N)
//  Ref: -
//  Note: -

//  Write a program to solve a Sudoku puzzle by filling the empty cells.
//  A sudoku solution must satisfy all of the following rules:
//  
//  Each of the digits 1-9 must occur exactly once in each row.
//  Each of the digits 1-9 must occur exactly once in each column.
//  Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//  
//  The '.' character indicates empty cells.
//   
//  Example 1:
//  
//  
//  Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
//  Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
//  Explanation: The input board is shown above and the only valid solution is shown below:
//  
//  
//  
//   
//  Constraints:
//  
//  board.length == 9
//  board[i].length == 9
//  board[i][j] is a digit or '.'.
//  It is guaranteed that the input board has only one solution.
//  
//  

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<bool>> row(n, vector(n + 1, false));
        vector<vector<bool>> col(n, vector(n + 1, false));
        vector<vector<bool>> zone(n, vector(n + 1, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '0';
                int k = i / 3 * 3 + j / 3;
                row[i][num] = col[j][num] = zone[k][num] = true;
            }
        }
        
        dfs(board, row, col, zone);
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& zone) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    int k = i / 3 * 3 + j / 3;
                    for (int num = 1; num <= 9; num++) {
                        if (row[i][num] || col[j][num] || zone[k][num]) {
                            continue;
                        }

                        row[i][num] = col[j][num] = zone[k][num] = true;
                        board[i][j] = num + '0';
                        if (dfs(board, row, col, zone)) {
                            return true;
                        }
                        board[i][j] = '.';
                        row[i][num] = col[j][num] = zone[k][num] = false;
                    }
                    return false;
                }
            }
        }
        return true;
    }
};