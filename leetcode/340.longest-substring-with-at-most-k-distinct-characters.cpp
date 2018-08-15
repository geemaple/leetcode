class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        int ans = 0;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (map[s[i]]++ == 0)
            {
                count++;
            }

            while (count > k)
            {
                map[s[start]]--;
                if (map[s[start]] == 0)
                {
                    count--;
                }
                start++;
            }
            
            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};
