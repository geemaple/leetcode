class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if (s.size() != t.size())
        {
            return false;
        }

        vector<int> leftToRight(256, 0);
        vector<int> rightToLeft(256, 0);

        for (auto i = 0; i < s.size(); ++i)
        {

            if (leftToRight[s[i]] == 0)
            {
                leftToRight[s[i]] = t[i];
            }
            else if(leftToRight[s[i]] != t[i])
            {
                return false;
            }

            if (rightToLeft[t[i]] == 0)
            {
                rightToLeft[t[i]] = s[i];
            }
            else if(rightToLeft[t[i]] != s[i])
            {
                return false;
            }
        }

        return true;
    }
};
