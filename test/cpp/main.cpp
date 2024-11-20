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
    int longestValidParentheses(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
                } else {
                    int j = i - dp[i - 1] - 1;
                    if (j >= 0 && s[j] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (j >= 1) {
                            dp[i] += dp[j - 1];
                        }
                    }
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
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
    int res = s.longestValidParentheses("())");
    cout << res << endl;
//    for (int word : res) {
//        cout << to_string(word) << ", ";
//    }
//    cout << endl;
    
    return 0;
}

