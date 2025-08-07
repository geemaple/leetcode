//  Tag: Array, Dynamic Programming, Bit Manipulation
//  Time: O(N^2)
//  Space: O(N^2)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/GkS3h6CU7Pk

//  Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
//  The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
//  A subarray is a contiguous non-empty sequence of elements within an array.
//   
//  Example 1:
//  
//  Input: arr = [0]
//  Output: 1
//  Explanation: There is only one possible result: 0.
//  
//  Example 2:
//  
//  Input: arr = [1,1,2]
//  Output: 3
//  Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
//  These yield the results 1, 1, 2, 1, 3, 3.
//  There are 3 unique values, so the answer is 3.
//  
//  Example 3:
//  
//  Input: arr = [1,2,4]
//  Output: 6
//  Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
//  
//   
//  Constraints:
//  
//  1 <= arr.length <= 5 * 104
//  0 <= arr[i] <= 109
//  
//  

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> res;
        unordered_set<int> cur;
        for (auto &i: arr) {
            unordered_set<int> tmp = {i};
            for (auto &j: cur) {
                tmp.insert(i | j);
            }
            cur = tmp;
            res.insert(cur.begin(), cur.end()); 
        }
        return res.size();
    }
};

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        int left = 0;
        int right = 0;
        for(int i = 0; i < n; i++) {
            res.push_back(arr[i]);
            for (int j = left; j < right; j++) {
                if (res.back() < (res[j] | arr[i])) {
                    res.push_back(res[j] | arr[i]);
                }
            }

            left = right;
            right = res.size();
        }

        return unordered_set<int>(begin(res), end(res)).size();
    }
};