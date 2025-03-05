//  Tag: Mathmatics
//  Time: O(NMK)
//  Space: O(NM)
//  Ref: Leetcode-311
//  Note: -

//  Given two [Sparse Matrix](https://en.wikipedia.org/wiki/Sparse_matrix "Sparse Matrix") A and B, return the result of AB.
//  
//  You may assume that A's column number is equal to B's row number.
//  
//  **Example1**
//  ```
//  Input: 
//  [[1,0,0],[-1,0,3]]
//  [[7,0,0],[0,0,0],[0,0,1]]
//  Output:
//  [[7,0,0],[-7,0,3]]
//  Explanation:
//  A = [
//    [ 1, 0, 0],
//    [-1, 0, 3]
//  ]
//  
//  B = [
//    [ 7, 0, 0 ],
//    [ 0, 0, 0 ],
//    [ 0, 0, 1 ]
//  ]
//  
//  
//       |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
//  AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                    | 0 0 1 |
//  ```
//  **Example2**
//  ```
//  Input:
//  [[1,0],[0,1]]
//  [[0,1],[1,0]]
//  Output:
//  [[0,1],[1,0]]
//  ```
//  
//  

class Solution {
public:
    /**
     * @param a: a sparse matrix
     * @param b: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
        // write your code here
        int n = a.size();
        int k = b.size();
        int m = b[0].size();

        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int d = 0; d < k; d++) {
                    res[i][j] += a[i][d] * b[d][j];
                }

            }
        }

        return res;

    }
};

class Solution {
public:
    /**
     * @param a: a sparse matrix
     * @param b: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
        // write your code here
        int n = a.size();
        int m = b[0].size();

        vector<vector<pair<int, int>>> sparseB(b.size(), vector<pair<int, int>>());
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] != 0) {
                    sparseB[i].emplace_back(j, b[i][j]);
                }
            }
        }

        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < a[i].size(); k++) {
                if (a[i][k] == 0) {
                    continue;
                }

                for (auto &[j, v]: sparseB[k]) {
                    res[i][j] += a[i][k] * v;
                }
            }
        }

        return res;

    }
};