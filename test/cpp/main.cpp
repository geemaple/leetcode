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
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == n) {
            return 0;
        }
        
        k = k - 1;
        vector<int> splits(n - 1, 0);
        for (int i = 0; i < n - 1; i++) {
            splits[i] = weights[i] + weights[i + 1];
        }

        long long diff = 0;
        nth_element(splits.begin(), splits.begin() + k, splits.end());
        for (int i = 0; i < k; i++) {
            diff -= splits[i];
        }

        nth_element(splits.begin(), splits.begin() + splits.size() - k + 1, splits.end());
        for (int i = 0; i < k; i++) {
            diff += splits[splits.size() - i - 1];
        }

        return diff;
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
    int res = s.putMarbles(profit, 2);

    return 0;
}

