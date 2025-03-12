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
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> prefix = {0};
        for (auto x: nums) {
            prefix.push_back(prefix.back() + x);
        }

        int l = 1;
        int r = n;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (fit(prefix, m, k)) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
    bool fit(vector<long long>& prefix, long long m, long long k) {
        int n = prefix.size() - 1;
        for (int i = 0; i <= n - m; i++) {
            if ((prefix[i + m] - prefix[i + m / 2]) - (prefix[i + (m + 1) / 2] - prefix[i]) <= k) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    std::string str = "aeioqq";
    
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
    vector<int> profit = {1,2,6,4};
    Solution s;
    int res = s.maxFrequencyScore(profit, 3);

    return 0;
}

