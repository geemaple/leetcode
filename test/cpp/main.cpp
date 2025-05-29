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
    int firstMissingPositive(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        int i = 1;
        while (i < nums.size()) {
            int j = nums[i];
            if (j > 0 && j < nums.size() && nums[i] != nums[j]) {
                swap(nums[i], nums[j]);
            } else {
                i += 1;
            }
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return nums.size();
    }
};

int main() {
    std::string str = "aeioqq";
    
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
    int res = s.firstMissingPositive(profit);
    cout << res << endl;
    return 0;
}

