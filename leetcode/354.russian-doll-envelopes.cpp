// refer question 300
// O(N * LogN)
class Solution {
private:
    static bool sort_cmp(pair<int, int> &left, pair<int, int> &right)
    {
        // first asscending
        if (left.first < right.first) return true;
        if (left.first > right.first) return false;

        // second descending
        if (left.second > right.second) return true;
        if (left.second < right.second) return false;

        return false;
    }

public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) 
    {
        if (envelopes.size() == 0)
        {
            return 0;
        }

        sort(envelopes.begin(), envelopes.end(), sort_cmp);
        vector<int> table;
        for (auto i = 0; i < envelopes.size(); ++i)
        {
            auto it = lower_bound(table.begin(), table.end(), envelopes[i].second);
            if (it == table.end())
            {
                table.push_back(envelopes[i].second);
            }
            else
            {
                *it = envelopes[i].second;
            }

        }

        return table.size();
    }
};

// O(N ^ 2)
// f(i) = max(1, f(j) + 1 if j < i and envelopes[j] < envelopes[i]) 
class Solution2 {
private:
    static bool sort_cmp(pair<int, int> &left, pair<int, int> &right)
    {
        return (left.first < right.first);
    }

public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) 
    {
        if (envelopes.size() == 0)
        {
            return 0;
        }

        sort(envelopes.begin(), envelopes.end(), sort_cmp);
        int m = envelopes.size();
        vector<int> table(m, 0);
        table[0] = 1;

        for (auto i = 1; i < envelopes.size(); ++i)
        {
            int value = 1;
            for(auto j = 0; j < i; ++j)
            {
                if (envelopes[j].first != envelopes[i].first && envelopes[j].second < envelopes[i].second)
                {
                    value = max(value, table[j] + 1);
                }
            }
            table[i] = value;
        }

        return *max_element(table.begin(), table.end());
    }
};
