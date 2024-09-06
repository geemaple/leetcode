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