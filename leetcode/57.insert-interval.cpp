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
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

        vector<Interval> res;
        int st = 0;
        for(; st < intervals.size(); ++st)
        {
            if (intervals[st].start < newInterval.start)
            {
                res.push_back(intervals[st]);
            }
            else
            {
                break;
            }
        }

        if (res.size() != 0 && res.back().end >= newInterval.start)
        {
            res.back().end = max(res.back().end, newInterval.end);
        }
        else
        {
            res.push_back(newInterval);
        }

        for (int i = st ; i < intervals.size(); ++i)
        {
            if (res.back().end >= intervals[i].start)
            {
                res.back().end = max(res.back().end, intervals[i].end);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
