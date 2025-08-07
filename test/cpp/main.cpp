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
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int child1 = 0;
        
        // Step 1: Calculate child1 and set the diagonal to 0
        for (int i = 0; i < n; ++i) {
            child1 += fruits[i][i];
            fruits[i][i] = 0;
        }
        
        // Step 2: Dynamic Programming for child2
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][n - 1] = fruits[0][n - 1];
        
        for (int i = 1; i < n; ++i) {
            for (int j = n - i - 1; j < n; ++j) {
                if (j == 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + fruits[i][j];
                } else if (j == n - 1) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + fruits[i][j];
                } else {
                    dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + fruits[i][j];
                }
            }
        }
        
        int child2 = dp[n - 1][n - 1];
        int j = n - 1;
        
        // Step 3: Trace back the path for child2
        for (int i = n - 1; i > 0; --i) {
            int val = fruits[i][j];
            fruits[i][j] = 0;
            if (j > 0 && dp[i - 1][j - 1] + val == dp[i][j]) {
                j = j - 1;
            } else if (j < n - 1 && dp[i - 1][j + 1] + val == dp[i][j]) {
                j = j + 1;
            }
        }
        
        // Step 4: Dynamic Programming for child3
        fill(dp.begin(), dp.end(), vector<int>(n, 0));
        dp[n - 1][0] = fruits[n - 1][0];
        
        for (int j = 1; j < n; ++j) {
            for (int i = n - j - 1; i < n; ++i) {
                if (i == 0) {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j - 1]) + fruits[i][j];
                } else if (i == n - 1) {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1]) + fruits[i][j];
                } else {
                    dp[i][j] = max({dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1]}) + fruits[i][j];
                }
            }
        }
        
        int child3 = dp[n - 1][n - 1];
        
        // Step 5: Return the final result
        return child1 + child2 + child3;
    }
};

int main() {
    std::string str = "aaba*";
    
    vector<int> nums = {1,5,5,4,11};
    
    vector<vector<int>> edges = {
        {0,1},{1,2},{1,3},{3,4}
    };
    
//    vector<vector<int>> edges = {
//        {0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}
//    };
    
    
//
//    
//    
//    vector<int> nums = {7,8,8,3,8,1,5,3,5,4};
//    vector<int> end = {3,4,5,6};
    vector<int> profit = {1,3,5,1};
    Solution s;
    int res = s.minimumScore(nums, edges);
    cout << res << endl;
    return 0;
}

