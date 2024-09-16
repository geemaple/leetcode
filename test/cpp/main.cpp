#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int n = pages.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));
        
        for (int i = 0; i <= k; i++) {
            dp[i][0] = 0;
        }
        
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <=n; j++) {
                int work_load = 0;
                for (int p = j - 1; p >= 0; p--) {
                    work_load += pages[p];
                    int cost = max(dp[i - 1][p], work_load);
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[k][n];
    }
};

int main() {
    vector<int> p1 = {3,2,4};
    vector<string> words = {"oath","pea","eat","rain"};
    Solution s;
    auto res = s.copyBooks(p1, 2);
    cout << res << endl;
//    for (auto &word : res) {
//        cout << word << ", ";
//    }
//    cout << endl;

    return 0;
}

