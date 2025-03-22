//  Tag: Sweep Line
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-1272
//  Note: -

//  The set of real numbers can be represented as a concatenation of a number of disjoint intervals, each of which is of the form `[a, b)`, denoting the set of all real numbers `x` that satisfy $a \le x < b$.
//  A real number `x` is said to be in the set if some interval `[a, b)` contains the real number `x`.
//  
//  Now you are given a **sorted** list of disjoint `intervals`, which represents a set of real numbers, where each item `intervals[i] = [ai, bi]` represents an interval $[a_i, b_i)$.
//  Then you are given an interval `toBeRemoved` to remove.
//  
//  You need to return **a set of real numbers** that represent the portions of `intervals` that have **deleted** `toBeRemoved`.
//  In other words, return the set of real numbers and satisfy that every real number `x` in the set is in `intervals` but not in `toBeRemoved`.
//  Your answer should be an **ordered** list of disjoint intervals as described above.
//  
//  **Example 1**
//  
//  Input
//  ```
//  intervals = [[0,2],[3,4],[5,7]]
//  toBeRemoved = [1,6]
//  ```
//  Output
//  ```
//  [[0,1],[6,7]]
//  ```
//  
//  **Example 2**
//  
//  Input
//  ```
//  intervals = [[0,5]]
//  toBeRemoved = [2,3]
//  ```
//  
//  Output
//  ```
//  [[0,2],[3,5]]
//  ```
//  
//  **Example 3**
//  
//  Input
//  ```
//  intervals = [[-5,-4],[-3,-2],[1,2],[3,5],[8,9]]
//  toBeRemoved = [-1,4]
//  ```
//  
//  Output
//  ```
//  [[-5,-4],[-3,-2],[4,5],[8,9]]
//  ```
//  
//  $1 \le intervals.length \le 104$
//  
//  $-10^9 \le a_i < b_i \le 10^9$

class Solution {
public:
    /**
     * @param intervals: A sorted list of disjoint intervals.
     * @param toBeRemoved: An interval to be removed.
     * @return: A set of real numbers.
     */
    vector<vector<int>> deleteInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved) {
        // --- write your code here ---
        vector<vector<int>> res;
        for (auto &interval: intervals) {
            int l = interval[0];
            int r = interval[1];

            if (l > toBeRemoved[1] || r < toBeRemoved[0]) {
                res.push_back({l, r});
            } else {
                if (l < toBeRemoved[0]) {
                    res.push_back({l, toBeRemoved[0]});
                }
                if (r > toBeRemoved[1]) {
                    res.push_back({toBeRemoved[1], r});
                }

            }
        }

        return res;
    }
};

class Solution {
public:
    /**
     * @param intervals: A sorted list of disjoint intervals.
     * @param toBeRemoved: An interval to be removed.
     * @return: A set of real numbers.
     */
    vector<vector<int>> deleteInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved) {
        // --- write your code here ---
        map<int, int> lines;
        for (auto &interval: intervals) {
            lines[interval[0]] += 1;
            lines[interval[1]] -= 1;
        }
        lines[toBeRemoved[0]] -= 1;
        lines[toBeRemoved[1]] += 1;

        int prefix = 0;
        vector<vector<int>> res;
        bool added = false;
        for (auto &[num, count]: lines) {
            prefix += count;
            if (prefix == 1) {
                res.push_back({num, num});
                added = true;
            }

            if (prefix == 0 && added) {
                res.back()[1] = num;
                added = false;
            }
        }

        return res;
    }
};