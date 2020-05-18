/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (39.95%)
 * Total Accepted:    93.3K
 * Total Submissions: 232.1K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * Given a sorted array arr, two integers k and x, find the k closest elements
 * to x in the array. The result should also be sorted in ascending order. If
 * there is a tie, the smaller elements are always preferred.
 * 
 * 
 * Example 1:
 * Input: arr = [1,2,3,4,5], k = 4, x = 3
 * Output: [1,2,3,4]
 * Example 2:
 * Input: arr = [1,2,3,4,5], k = 4, x = -1
 * Output: [1,2,3,4]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * Absolute value of elements in the array and x will not exceed 10^4
 * 
 * 
 */

// Log(N - K)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int start = 0;
        int end = (int)arr.size() - k;

        while (start < end) {
            int mid = start + (end - start) / 2;

            int rightGap = arr[mid + k] - x;
            int leftGap = x - arr[mid];


            if (rightGap >= leftGap) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return vector(arr.begin() + start, arr.begin() + start + k);
    }
};

// O(N)
class Solution2 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int start = 0;
        int end = (int)arr.size() - 1;

        while (end - start + 1 > k) {
            int rightGap = arr[end] - x;
            int leftGap = x - arr[start];


            if (rightGap >= leftGap) {
                end -= 1;
            } else {
                start += 1;
            }
        }

        return vector(arr.begin() + start, arr.begin() + start + k);
    }
};
