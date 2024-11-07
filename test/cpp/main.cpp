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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        vector<vector<int>> dp;
        dp.push_back({0, 0});
        for (auto &x : jobs) {
            auto p = upper_bound(dp.begin(), dp.end(), x[0], [](int target, vector<int> & a) {
                return target < a[0];
            });

            p = prev(p);
            if ((*p)[1] + x[2] > dp.back()[1]) {
                dp.push_back({x[1], (*p)[1] + x[2]});
            }
        }

        return dp.back()[1];
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
    int res = s.jobScheduling(start, end, profit);
    cout << res << endl;
//    for (int word : res) {
//        cout << std::to_string(word) << ", ";
//    }
//    cout << endl;
    
    return 0;
}

