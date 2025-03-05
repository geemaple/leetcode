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
     * @param a: a sparse matrix
     * @param b: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
        // write your code here
        int n = a.size();
        int m = b[0].size();

        vector<vector<pair<int, int>>> sparseB(b.size(), vector<pair<int, int>>());
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < m; j++) {
                if (!b[i][j]) {
                    sparseB[i].emplace_back(j, b[i][j]);
                }
            }
        }

        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < a[i].size(); k++) {
                if (a[i][k] == 0) {
                    continue;
                }

                for (auto &[j, v]: sparseB[k]) {
                    res[i][j] += a[i][k] * v;
                }
            }
        }

        return res;

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
    int res = s.takeCharacters("aabaaaacaabc", 2);

    return 0;
}

