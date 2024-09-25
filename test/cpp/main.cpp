#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10;
        long long right = 1e10;
        while (left < right) {
            long long mid = (left + right) >> 1;
            if (count_less_equal(nums1, nums2, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int count_less_equal(vector<int>& nums1, vector<int>& nums2, long long target) {
        int n = nums1.size();
        int m = nums2.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] > 0) {
                auto it = upper_bound(nums2.begin(), nums2.end(), floor((double)target / nums1[i]));
                count += it - nums2.begin();
            } else if (nums1[i] < 0) {
                auto it = lower_bound(nums2.begin(), nums2.end(), ceil((double)target / nums1[i]));
                count += m - (it - nums2.begin());
            } else {
                count += target >= 0 ? m : 0;
            }
        }
        return count;
    }
};

int main() {
    vector<int> p1 = {3,2,4};
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<int> nums1 = {-3,-1,2,4,5};
    vector<int> nums2 = {-3,-1,2,4,5};
    Solution s;
    auto res = s.kthSmallestProduct(nums1, nums2, 3);
    cout << res << endl;
    //    for (auto &word : res) {
    //        cout << word << ', ';
    //    }
    //    cout << endl;
    
    return 0;
}

