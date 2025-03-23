//  Tag: Array, Sorting
//  Time: O(NlogN)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
//  The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
//  Return the number of remaining intervals.
//   
//  Example 1:
//  
//  Input: intervals = [[1,4],[3,6],[2,8]]
//  Output: 2
//  Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
//  
//  Example 2:
//  
//  Input: intervals = [[1,4],[2,3]]
//  Output: 1
//  
//   
//  Constraints:
//  
//  1 <= intervals.length <= 1000
//  intervals[i].length == 2
//  0 <= li < ri <= 105
//  All the given intervals are unique.
//  
//  

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int right = 0;
        int res = 0;
        for (auto &inter: intervals) {
            res += inter[1] > right;
            right = max(right, inter[1]);
        }
        return res;
    }
};