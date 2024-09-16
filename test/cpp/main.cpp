#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            expand(s, i, i, is_palindrome);
            expand(s, i, i + 1, is_palindrome);
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (is_palindrome[j][i - 1]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n] - 1;
    }

    void expand(string &s, int left, int right, vector<vector<bool>> &is_palindrome) {
        while (left >=0 && right < s.size() && s[left] == s[right]) {
            is_palindrome[left][right] = true;
            left--;
            right++;
        }
    }
};

int main() {
    vector<vector<int>> p1 = {{5,4},{6,4},{6,7},{2,3}};
    vector<string> words = {"oath","pea","eat","rain"};
    Solution s;
    auto res = s.maxEnvelopes(p1);
    cout << res << endl;
//    for (auto &word : res) {
//        cout << word << ", ";
//    }
//    cout << endl;

    return 0;
}

