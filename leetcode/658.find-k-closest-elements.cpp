//  Category: Array, Two Pointers, Binary Search, Sorting, Sliding Window, Heap (Priority Queue)
//  Time: O(Log(N - K))
//  Space: O(1)
//  Ref: -
//  Note: Range

//  Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
//  An integer a is closer to x than an integer b if:
//  
//  |a - x| < |b - x|, or
//  |a - x| == |b - x| and a < b
//  
//   
//  Example 1:
//  Input: arr = [1,2,3,4,5], k = 4, x = 3
//  Output: [1,2,3,4]
//  Example 2:
//  Input: arr = [1,2,3,4,5], k = 4, x = -1
//  Output: [1,2,3,4]
//  
//   
//  Constraints:
//  
//  1 <= k <= arr.length
//  1 <= arr.length <= 104
//  arr is sorted in ascending order.
//  -104 <= arr[i], x <= 104
//  
//  

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
        int end = arr.size() - k;

        while (start < end) {
            int mid = start + (end - start) / 2;
            int left = x - arr[mid];
            int right = arr[mid + k] - x;
            if (left <= right) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return vector(arr.begin() + start, arr.begin() + start + k);
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
        int end = arr.size() - 1;

        while (end - start + 1 > k) {
            int left = x - arr[start];
            int right = arr[end] - x;
            if (left <= right) {
                end --;
            } else {
                start ++;
            }
        }

        return vector(arr.begin() + start, arr.begin() + start + k);
    }
};