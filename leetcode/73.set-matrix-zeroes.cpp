//  Tag: Array, Hash Table, Matrix
//  Time: O(NM)
//  Space: O(N + M)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/QEtneU-AKMw

//  Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
//  You must do it in place.
//   
//  Example 1:
//  
//  
//  Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
//  Output: [[1,0,1],[0,0,0],[1,0,1]]
//  
//  Example 2:
//  
//  
//  Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//  Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
//  
//   
//  Constraints:
//  
//  m == matrix.length
//  n == matrix[0].length
//  1 <= m, n <= 200
//  -231 <= matrix[i][j] <= 231 - 1
//  
//   
//  Follow up:
//  
//  A straightforward solution using O(mn) space is probably a bad idea.
//  A simple improvement uses O(m + n) space, but still not the best solution.
//  Could you devise a constant space solution?
//  
//  

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> rows;
        unordered_set<int> cols;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }   
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rows.count(i) > 0 || cols.count(j) > 0) {
                    matrix[i][j] = 0;
                }
            }   
        }
    }
};

// follow-up
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0_zero = false;

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                col0_zero = true;
            }

            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // use first row and cos as marking sets
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }   
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 1; j--) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }   

            if (col0_zero) {
                matrix[i][0] = 0;
            }
        }
    }
};