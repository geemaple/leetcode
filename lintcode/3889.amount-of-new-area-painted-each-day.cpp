//  Tag: Segment Tree, Array, Line Sweep
//  Time: O(N + L)
//  Space: O(L)
//  Ref: Leetcode-2158
//  Note: -

//  There is a long, thin painting that can be represented by an array of numbers.
//  Given a two-dimensional array of integers $paint$ of length $n$ with subscripts starting at **0**, where $paint[i] = [start_i, end_i]$ means that the region between $start_i$ and $end_i$ needs to be painted on day $i$.
//  
//  Painting the same area multiple times will destroy the painting frame, **so each area can only be painted once.**
//  
//  Returns an integer array `worklog` of length `n`, where `worklog[i]` is the number of **new regions to be drawn on day `i`.**
//  
//  Example 1:
//  
//  ```
//  Input:
//  paint = [[1, 4], [4, 7], [5, 8]]
//  Output:
//  [3, 3, 1]
//  Explanation:
//  The figure below illustrates this:
//  On day 0, the content between 1 and 4 is plotted and the number of new areas is 3
//  On day 1, the content between 4 and 7 is plotted and the number of new areas is 3
//  On day 2, the content between 7 and 8 is plotted. The content between 5 and 7 was already plotted on day 1, so the number of new areas is 1
//  ```
//  
//  ![021901.png](https://media-cn.lintcode.com/new_storage_v2/public/202502/736cd225d9934629ba346086a97b7c3f/021901.png)
//  
//  Example 2:
//  
//  ```
//  Input:
//  paint = [[1, 4], [5, 8], [4, 7]]
//  Output:
//  [3, 3, 1]
//  Explanation:
//  The figure below illustrates this:
//  On day 0, the content between 1 and 4 is plotted and the number of new areas is 3
//  On day 1, the content between 5 and 8 is plotted and the number of new areas is 3
//  On day 2, the content between 4 and 5 is plotted. The content between 5 and 7 was already plotted on day 1, so the number of new areas is 1
//  ```
//  
//  ![021902.png](https://media-cn.lintcode.com/new_storage_v2/public/202502/8fa11f7dbd304ed69ae844f28f2707a1/021902.png)
//  
//  Example 3:
//  
//  ```
//  Input:
//  paint = [[1, 8], [1, 4], [5, 8]]
//  Output:
//  [7, 0, 0]
//  Explanation:
//  The figure below illustrates this:
//  On day 0, content between 1 and 8 is plotted and the number of new areas is 7
//  On day 1, the content between 1 and 4 was already plotted on day 0, so the number of new areas is 0
//  On day 2, the content between 5 and 8 was already plotted on day 0, so the number of new areas is 0
//  ```
//  
//  ![021903.png](https://media-cn.lintcode.com/new_storage_v2/public/202502/98576eb18f9d4f2980df73e8296cf29e/021903.png)
//  
//  - $ 1 \leq paint.length \leq 10^4$
//  - $paint[i].length == 2$
//  - $ 0 \leq start_i < end_i \leq 5 \times 10^4$

class Solution {
public:
    /**
     * @param paint: Areas plotted on each day
     * @return: New areas painted on each day
     */
    vector<int> amountPainted(vector<vector<int>> &paint) {
        // write your code here
        int n = paint.size();
        vector<int> line(50001, 0);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int start = paint[i][0];
            int end = paint[i][1];
            while (start < end) {
                int jump = max(start + 1, line[start]);
                res[i] += line[start] == 0 ? 1 : 0;
                line[start] = max(line[start], end);
                start = jump;
            }
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param paint: Areas plotted on each day
     * @return: New areas painted on each day
     */
    vector<int> amountPainted(vector<vector<int>> &paint) {
        // write your code here
        int n = paint.size();
        unordered_map<int, vector<pair<int, int>>> lines;
        int length = 0;
        for (int i = 0; i < n; i++) {
            lines[paint[i][0]].emplace_back(i, 1);
            lines[paint[i][1]].emplace_back(i, 0);
            length = max(length, paint[i][1]);
        }

        vector<int> res(n, 0);
        set<int> days;
        for (int i = 0; i <= length; i++) {
            for (auto &line : lines[i]) {
                if (line.second) {
                    days.insert(line.first);
                } else {
                    days.erase(line.first);
                }
            }

            if (!days.empty()) {
                res[*days.begin()] += 1;
            }
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param paint: Areas plotted on each day
     * @return: New areas painted on each day
     */
    vector<int> amountPainted(vector<vector<int>> &paint) {
        // write your code here
        map<int, int> m;
        vector<int> res;
        for (auto &p : paint) {
            int l = p[0];
            int r = p[1];
            auto next = m.upper_bound(l);
            auto cur = next;
            if (cur != begin(m) && prev(cur)->second >= l) {
                cur = prev(cur);
                l = cur->second;
            } else {
                cur = m.insert({l, r}).first;
            }

            int paint = r - l;
            while (next != end(m) && next->first < r) {
                paint -= min(r, next->second) - next->first;
                r = max(r, next->second);
                m.erase(next++);
            }
            cur->second = max(cur->second, r);
            res.push_back(max(0, paint));
        }

        return res;
    }
};