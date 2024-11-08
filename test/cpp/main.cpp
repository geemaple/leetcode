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

#include <vector>
#include <string>

class Solution {
public:
    int countBalancedPermutations(string num) {
        long long mod = 1e9 + 7;
        vector<int> counter(10, 0);
        int total_sum = 0;
        for (char c : num) {
            total_sum += c - '0';
            ++counter[c - '0'];
        }
        
        if (total_sum % 2 == 1) {
            return 0;
        }

        int n = num.size();
        vector<vector<long long>> comb(n + 1, vector<long long>(n + 1, 0));
        comb[0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
            }
        }

        int balance = total_sum / 2;
        int even = n / 2;

        vector<vector<long long>> dp(1 + even, vector<long long>(1 + balance, 0));
        dp[0][0] = 1;
        
        int total = 0;
        for (int digit = 0; digit < 10; ++digit) {
            if (counter[digit] == 0) continue;
            vector<vector<long long>> prev = dp;
            fill(dp.begin(), dp.end(), vector<long long>(1 + balance, 0));
            int count = counter[digit];
            total += count;
            
            for (int b = 0; b <= balance; b++) {
                for (int e = 0; e <= even; e++) {
                    if (prev[e][b] == 0) continue;
                    
                    for (int k = 0; k <= count; ++k) {
                        if (b + digit * k > balance || e + k > even) break;
            
                        long long cur = (comb[k + e][k] * comb[total - k - e][count - k]) % mod;
                        cur = (cur * prev[e][b]) % mod;
                        dp[e + k][b + digit * k] = (dp[e + k][b + digit * k] + cur) % mod;
                    }
                }
            }
        }
        
        return dp[even][balance];
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0,1,1,0,0,0},
        {1,0,1,0,0,0},
        {0,1,1,1,0,1},
        {0,0,1,0,1,0}
    };
    
    
    
    vector<int> start = {1,2,3,3};
    vector<int> end = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    Solution s;
    int res = s.countBalancedPermutations("936743669957054147457096237781383667457517817480");
    cout << res << endl;
//    for (int word : res) {
//        cout << to_string(word) << ", ";
//    }
//    cout << endl;
    
    return 0;
}

