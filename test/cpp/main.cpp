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
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int x : nums) {
            k += x;
        }

        int ones = 0;
        int count = 0;
        for (int i = 0; i < n + k; i++) {
            if (i >= k) {
                count -= nums[i - k];
            }
            count += nums[i % n];
            if (i >= k - 1) {
                ones = max(ones, count);
            }
        }

        return k - ones;
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
    vector<int> profit = {0, 0, 0};
    Solution s;
    int res = s.minSwaps(profit);

    return 0;
}

