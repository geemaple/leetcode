//  Tag: Array, Greedy, Matrix
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given an n x n integer matrix. You can do the following operation any number of times:
//  
//  Choose any two adjacent elements of matrix and multiply each of them by -1.
//  
//  Two elements are considered adjacent if and only if they share a border.
//  Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
//   
//  Example 1:
//  
//  
//  Input: matrix = [[1,-1],[-1,1]]
//  Output: 4
//  Explanation: We can follow the following steps to reach sum equals 4:
//  - Multiply the 2 elements in the first row by -1.
//  - Multiply the 2 elements in the first column by -1.
//  
//  Example 2:
//  
//  
//  Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
//  Output: 16
//  Explanation: We can follow the following step to reach sum equals 16:
//  - Multiply the 2 last elements in the second row by -1.
//  
//   
//  Constraints:
//  
//  n == matrix.length == matrix[i].length
//  2 <= n <= 250
//  -105 <= matrix[i][j] <= 105
//  
//  

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int zeros = 0;
        int negs = 0;
        int small = INT_MAX;
        for (auto &row: matrix) {
            for (auto &x: row) {
                res += abs(x);
                small = min(small, abs(x));
                zeros += x == 0;
                negs += x < 0;
            }
        }

        return (zeros > 0 || negs % 2 == 0) ? res: res - 2 * small;
    }
};