/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (28.77%)
 * Total Accepted:    644.1K
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
            
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        
        
        int start = 0;
        int end = m + 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            int left1 = mid - 1 >= 0 ? nums1[mid - 1] : INT_MIN;
            int right1 = mid < m ? nums1[mid]: INT_MAX;

            int rest = (m + n) / 2 - mid;
            int left2 = rest - 1 >= 0 ? nums2[rest - 1] : INT_MIN;
            int right2 = rest < n ? nums2[rest] : INT_MAX;


            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 1) {
                    return min(right1, right2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            } else if (left1 > right2) {
                end = mid;
            } else {
                start = mid + 1;
            }

        } 

        return 0.0;
    }
};


class Solution2 {
private:
    int kthNumber(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int kth){
        
        if (start1 >= nums1.size())
        {
            return nums2[start2 + kth - 1];
        }
        
        if (start2 >= nums2.size()){
            return nums1[start1 + kth - 1];
        }
        
        if (kth == 1)
        {
            return min(nums1[start1], nums2[start2]);
        }
        
        int left = INT_MAX;
        if (start1 + kth / 2 - 1 < nums1.size())
        {
            left = nums1[start1 + kth / 2 - 1];
        }
        
        int right = INT_MAX;
        if (start2 + kth / 2 - 1 < nums2.size())
        {
            right = nums2[start2 + kth / 2 - 1];
        }
        
        if (left < right){
            return kthNumber(nums1, start1 + kth / 2, nums2, start2, kth - kth / 2);
        }else{
            return kthNumber(nums1, start1, nums2, start2 + kth / 2, kth - kth / 2);
        }
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = nums1.size() + nums2.size();
        if (k % 2 == 0){
            return double(kthNumber(nums1, 0, nums2, 0, k / 2) + kthNumber(nums1, 0, nums2, 0, k / 2 + 1)) / 2.0;
        }else{
            return double(kthNumber(nums1, 0, nums2, 0, k / 2 + 1));
        }
    }
};