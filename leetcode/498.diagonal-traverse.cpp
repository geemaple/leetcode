//  Tag: Array, Matrix, Simulation
//  Time: O(NM)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/saqXlKaw0Qs

//  Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
//   
//  Example 1:
//  
//  
//  Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
//  Output: [1,2,4,7,5,3,6,8,9]
//  
//  Example 2:
//  
//  Input: mat = [[1,2],[3,4]]
//  Output: [1,2,3,4]
//  
//   
//  Constraints:
//  
//  m == mat.length
//  n == mat[i].length
//  1 <= m, n <= 104
//  1 <= m * n <= 104
//  -105 <= mat[i][j] <= 105
//  
//  

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<int> res;
        bool upwards = false;
        int i = 0;
        int j = 0;
        
        for (auto k = 0; k < m * n; ++k)
        {
            res.push_back(mat[i][j]);
            if ((i + j) % 2 == 0) { // up
                if(j == m - 1) {
                    i += 1;
                } else if (i == 0) {
                    j += 1;
                } else {
                    i -= 1;
                    j += 1;
                }
            }
            else {
                if(i == n - 1) {
                    j += 1;
                } else if (j == 0) {
                    i += 1;
                } else {
                    i += 1;
                    j -= 1;
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        bool up = true;
        vector<int> res;

        for (int k = 0; k < m + n - 1; ++k) {
            if (up) {
                for (int i = min(n - 1, k); i >= 0; --i) {
                    int j = k - i;
                    if (j < m) {
                        res.push_back(mat[i][j]);
                    } else {
                        break;
                    }
                }
            } else {
                for (int j = min(m - 1, k); j >= 0; --j) {
                    int i = k - j;
                    if (i < n) {
                        res.push_back(mat[i][j]);
                    } else {
                        break;
                    }
                }
            }
            
            up = !up;
        }
        
        return res;
    }
};

