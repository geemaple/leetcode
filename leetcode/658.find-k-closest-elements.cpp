//  Tag: Array, Two Pointers, Binary Search, Sorting, Sliding Window, Heap (Priority Queue)
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
        int l = 0;
        int r = arr.size() - k;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (x - arr[mid] <= arr[mid + k] - x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return vector(arr.begin() + l, arr.begin() + l + k);
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - 1;

        while (r - l + 1 > k) {
            if (x - arr[l] <= arr[r] - x) {
                r -= 1;
            } else {
                l += 1;
            }
        }

        return vector(arr.begin() + l, arr.begin() + l + k);
    }
};