//  Tag: Array, Binary Search
//  Time: O(logA * NlogM)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/kw0qMFMjHhU

//  Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.
//   
//  Example 1:
//  
//  Input: nums1 = [2,5], nums2 = [3,4], k = 2
//  Output: 8
//  Explanation: The 2 smallest products are:
//  - nums1[0] * nums2[0] = 2 * 3 = 6
//  - nums1[0] * nums2[1] = 2 * 4 = 8
//  The 2nd smallest product is 8.
//  
//  Example 2:
//  
//  Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
//  Output: 0
//  Explanation: The 6 smallest products are:
//  - nums1[0] * nums2[1] = (-4) * 4 = -16
//  - nums1[0] * nums2[0] = (-4) * 2 = -8
//  - nums1[1] * nums2[1] = (-2) * 4 = -8
//  - nums1[1] * nums2[0] = (-2) * 2 = -4
//  - nums1[2] * nums2[0] = 0 * 2 = 0
//  - nums1[2] * nums2[1] = 0 * 4 = 0
//  The 6th smallest product is 0.
//  
//  Example 3:
//  
//  Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
//  Output: -6
//  Explanation: The 3 smallest products are:
//  - nums1[0] * nums2[4] = (-2) * 5 = -10
//  - nums1[0] * nums2[3] = (-2) * 4 = -8
//  - nums1[4] * nums2[0] = 2 * (-3) = -6
//  The 3rd smallest product is -6.
//  
//   
//  Constraints:
//  
//  1 <= nums1.length, nums2.length <= 5 * 104
//  -105 <= nums1[i], nums2[j] <= 105
//  1 <= k <= nums1.length * nums2.length
//  nums1 and nums2 are sorted.
//  
//  

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10;
        long long right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (count_less_equal(nums1, nums2, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    long long count_less_equal(vector<int>& nums1, vector<int>& nums2, long long target) {
        int n = nums1.size();
        int m = nums2.size();
        long long count = 0;
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