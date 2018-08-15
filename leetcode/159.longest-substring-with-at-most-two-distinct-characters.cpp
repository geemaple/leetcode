class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        unordered_map<char, int> map;
        int count = 0;
        int start = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (map[s[i]]++ == 0)
            {
                count++;
            }

            while (count > 2)
            {
                map[s[start]]--;
                if (map[s[start++]] == 0)
                {
                    count--;
                }
            }

            ans = max(ans, i - start + 1);
        }    

        return ans;
    }
};
