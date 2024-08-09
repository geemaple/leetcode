//  Tag: Two Pointers, String, String Matching
//  Time: O(M + N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//   
//  Example 1:
//  
//  Input: haystack = "sadbutsad", needle = "sad"
//  Output: 0
//  Explanation: "sad" occurs at index 0 and 6.
//  The first occurrence is at index 0, so we return 0.
//  
//  Example 2:
//  
//  Input: haystack = "leetcode", needle = "leeto"
//  Output: -1
//  Explanation: "leeto" did not occur in "leetcode", so we return -1.
//  
//   
//  Constraints:
//  
//  1 <= haystack.length, needle.length <= 104
//  haystack and needle consist of only lowercase English characters.
//  
//  

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int match_cout = 0;
        vector<int> dp = buildNext(needle);
        for (int i = 0; i < n; i++) {
            while (match_cout > 0 && haystack[i] != needle[match_cout]) {
                match_cout = dp[match_cout - 1];
            }

            if (haystack[i] == needle[match_cout]) {
                match_cout++;
            }

            if (match_cout == m) {
                return i - match_cout + 1;
            }

        }
        return -1;
    }

    vector<int> buildNext(string &text) {
        int n = text.size();
        vector<int> next(n, 0);
        int k = 0;
        for (int i = 1; i < n; i++) {
            while (k > 0 && text[k] != text[i]) {
                k = next[k - 1];
            }

            if (text[k] == text[i]) {
                k++;
            }

            next[i] = k;

        }

        return next;
    }
};