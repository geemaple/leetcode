/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    bool static cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first < b.first) {return true;}
        if (a.first > b.first) {return false;}
        
        return a.second < b.second;
    }
    
    
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        
        vector<pair<int, int>> times;
        for (auto i = 0; i < intervals.size(); ++i)
        {
            times.push_back(make_pair(intervals[i].start, 1));
            times.push_back(make_pair(intervals[i].end, -1));
        }
        
        sort(times.begin(), times.end(), cmp);
        
        int count = 0;
        int res = 0;
        for (auto i = 0; i < times.size(); ++i)
        {
            count += times[i].second;
            res = max(res, count);
        }
        
        return res;
    }
};