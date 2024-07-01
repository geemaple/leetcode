//  Tag: Array, Binary Search, Divide and Conquer
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//  The overall run time complexity should be O(log (m+n)).
//   
//  Example 1:
//  
//  Input: nums1 = [1,3], nums2 = [2]
//  Output: 2.00000
//  Explanation: merged array = [1,2,3] and median is 2.
//  
//  Example 2:
//  
//  Input: nums1 = [1,2], nums2 = [3,4]
//  Output: 2.50000
//  Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
//  
//   
//  Constraints:
//  
//  nums1.length == m
//  nums2.length == n
//  0 <= m <= 1000
//  0 <= n <= 1000
//  1 <= m + n <= 2000
//  -106 <= nums1[i], nums2[i] <= 106
//  
//  

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = nums1.size() + nums2.size();
        int i = 0;
        int j = 0;
        int pre = 0;
        int cur = 0;

        for (int r = 0; r <= k / 2; r++) {
            pre = cur;
            if (i < nums1.size() && j < nums2.size()) {
                if (nums1[i] >= nums2[j]) {
                    cur = nums2[j++];
                } else {
                    cur = nums1[i++];
                }
            } else if (i < nums1.size()) {
                cur = nums1[i++];
            } else {
                cur = nums2[j++];
            }
        }

        return k % 2 == 1 ? cur : (pre + cur) / 2.0;
    }
};