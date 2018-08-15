class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() < s.size())
        {
            return "";
        }

        unordered_map<char, int> map;
        int missing = t.size();
        for(int i = 0; i < t.size(); ++i)
        {
            map[t[i]] += 1;
        }

        pair<int, int>ans = make_pair(0, INT_MAX);

        int i = 0;
        for(int j = 0; j < s.size(); ++j)
        {
            if (map.count(s[j]) > 0)
            {
                if (map[s[j]] > 0)
                {
                    missing--;
                }
                map[s[j]] -= 1;
            }

            while (missing == 0)
            {
                if (ans.second - ans.first > j - i + 1)
                {
                    ans = make_pair(i, j + 1);
                }

                // remove start
                if (map.count(s[i]) > 0)
                {
                    if (map[s[i]] == 0)
                    {
                        missing += 1;
                    }
                    map[s[i]] += 1;
                }
                i++;
            }
        }

        return (ans.second != INT_MAX)? s.substr(ans.first, ans.second - ans.first) : "";
    }
};
