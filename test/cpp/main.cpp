#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <set>

using namespace std;

class Solution {

public:

    /*

     * @param A: An integer matrix

     * @return: The index of the peak

     */

    vector<int> findPeakII(vector<vector<int>> &A) {

        int n = A.size();

        int m = A[0].size();

        //根据条件可以知道边界上是不可能为峰值的

        //所以起始边界从1开始，终止边界为n - 1和m - 1

        return find(A, 1, n - 2, 1, m - 2);

    }

private:

    vector<int> find(vector<vector<int>>& A, int up, int bottom, int left, int right) {

        int row_mid = up + (bottom - up) / 2;

        int col_mid = left + (right - left) / 2;

        

        int row = row_mid, col = col_mid;

        int mx = A[row_mid][col_mid];

        

        //在中心点所在列上找最大值

        for (int i = up; i <= bottom; i++) {

            if (A[i][col_mid] > mx) {

                mx = A[i][col_mid];

                row = i;

                col = col_mid;

            }

        }

        //在中心点所在行上找最大值

        for (int i = left; i <= right; i++) {

            if (A[row_mid][i] > mx) {

                mx = A[row_mid][i];

                row = row_mid;

                col = i;

            }

        }

        //比较四个方向上的相邻值，若小于相邻值则向该方向移动

        //否则即为峰值直接返回答案

        if (A[row - 1][col] > A[row][col]) {

            row -= 1;

        } else if (A[row + 1][col] > A[row][col]) {

            row += 1;

        } else if (A[row][col - 1] > A[row][col]) {

            col -= 1;

        } else if (A[row][col + 1] > A[row][col]) {

            col += 1;

        } else {

            return vector<int>{row, col};

        }

        //递归搜索比最大值大的相邻点所在的部分

        if (row >= up && row < row_mid && col >= left && col < col_mid) {

            return find(A, up, row_mid - 1, left, col_mid - 1);

        }else if (row >= up && row < row_mid && col > col_mid && col <= right) {

            return find(A, up, row_mid - 1, col_mid + 1, right);

        }else if (row > row_mid && row <= bottom && col >= left && col < col_mid) {

            return find(A, row_mid + 1, bottom, left, col_mid - 1);

        }else if (row > row_mid && row <= bottom && col > col_mid && col <= right) {

            return find(A, row_mid + 1, bottom, col_mid + 1, right);

        }
        
        return vector<int>{-1, -1};

    }

};


int main() {
    vector<vector<int>> matrix = {
        {0,  1,  0,  1,  0,  1,  0,  1,  0},
        {1,  2,  1, 99, 98, 22, 21, 20,  1},
        {0,  3,  2,  1,  2,  3,  4, 19,  0},
        {1,  4,  3,  2,  1,  2,  3, 18,  1},
        {0,  5,  4,  3,  2,  1,  2, 17,  0},
        {1,  6,  5,  4,  3,  2,  1, 16,  1},
        {0,  7,  6,  5,  4,  3,  2, 15,  0},
        {1,  8,  9, 10, 11, 12, 13, 14,  1},
        {0,  1,  0,  1,  0,  1,  0,  1,  0}
    };
    
    vector<int> nums1 = {-3,-1,2,4,5};
    vector<int> nums2 = {-3,-1,2,4,5};
    Solution s;
    vector<int> res = s.findPeakII(matrix);
    cout << matrix[res[0]][res[1]] << endl;
//    cout << res << endl;
//    for (int word : res) {
//        cout << std::to_string(word) << ", ";
//    }
//    cout << endl;
    
    return 0;
}

