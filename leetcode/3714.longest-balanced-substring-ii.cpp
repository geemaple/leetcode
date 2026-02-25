//  Tag: Hash Table, String, Prefix Sum
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  You are given a string s consisting only of the characters 'a', 'b', and 'c'.
//  A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
//  Return the length of the longest balanced substring of s.
//   
//  Example 1:
//  
//  Input: s = "abbac"
//  Output: 4
//  Explanation:
//  The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
//  
//  Example 2:
//  
//  Input: s = "aabcc"
//  Output: 3
//  Explanation:
//  The longest balanced substring is "abc" because all distinct characters 'a', 'b' and 'c' each appear exactly 1 time.
//  
//  Example 3:
//  
//  Input: s = "aba"
//  Output: 2
//  Explanation:
//  One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s contains only the characters 'a', 'b', and 'c'.
//  
//  

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;  // 至少一个字符一定是平衡的

        // -----------------------------
        // Case 1: 单字符连续段
        // -----------------------------
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            ans = max(ans, j - i);
            i = j;
        }

        // -----------------------------
        // Case 2: 恰好 2 个字符
        // -----------------------------
        auto longest_two = [&](char c1, char c2) {
            int diff = 0;
            unordered_map<int, int> first;
            first[0] = -1;
            int best = 0;

            for (int i = 0; i < n; i++) {
                char ch = s[i];

                if (ch == c1) {
                    diff++;
                } else if (ch == c2) {
                    diff--;
                } else {
                    // 第三个字符打断
                    diff = 0;
                    first.clear();
                    first[0] = i;
                    continue;
                }

                if (first.count(diff)) {
                    best = max(best, i - first[diff]);
                } else {
                    first[diff] = i;
                }
            }
            return best;
        };

        ans = max(ans, longest_two('a', 'b'));
        ans = max(ans, longest_two('a', 'c'));
        ans = max(ans, longest_two('b', 'c'));

        // -----------------------------
        // Case 3: 三个字符
        // -----------------------------
        int cntA = 0, cntB = 0, cntC = 0;
        map<pair<int,int>, int> mp;
        mp[{0, 0}] = -1;
        int best = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'a') cntA++;
            else if (ch == 'b') cntB++;
            else cntC++;

            pair<int,int> key = {cntA - cntB, cntA - cntC};

            if (mp.count(key)) {
                best = max(best, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return max(ans, best);
    }
};