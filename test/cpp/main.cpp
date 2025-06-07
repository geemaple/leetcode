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
    string clearStars(string s) {
        int n = s.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
        vector<bool> removed(n, false);

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                auto [small, index] = heap.top();
                heap.pop();
                removed[index] = true;
            } else {
                heap.emplace(-s[i], i);
            }
        }

        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*' && !removed[i]) {
                res += s[i];
            }
        }
        return res;
    }
};

int main() {
    std::string str = "aaba*";
    
    vector<vector<int>> matrix1 = {
        {0,1},{0,2},{2,3},{2,4}
    };
    
    vector<vector<int>> matrix2 = {
        {0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}
    };
    
    
//
//    
//    
//    vector<int> nums = {7,8,8,3,8,1,5,3,5,4};
//    vector<int> end = {3,4,5,6};
    vector<int> profit = {1,3,5,1};
    Solution s;
    string res = s.clearStars(str);
    cout << res << endl;
    return 0;
}

