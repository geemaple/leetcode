class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counting;
        for (auto c: s)
        {
            counting[c] += 1;
        }

        for (auto i = 0; i < s.size(); ++i)
        {
            if (counting[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};
