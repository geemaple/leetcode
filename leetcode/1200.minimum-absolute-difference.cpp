//  Tag: Array, Sorting
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
//  Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
//  
//  a, b are from arr
//  a < b
//  b - a equals to the minimum absolute difference of any two elements in arr
//  
//   
//  Example 1:
//  
//  Input: arr = [4,2,1,3]
//  Output: [[1,2],[2,3],[3,4]]
//  Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
//  Example 2:
//  
//  Input: arr = [1,3,6,10,15]
//  Output: [[1,3]]
//  
//  Example 3:
//  
//  Input: arr = [3,8,-10,23,19,-4,-14,27]
//  Output: [[-14,-10],[19,23],[23,27]]
//  
//   
//  Constraints:
//  
//  2 <= arr.length <= 105
//  -106 <= arr[i] <= 106
//  
//  

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
         int n = arr.size();
        sort(arr.begin(), arr.end());

        int min_diff = INT_MAX;
        vector<vector<int>> res;

        for (int i = 0; i < n - 1; i++) {
            int diff = arr[i + 1] - arr[i];

            if (diff < min_diff) {
                res.clear();
                min_diff = diff;
            }

            if (diff == min_diff) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }

        return res;
    }
};