//  Tag: Hash Table, String, Divide and Conquer, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
//  if no such substring exists, return 0.
//   
//  Example 1:
//  
//  Input: s = "aaabb", k = 3
//  Output: 3
//  Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
//  
//  Example 2:
//  
//  Input: s = "ababbc", k = 2
//  Output: 5
//  Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 104
//  s consists of only lowercase English letters.
//  1 <= k <= 105
//  
//  

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if (n == 0 || k > n) {
            return 0;
        }
        unordered_map<char, int> counter;
        for (auto x: s) {
            counter[x] += 1;
        }
        int i = 0;
        while (i < n && counter[s[i]] >= k) {
            i += 1;
        }

        if (i == n) {
            return n;
        }

        int res = 0;
        int pre = 0;
        while (i < n) {
            if (counter[s[i]] < k) {
                res = max(res, longestSubstring(s.substr(pre, i - pre), k));
                pre = i + 1;
            }
            i += 1;
        }

        if (i > pre) {
            res = max(res, longestSubstring(s.substr(pre, i - pre), k));
        }

        return res;
    }
};

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        for (int i = 1; i <= 26; i++) {
            res = max(res, longestSubstringWithUnique(s, k, i));
        }
        return res;
    }

    int longestSubstringWithUnique(string &s, int k, int target) {
        int n = s.size();
        int count = 0;
        unordered_map<char, int> counter;
        int res = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            counter[s[j]] += 1;
            if (counter[s[j]] == k) {
                count += 1;
            }
            
            while (counter.size() > target) {
                counter[s[i]] -= 1;
                if (counter[s[i]] == k - 1) {
                    count -= 1;
                }
                if (counter[s[i]] == 0) {
                    counter.erase(s[i]);
                }
                i += 1;
            }

            if (counter.size() == target && counter.size() == count) {
                res = max(res, j - i + 1);
            }
        }

        return res;
    }
};