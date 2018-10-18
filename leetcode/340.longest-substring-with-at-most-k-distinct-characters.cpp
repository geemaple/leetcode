class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {

        if (s.size() == 0 || k <= 0)
        {
            return 0;
        }
        
        unordered_map<char, int> char_count;
        int res = 0;
        int i = 0;
        for (auto j = 0; j < s.size(); ++j)
        {
            char_count[s[j]] ++;
            while (char_count.size() > k)
            {
                char_count[s[i]] --;
                if (char_count[s[i]] == 0)
                {
                    char_count.erase(s[i]);
                }
        
                i ++;
            }
            
            res = max(res, j - i + 1);
        }
        
        return res;
    }
};