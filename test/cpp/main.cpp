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
    /**
     * @param n: An integer
     * @return: a list of combination
     *          we will sort your return value in output
     */
    vector<vector<int>> getFactors(int n) {
        // write your code here
        vector<int> ans;
        vector<vector<int>> res;
        helper(2, n, ans, res);
        return res;
    }

    void helper(int start, int n, vector<int> &ans, vector<vector<int>> &res) {
        if (ans.size() > 0) {
            ans.push_back(n);
            res.push_back(ans);
            ans.pop_back();
        }

        for (int k = start; k < n; k++) {
            if (n / k < k) {
                break;
            }
            if (n % k == 0) {
                ans.push_back(k);
                helper(k, n / k, ans, res);
                ans.pop_back();
            }
        }

    }
};

int main() {
    std::string str = "Hello, World!";
    
//    vector<vector<int>> matrix = {
//        {0,1,1,0,0,0},
//        {1,0,1,0,0,0},
//        {0,1,1,1,0,1},
//        {0,0,1,0,1,0}
//    };
//    
//    
//    
//    vector<int> nums = {7,8,8,3,8,1,5,3,5,4};
//    vector<int> end = {3,4,5,6};
    vector<int> profit = {1, 3, 2};
    Solution s;
    string res = s.shortestCommonSupersequence("abac", "cab");

    return 0;
}

