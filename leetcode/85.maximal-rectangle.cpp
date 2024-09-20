//  Tag: Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
//  Time: O(NM)
//  Space: O(M)
//  Ref: -
//  Note: Based On 84

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