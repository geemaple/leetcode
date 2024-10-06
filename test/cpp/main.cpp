#include <iostream>
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
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int, greater<int>> max_set;
        multiset<int, less<int>> min_set;
        vector<double> res;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                if (max_set.count(nums[i - k]) > 0) {
                    max_set.erase(max_set.find(nums[i - k]));
                } else {
                    min_set.erase(min_set.find(nums[i - k]));
                }
            }

            max_set.insert(nums[i]);
            min_set.insert(*max_set.begin());
            max_set.erase(max_set.begin());
            if (max_set.size() < min_set.size()) {
                max_set.insert(*min_set.begin());
                min_set.erase(min_set.begin());
            }

            if (i >= k - 1) {
                if (k & 1) {
                    res.push_back((double)*max_set.begin());
                } else {
                    res.push_back(((double)*max_set.begin() + (double)*min_set.begin()) / 2.0);
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> graph= {1,3,-1,-3,5,3,6,7};
    
    vector<int> nums1 = {-3,-1,2,4,5};
    vector<int> nums2 = {-3,-1,2,4,5};
    Solution s;
    vector<double> res = s.medianSlidingWindow(graph, 3);
//    cout << res << endl;
    for (auto word : res) {
        cout << word << ", ";
    }
    cout << endl;
    
    return 0;
}

