//  Tag: Array, Sorting, Line Sweep
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/iLEeUsBBcZE

//  You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
//  Return the count of days when the employee is available for work but no meetings are scheduled.
//  Note: The meetings may overlap.
//   
//  Example 1:
//  
//  Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
//  Output: 2
//  Explanation:
//  There is no meeting scheduled on the 4th and 8th days.
//  
//  Example 2:
//  
//  Input: days = 5, meetings = [[2,4],[1,3]]
//  Output: 1
//  Explanation:
//  There is no meeting scheduled on the 5th day.
//  
//  Example 3:
//  
//  Input: days = 6, meetings = [[1,6]]
//  Output: 0
//  Explanation:
//  Meetings are scheduled for all working days.
//  
//   
//  Constraints:
//  
//  1 <= days <= 109
//  1 <= meetings.length <= 105
//  meetings[i].length == 2
//  1 <= meetings[i][0] <= meetings[i][1] <= days
//  
//  

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> lines;
        for (auto &m: meetings) {
            lines[m[0]] += 1;
            lines[m[1] + 1] -= 1;
        }

        int res = 0;
        int prefix = 0;
        int start = 0;
        for (auto &[day, count]: lines) {
            if (prefix == 0) {
                start = day;
            }

            prefix += count;

            if (prefix == 0) {
                res += day - start;
            }
        }

        return days - res;
    }
};

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int res = 0;
        int cur = 1;
        sort(meetings.begin(), meetings.end());
        for (auto &m : meetings) {
            res += max(0, m[0] - cur);
            cur = max(cur, m[1] + 1);
            if (cur > days) {
                break;
            }
        }

        return res + (days - cur + 1);
    }
};