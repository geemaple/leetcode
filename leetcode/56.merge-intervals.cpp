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

private:
    static bool cmp(Interval &left, Interval &right)
    {
        return left.start < right.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), cmp);

        vector<Interval> res;
        if (intervals.size() == 0)
        {
            return res;
        }

        int start = intervals[0].start;
        int end = intervals[0].end;
        for (auto i = 1; i < intervals.size(); ++i)
        {
            if (end >= intervals[i].start)
            {
                end = max(end, intervals[i].end);
            }
            else
            {
                Interval ans(start, end);
                res.push_back(ans);
                start = intervals[i].start;
                end = intervals[i].end;
            }   
        }

        Interval ans(start, end);
        res.push_back(ans);
        return res;
    }
};
