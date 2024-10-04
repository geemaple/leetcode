//  Tag: Array, Backtracking, Bitmask
//  Time: O(N!)
//  Space: O(N)
//  Ref: -
//  Note: -

//  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//  Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
//  Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
//   
//  Example 1:
//  
//  
//  Input: n = 4
//  Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//  Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
//  
//  Example 2:
//  
//  Input: n = 1
//  Output: [["Q"]]
//  
//   
//  Constraints:
//  
//  1 <= n <= 9
//  
//  

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        unordered_set<int> vertical;
        unordered_set<int> diagonal_plus;
        unordered_set<int> diagonal_minus;

        dfs(n, 0, tmp, res, vertical, diagonal_plus, diagonal_minus);

        return res;
    }

    void dfs(int n, int k, vector<string>& tmp, vector<vector<string>>& res, unordered_set<int>& vertical, unordered_set<int>& diagonal_plus, unordered_set<int>& diagonal_minus){
        if (n == k) {
            res.push_back(tmp);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (vertical.count(j) == 0 && diagonal_plus.count(k + j) == 0 && diagonal_minus.count(k - j) == 0){
                vertical.insert(j);
                diagonal_plus.insert(k + j);
                diagonal_minus.insert(k - j);
                tmp[k][j] = 'Q';
                dfs(n, k + 1, tmp, res, vertical, diagonal_plus, diagonal_minus);
                tmp[k][j] = '.';
                vertical.erase(j);
                diagonal_plus.erase(k + j);
                diagonal_minus.erase(k - j);
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ans;
        helper(n, 0, 0, 0, 0, ans, res);
        return res;
    }

private:
    void helper(int n, int row, int col, int left, int right, vector<string>& ans, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(ans);
            return;
        }

        int taken = col | left | right;
        int mask = ~taken & ((1 << n) - 1);

        while (mask > 0) {
            int pos = mask & (-mask);

            string tmp(n, '.');
            for (int j = 0; j < n; ++j) {
                if (1 << j == pos) {
                    tmp[j] = 'Q';
                    break;
                }
            }
            ans.push_back(tmp);

            helper(n, row + 1, col | pos, (left | pos) << 1, (right | pos) >> 1, ans, res);
            ans.pop_back();

            mask &= mask - 1;
        }
    }
};
