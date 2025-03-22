//  Tag: Same Direction Two Pointers, Two Pointers, Sort, Line Sweep
//  Time: O(N + M)
//  Space: O(1)
//  Ref: Leetcode-1229
//  Note: -

//  Given the availability schedules `slots1` and `slots2` of two people, and the expected `duration` of the meeting, you are asked to schedule **the earliest and appropriate** meeting time in the interval for them.
//  
//  The format of an **availability schedules** is an ***Interval*** consisting of a `start` time and an `end` time, i.e., `(start, end)`, which means that it starts at `start` and ends at `end`.
//  
//  
//  If the required meeting time is not met, return to the interval `(-1, -1)`.
//  
//  **Example 1**
//  
//  Input
//  ```
//  slots1 = [(10,50),(60,120),(140,210)]
//  slots2 = [(0,15),(60,70)]
//  duration = 8
//  ```
//  
//  Output
//  ```
//  (60,68)
//  ```
//  
//  **Example 2**
//  
//  Input
//  ```
//  slots1 = [(10,50),(60,120),(140,210)]
//  slots2 = [(0,15),(60,70)]
//  duration = 12
//  ```
//  
//  Output
//  ```
//  (-1,-1)
//  ```
//  
//  $1 <= slots1.length, slots2.length <= 10^4$
//  
//  $slots1[i].length, slots2[i].length == 2$
//  
//  $slots1[i].start < slots1[i].end$
//  
//  $slots2[i].start < slots2[i].end$
//  
//  $0 <= slots1[i][j], slots2[i][j] <= 10^9$
//  
//  $1 <= duration <= 10^6$

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
     * @param slots1: The availability schedule of one.
     * @param slots2: The availability schedule of one.
     * @param duration: The expected duration of the meeting.
     * @return: The earliest and appropriate meeting time in the interval for them.
     */
    Interval earliestAppropriateDuration(vector<Interval> &slots1, vector<Interval> &slots2, int duration) {
        // --- write your code here ---
        int i = 0;
        int j = 0;
        while (i < slots1.size() && j < slots2.size()) {
            pair<int, int> p = make_pair(max(slots1[i].start, slots2[j].start), min(slots1[i].end, slots2[j].end));
            if (p.second - p.first >= duration) {
                return Interval(p.first, p.first + duration);
            }

            if (slots1[i].end < slots2[j].end) {
                i += 1;
            } else {
                j += 1;
            }
        }

        return Interval(-1, -1);
    }
};

class Solution {
public:
    /**
     * @param slots1: The availability schedule of one.
     * @param slots2: The availability schedule of one.
     * @param duration: The expected duration of the meeting.
     * @return: The earliest and appropriate meeting time in the interval for them.
     */
    Interval earliestAppropriateDuration(vector<Interval> &slots1, vector<Interval> &slots2, int duration) {
        // --- write your code here ---
        map<int, int> lines;
        for (auto &p: slots1) {
            lines[p.start] += 1;
            lines[p.end] -= 1;
        }

        for (auto &p: slots2) {
            lines[p.start] += 1;
            lines[p.end] -= 1;
        }

        int prefix = 0;
        int start = 0;
        bool begin = false;
        for (auto &[t, c]: lines) {
            prefix += c;
            if (prefix == 2) {
                begin = true;
                start = t;
            }

            if (prefix < 2 && begin) {
                if (t - start >= duration) {
                    return Interval(start, start + duration);
                }
                begin = false;
            }
        }

        return Interval(-1, -1);
    }
};