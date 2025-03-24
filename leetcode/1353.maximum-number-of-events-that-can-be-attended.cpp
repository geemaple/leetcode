//  Tag: Array, Greedy, Sorting, Heap (Priority Queue), Line Sweep
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
//  You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
//  Return the maximum number of events you can attend.
//   
//  Example 1:
//  
//  
//  Input: events = [[1,2],[2,3],[3,4]]
//  Output: 3
//  Explanation: You can attend all the three events.
//  One way to attend them all is as shown.
//  Attend the first event on day 1.
//  Attend the second event on day 2.
//  Attend the third event on day 3.
//  
//  Example 2:
//  
//  Input: events= [[1,2],[2,3],[3,4],[1,2]]
//  Output: 4
//  
//   
//  Constraints:
//  
//  1 <= events.length <= 105
//  events[i].length == 2
//  1 <= startDayi <= endDayi <= 105
//  
//  

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int i = 0;
        int res = 0;
        int cur = 0;
        priority_queue<int, vector<int>, greater<>> q;
        while (i < n || !q.empty()) {
            if (q.empty()) {
                cur = events[i][0];
            }

            while (i < n && events[i][0] <= cur) {
                q.push(events[i][1]);
                i += 1;
            }

            q.pop();
            res += 1;
            cur += 1;

            while (!q.empty() && q.top() < cur) {
                q.pop();
            }

        }
        return res;   
    }
};