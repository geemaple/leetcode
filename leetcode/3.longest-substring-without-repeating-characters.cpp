class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int j = 0;
        unordered_set<char> set;

        for(int i = 0; i < s.size(); ++i){
            while(j < s.size() && set.count(s[j]) == 0){
                set.insert(s[j++]);
            }

            res = max(res, j - i);

            set.erase(s[i]);
        }

        return res;
    }
};
