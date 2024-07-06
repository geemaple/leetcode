//  Tag: Array, String, Backtracking, Matrix
//  Time: O(MN*4^L)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  Given an m x n grid of characters board and a string word, return true if word exists in the grid.
//  The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
//   
//  Example 1:
//  
//  
//  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
//  Output: true
//  
//  Example 2:
//  
//  
//  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
//  Output: true
//  
//  Example 3:
//  
//  
//  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
//  Output: false
//  
//   
//  Constraints:
//  
//  m == board.length
//  n = board[i].length
//  1 <= m, n <= 6
//  1 <= word.length <= 15
//  board and word consists of only lowercase and uppercase English letters.
//  
//   
//  Follow up: Could you use search pruning to make your solution faster with a larger board?
//  

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int pos, int x, int y, vector<vector<bool>>& visited) {
        if (board[x][y] != word[pos]) {
            return false;
        }

        if (pos == word.size() - 1) {
            return true;
        }
        int directions[5] = {-1, 0, 1, 0, -1};
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int dx = x + directions[i];
            int dy = y + directions[i + 1];
            if (dx >= 0 && dx < board.size() && dy >= 0 && dy < board[dx].size() && !visited[dx][dy]) {
                if (dfs(board, word, pos + 1, dx, dy, visited)) {
                    return true;
                }
            }
        }
        visited[x][y] = false;
        return false;
    }
};