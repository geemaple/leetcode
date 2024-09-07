//  Tag: Backtracking
//  Time: O(N!)
//  Space: O(N)
//  Ref: -
//  Note: -

//  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//  Given an integer n, return the number of distinct solutions to the n-queens puzzle.
//   
//  Example 1:
//  
//  
//  Input: n = 4
//  Output: 2
//  Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
//  
//  Example 2:
//  
//  Input: n = 1
//  Output: 1
//  
//   
//  Constraints:
//  
//  1 <= n <= 9
//  
//  

class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> dia;
        unordered_set<int> anti_dia;

        return helper(0, n, cols, dia, anti_dia);
    }

    int helper(int i, int n, unordered_set<int> &cols, unordered_set<int> &dia, unordered_set<int> &anti_dia) {
        if (i == n) {
            return 1;
        }

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (cols.count(j) || dia.count(i + j) || anti_dia.count(i - j)) {
                continue;
            }

            cols.insert(j);
            dia.insert(i + j);
            anti_dia.insert(i - j);

            count += helper(i + 1, n, cols, dia, anti_dia);
            cols.erase(j);
            dia.erase(i + j);
            anti_dia.erase(i - j);
        }

        return count;

    }
};

class Solution {
public:
    int res = 0;

    int totalNQueens(int n) {
        helper(n, 0, 0, 0, 0);
        return res;
    }

    void helper(int n, int row, int cols, int rd, int ld) {
        // 如果当前行等于 n，说明已经成功放置了 n 个皇后
        if (row == n) {
            res += 1;
            return;
        }

        // (cols | rd | ld) 三个方向取或，0就是没有占用的位置
        // 〜取反，1就是没有占用的位置, 但是32位的头部0也会变成1
        // 所以, ((1 << n) - 1) 只有后这些位置是有意义的。
        int candidate = ~(cols | rd | ld) & ((1 << n) - 1);
        
        while (candidate > 0) {
            // 得到末尾的1(负数的表示正数取反+1), 获得放置位置
            int p = candidate & -candidate;

            // 往下递归时，列垂直向下, ↖️↘️往右移一位, ↙️↗️往左移一位
            helper(n, row + 1, cols | p, (rd | p) >> 1, (ld | p) << 1);
            
            // 消掉末尾的1
            candidate &= candidate - 1;
        }
    }
};