#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

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

int main() {
    vector<int> p1 = {3,2,4};
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution s;
    auto res = s.maximalRectangle(matrix);
    cout << res << endl;
    //    for (auto &word : res) {
    //        cout << word << ', ';
    //    }
    //    cout << endl;
    
    return 0;
}

