#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int>&b){
            return (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]));
        });
        vector<int> res;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(res.begin(), res.end(), envelopes[i][1]);
            if (it == res.end()) {
                res.push_back(envelopes[i][1]);
            } else {
                *it = envelopes[i][1];
            }
        }

        return res.size();
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

