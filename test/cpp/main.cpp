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

int comb[10001][14] = {1};
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        int k = min(n, 14);
        int mod = 1e9 + 7;
        unordered_map<int, vector<int>> divisors;
        for (int i = 1; i <= maxValue; i++) {
            for (int j = 2 * i; j <= maxValue; j += i) {
                divisors[j].push_back(i);
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(maxValue + 1, 0));
        for (int i = 1; i <= maxValue; i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= k; i++) {
            for (int j = 1; j <= maxValue; j++) {
                for (auto d: divisors[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][d]) % mod;
                }
            }
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= maxValue; j++) {
                dp[i][0] = (dp[i][0] + dp[i][j]) % mod;
            }
        }

        if (comb[1][1] == 0) {
            for (int i = 1; i <= 10001; i++) {
                for (int j = 0; j < 14; j ++) {
                    
                    comb[i][j] = j == 0 ? 1 : (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= k; i++) {
            if (dp[i][0] > 0) {
                res = (res + 1LL * comb[n - 1][i - 1] * dp[i][0]) % mod;
            }
        }

        return res;
    }
};

int main() {
    std::string str = "aeioqq";
    
    vector<vector<int>> matrix = {
        {1,2,3},{2,5,7},{3,5,1}
    };
//    
//    
//    
//    vector<int> nums = {7,8,8,3,8,1,5,3,5,4};
//    vector<int> end = {3,4,5,6};
    vector<int> profit = {1,3,5,1};
    Solution s;
    int res = s.idealArrays(5878, 2900);
    cout << res << endl;
    return 0;
}

