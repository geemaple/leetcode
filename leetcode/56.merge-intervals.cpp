//  Tag: Array, Sorting
//  Time: O(NlogN)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
//   
//  Example 1:
//  
//  Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//  Output: [[1,6],[8,10],[15,18]]
//  Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
//  
//  Example 2:
//  
//  Input: intervals = [[1,4],[4,5]]
//  Output: [[1,5]]
//  Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//  
//   
//  Constraints:
//  
//  1 <= intervals.length <= 104
//  intervals[i].length == 2
//  0 <= starti <= endi <= 104
//  
//  

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int low = intervals[0][0];
        int high = intervals[0][1];

        vector<vector<int>> res;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= high) {
                high = max(high, intervals[i][1]);
            } else {
                res.push_back({low, high});
                low = intervals[i][0];
                high = intervals[i][1];
            }
        }
        res.push_back({low, high});
        return res;
    }
};