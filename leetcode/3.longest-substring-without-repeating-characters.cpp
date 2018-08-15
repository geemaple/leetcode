class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> set;
        int ans = 0;
        int i  = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            if (set.count(s[j]) > 0)
            {
                ans = max(ans, j - i);
                
                while(s[i] != s[j])
                {
                    set.erase(s[i]);
                    i++;
                }
                
                i++;
            }
            else
            {
                set.insert(s[j]);
            }
        }
        
        ans = max(ans, (int)set.size());
        
        return ans;
    }
};