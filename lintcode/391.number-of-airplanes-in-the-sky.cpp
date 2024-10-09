//  Tag: Sweep Line
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an list `interval`,  which are taking off and landing time of the flight.
//  How many airplanes are there at most at the same time in the sky?
//  
//  **Example 1:**
//  
//  ```
//  Input: [(1, 10), (2, 3), (5, 8), (4, 7)]
//  Output: 3
//  Explanation:
//  The first airplane takes off at 1 and lands at 10.
//  The second ariplane takes off at 2 and lands at 3.
//  The third ariplane takes off at 5 and lands at 8.
//  The forth ariplane takes off at 4 and lands at 7.
//  During 5 to 6, there are three airplanes in the sky.
//  ```
//  
//  **Example 2:**
//  
//  ```
//  Input: [(1, 2), (2, 3), (3, 4)]
//  Output: 1
//  Explanation: Landing happen before taking off.
//  ```
//  
//  If landing and taking off of different planes happen at the same time, we consider landing should happen at first.

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
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<pair<int, int>> times;
        for (auto x: airplanes) {
            times.emplace_back(x.start, 1);
            times.emplace_back(x.end, -1);
        }
        sort(times.begin(), times.end());
        int count = 0;
        int res = 0;
        for (auto p: times) {
            count += p.second;
            res = max(res, count);
        }
        return res;
    }
};