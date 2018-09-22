class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mappings;
        mappings['I'] = 1;
        mappings['V'] = 5;
        mappings['X'] = 10;
        mappings['L'] = 50;
        mappings['C'] = 100;
        mappings['D'] = 500;
        mappings['M'] = 1000;

        int res = 0;
        for (auto i = 0; i < s.size(); ++i)
        {
            if (i + 1 < s.size() && mappings[s[i]] < mappings[s[i + 1]])
            {
                res += mappings[s[i + 1]] - mappings[s[i]];
                i++;
            }
            else
            {
                res += mappings[s[i]];
            }
        }

        return res;
    }
};
