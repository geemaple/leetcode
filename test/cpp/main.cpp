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
    int uniquePaths(int m, int n) {
        vector<vector<long long>> comb(n + m - 1, vector<long long>(n + m - 1, 0));
        comb[0][0] = 1;

        for (int i = 0; i <= n + m - 2; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= n - 1; j++) {
                comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            }
        }
    
        return comb[n + m - 2][n - 1];
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
    int res = s.uniquePaths(3, 7);
    cout << res << endl;
//    for (int word : res) {
//        cout << to_string(word) << ", ";
//    }
//    cout << endl;
    
    return 0;
}

