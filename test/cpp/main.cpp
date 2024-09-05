#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, unordered_set<int>> indexes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                indexes[grid[i][j]].insert(i);
            }
        }

        vector<int> dp(1 << n, 0);
        for (auto &[v, index] : indexes) {
            vector<int> ndp = dp;
            for (int i = 1; i < (1 << n); i++) {
                for (auto j: index) {
                    if (i >> j & 1) {
                        ndp[i] = max(ndp[i], dp[i ^ (1 << j)] + v);
                    }
                }
            }
            dp = ndp;
        }

        return dp[(1 << n) - 1];
    }
};

int main() {
    vector<vector<int>> f = {{8,7,6},{8,3,2}};
    Solution s;
    cout << "Longest Palindromic Substring: " << s.maxScore(f) << endl;
    return 0;
}

