//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(K)
//  Ref: -
//  Note: -

//  Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//  An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
//   
//  Example 1:
//  
//  Input: s = "cbaebabacd", p = "abc"
//  Output: [0,6]
//  Explanation:
//  The substring with start index = 0 is "cba", which is an anagram of "abc".
//  The substring with start index = 6 is "bac", which is an anagram of "abc".
//  
//  Example 2:
//  
//  Input: s = "abab", p = "ab"
//  Output: [0,1,2]
//  Explanation:
//  The substring with start index = 0 is "ab", which is an anagram of "ab".
//  The substring with start index = 1 is "ba", which is an anagram of "ab".
//  The substring with start index = 2 is "ab", which is an anagram of "ab".
//  
//   
//  Constraints:
//  
//  1 <= s.length, p.length <= 3 * 104
//  s and p consist of lowercase English letters.
//  
//  

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        unordered_map<char, int> counter;
        for (auto ch: p) {
            counter[ch] += 1;
        }
        int hit = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                if (counter.count(s[i - k]) > 0) {
                    counter[s[i - k]] += 1;
                    if (counter[s[i - k]] >= 1) {
                        hit -= 1;
                    }
                }
            }


            if (counter.count(s[i]) > 0) {
                counter[s[i]]--;
                if (counter[s[i]] >= 0) {
                    hit += 1;
                }
            }

            if (i >= k - 1) {
                if (hit == k) {
                    res.push_back(i - k + 1);
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        unordered_map<char, int> counter;
        for (char &c : p) {
            counter[c]++;
        }

        int count = 0;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (counter.find(s[i]) != counter.end()) {
                counter[s[i]]--;
                if (counter[s[i]] >= 0) {
                    count++;
                }
            }

            if (i >= k - 1) {
                if (count == k) {
                    res.push_back(i - k + 1);
                }

                char left = s[i - k + 1];
                if (counter.find(left) != counter.end()) {
                    counter[left]++;
                    if (counter[left] > 0) {
                        count--;
                    }
                }
            }
        }

        return res;
    }
};