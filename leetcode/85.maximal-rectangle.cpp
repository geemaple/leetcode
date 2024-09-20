//  Tag: Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
//  Time: O(NM)
//  Space: O(M)
//  Ref: -
//  Note: -

//  Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//   
//  Example 1:
//  
//  
//  Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//  Output: 6
//  Explanation: The maximal rectangle is shown in the above picture.
//  
//  Example 2:
//  
//  Input: matrix = [["0"]]
//  Output: 0
//  
//  Example 3:
//  
//  Input: matrix = [["1"]]
//  Output: 1
//  
//   
//  Constraints:
//  
//  rows == matrix.length
//  cols == matrix[i].length
//  1 <= row, cols <= 200
//  matrix[i][j] is '0' or '1'.
//  
//  

// Based On 84
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m + 1, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    dp[j] += 1;
                } else {
                    dp[j] = 0;
                }
            }
            res = max(res, cal(dp));
        }

        return res;
    }

    int cal(vector<int> &dp) {
        int res = 0;
        stack<int> st;
        for (int i = 0; i < dp.size(); i++) {
            while (!st.empty() && dp[i] < dp[st.top()]) {
                int height = dp[st.top()];
                st.pop();
                int left = st.empty() ? 0 : st.top() + 1;
                res = max(res, (i - left) * height);
            }
            st.push(i);
        }
        return res;
    }
};

// 3 dp
class Solution {public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            int cur_left = 0;
            int cur_right = n;
            
            // height dp
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]=='1'){
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }
            
            // left dp
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]=='1') {
                    left[j] = max(left[j], cur_left);
                } else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            // right dp
            for (int j = n-1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            // area
            for (int j = 0; j < n; j++) {
                res = max(res,(right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};