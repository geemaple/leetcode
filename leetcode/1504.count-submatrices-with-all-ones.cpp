//  Tag: Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
//  Time: O(MN)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/ZlmQt7M5HUg

//  Given an m x n binary matrix mat, return the number of submatrices that have all ones.
//   
//  Example 1:
//  
//  
//  Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
//  Output: 13
//  Explanation: 
//  There are 6 rectangles of side 1x1.
//  There are 2 rectangles of side 1x2.
//  There are 3 rectangles of side 2x1.
//  There is 1 rectangle of side 2x2. 
//  There is 1 rectangle of side 3x1.
//  Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
//  
//  Example 2:
//  
//  
//  Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
//  Output: 24
//  Explanation: 
//  There are 8 rectangles of side 1x1.
//  There are 5 rectangles of side 1x2.
//  There are 2 rectangles of side 1x3. 
//  There are 4 rectangles of side 2x1.
//  There are 2 rectangles of side 2x2. 
//  There are 2 rectangles of side 3x1. 
//  There is 1 rectangle of side 3x2. 
//  Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
//  
//   
//  Constraints:
//  
//  1 <= m, n <= 150
//  mat[i][j] is either 0 or 1.
//  
//  
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;
        vector<int> dp(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j] = mat[i][j] == 1 ? dp[j] + 1 : 0;
            }

            res += count(dp);
        }
        return res;
    }

    int count(vector<int> &dp) {
        int n = dp.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && dp[st.top()] >= dp[i]) {
                st.pop();
            }

            if (!st.empty()) {
                int pre = st.top();
                
                res[i] += res[pre];
                res[i] += dp[i] * (i - pre);
            } else {
                res[i] += dp[i] * (i + 1);
            }
            st.push(i);
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};  

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            vector<int> arr(n, 1);
            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    arr[k] &= mat[j][k];
                }

                res += count(arr);
            }
        }
        return res;
    }

    int count(vector<int> &arr) {
        int res = 0;
        int length = 0;
        for (int i = 0; i < arr.size(); i ++) {
            length = arr[i] == 0 ? 0 : length + 1;
            res += length;
        }
        return res;
    }
};  