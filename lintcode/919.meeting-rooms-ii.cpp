//  Tag: Heap, Greedy, Sweep Line, Sort
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: leetcode-253
//  Note: -

//  Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...] (si < ei)`, find the minimum number of conference rooms required.
//  
//  **Example1**
//  
//  ```
//  Input: intervals = [(0,30),(5,10),(15,20)]
//  Output: 2
//  Explanation:
//  We need two meeting rooms
//  room1: (0,30)
//  room2: (5,10),(15,20)
//  ```
//  
//  **Example2**
//  
//  ```
//  Input: intervals = [(2,7)]
//  Output: 1
//  Explanation: 
//  Only need one meeting room
//  ```
//  
//  (0,8),(8,10) is not conflict at 8

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
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        vector<pair<int, int>> meetings;
        for (auto x: intervals) {
            meetings.emplace_back(x.start, 1);
            meetings.emplace_back(x.end, -1);
        }

        int count = 0;
        int res = 0;
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < n; i++) {
            count += meetings[i].second;
            if (i == n - 1 || meetings[i].first != meetings[i + 1].first) { // second -1 comes first after sorting, this is not necessary
                res = max(res, count);
            }   
        }
        return res;
    }
};