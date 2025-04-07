//  Tag: Sweep Line
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: Leetcode-759
//  Note: -

//  We are given a list `schedule` of employees, which represents the working time for each employee.
//  
//  Each employee has a list of non-overlapping `Intervals`, and these intervals are in sorted order.
//  
//  Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.
//  
//  The `Intervals` is an 1d-array.
//  Each two numbers shows an interval.
//  For example, `[1,2,8,10]` represents that the employee works in `[1,2]` and `[8,10]`.
//  
//  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
//  
//  **Example 1:**
//  ```
//  Input：schedule = [[1,2,5,6],[1,3],[4,10]]
//  Output：[(3,4)]
//  Explanation:
//  There are a total of three employees, and all common
//  free time intervals would be [-inf, 1], [3, 4], [10, inf].
//  We discard any intervals that contain inf as they aren't finite.
//  ```
//  
//  
//  **Example 2:**
//  ```
//  Input：schedule = [[1,3,6,7],[2,4],[2,5,9,12]]
//  Output：[(5,6),(7,9)]
//  Explanation：
//  There are a total of three employees, and all common
//  free time intervals would be [-inf, 1], [5, 6], [7, 9],[12,inf].
//  We discard any intervals that contain inf as they aren't finite.
//  ```
//  
//  1.schedule and schedule[i] are lists with lengths in range [1, 100].
//  2.0 <= schedule[i].start < schedule[i].end <= 10^8.

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param schedule: a list schedule of employees
     * @return: Return a list of finite intervals 
     */
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {
        // Write your code here
        vector<pair<int, string>> works;
        for (auto &s: schedule) {
            for (int i = 0; i < s.size(); i+=2) {
                works.emplace_back(s[i], "start");
                works.emplace_back(s[i + 1], "end");
            }
        }

        sort(works.begin(), works.end());
        int count = 0;
        vector<Interval> res;
        int low = INT_MAX;

        for (int i = 0; i < works.size(); i++) {
            if (works[i].second == "start") {
                count += 1;
                if (count == 1 && low < works[i].first) {
                    res.push_back(Interval(low, works[i].first));
                }
            } else {
                count -= 1;
                if (count == 0) {
                    low = works[i].first;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param schedule: a list schedule of employees
     * @return: Return a list of finite intervals 
     */
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {
        // Write your code here
        vector<pair<int, int>> works;
        for (auto &s: schedule) {
            for (int i = 0; i < s.size(); i+=2) {
                works.emplace_back(s[i], s[i + 1]);
            }
        }

        sort(works.begin(), works.end());
        vector<pair<int, int>> merge;

        for (auto p: works) {
            if (merge.empty() || merge.back().second < p.first) {
                merge.push_back(p);
            } else {
                merge.back().second = max(merge.back().second, p.second);
            }
        }

        vector<Interval> res;
        for (int i = 1; i < merge.size(); i++) {
            res.push_back(Interval(merge[i - 1].second, merge[i].first));
        }

        return res;
    }
};

class Solution {
public:
    /**
     * @param schedule: a list schedule of employees
     * @return: Return a list of finite intervals 
     */
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {
        // Write your code here
        map<int, int> line;

        for (int i = 0; i < schedule.size(); ++i) {
            for (int j = 0; j < schedule[i].size(); j += 2) {
                line[schedule[i][j]] += i + 1;
                line[schedule[i][j + 1]] -= i + 1;
            }
        }

        int prefix = 0;
        int start = -1;
        vector<Interval> res;

        for (const auto& [t, val] : line) {
            if (prefix == 0 && start != -1) {
                res.emplace_back(start, t);
                start = -1;
            }

            prefix += val;
            if (prefix == 0 && start == -1) {
                start = t;
            }
        }

        return res;
    }
};