//  Tag: Hash Table, String, Divide and Conquer, Bit Manipulation, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
//  Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
//   
//  Example 1:
//  
//  Input: s = "YazaAay"
//  Output: "aAa"
//  Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
//  "aAa" is the longest nice substring.
//  
//  Example 2:
//  
//  Input: s = "Bb"
//  Output: "Bb"
//  Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
//  
//  Example 3:
//  
//  Input: s = "c"
//  Output: ""
//  Explanation: There are no nice substrings.
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 100
//  s consists of uppercase and lowercase English letters.
//  
//  

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        if (n < 2) {
            return "";
        }

        unordered_set<char> alphabets(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            if (alphabets.count(tolower(s[i])) && alphabets.count(toupper(s[i]))) {
                continue;
            }
            string s1 = longestNiceSubstring(s.substr(0, i));
            string s2 = longestNiceSubstring(s.substr(i + 1));
            return s1.size() >= s2.size() ? s1: s2;
        }
        return s;
    }
};

class Solution {
public:
    string longestNiceSubstring(string s) {
        string res = "";
        for (int i = 1; i <= 26; i++) {
            string tmp = longestNiceSubstringWithUnique(s, i);
            if (tmp.size() > res.size()) {
                res = tmp;
            }
        }

        return res;
    }
    string longestNiceSubstringWithUnique(string &s, int k) {
        int n = s.size();
        unordered_set<char> alphabets(s.begin(), s.end());
        unordered_map<char, int> counter;
        int count = 0;
        string res = "";
        int i = 0;
        for (int j = 0; j < n; j++) {
            counter[s[j]] += 1;
            if (counter[s[j]] == 1) {
                char other = islower(s[j]) ? toupper(s[j]) : tolower(s[j]);
                if (counter.count(other) > 0) {
                    count += 1;
                }
            }

            while (counter.size() > 2 * k) {
                counter[s[i]] -= 1;
                if (counter[s[i]] == 0) {
                    char other = islower(s[i]) ? toupper(s[i]) : tolower(s[i]);
                    if (counter.count(other) > 0) {
                        count -= 1;
                    }
                    counter.erase(s[i]);
                }
                i += 1;
            }

            if (count == k && j - i + 1 > res.size()) {
                res = s.substr(i, j - i + 1);
            } 
        }

        return res;
    }
};