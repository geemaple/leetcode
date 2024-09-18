#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                for (int j = 0; j <= n - l; j++) {
                    if (l == 1) {
                        dp[i][j][l] = (s1[i] == s2[j]);
                    } else {
                        for (int k = 1; k < l; k++) {
                            if (dp[i][j][k] && dp[i + k][j + k][l - k]) {
                                dp[i][j][l] = true;
                                break;
                            }

                            if (dp[i][j + l - k][k] && dp[i + k][j][l - k]) {
                                dp[i][j][l] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};

int main() {
    vector<int> p1 = {3,2,4};
    vector<string> words = {"oath","pea","eat","rain"};
    Solution s;
    auto res = s.isScramble("great", "rgeat");
    cout << res << endl;
//    for (auto &word : res) {
//        cout << word << ", ";
//    }
//    cout << endl;

    return 0;
}

