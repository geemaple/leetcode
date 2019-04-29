/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (49.83%)
 * Total Accepted:    327.6K
 * Total Submissions: 632.5K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
// O(N) 12ms array access is much faster
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int hash_count[26] = {0};
        
        if (s.size() != t.size()) {
            return false;
        }
        
        for (int i = 0; i < s.size(); i++) {
            hash_count[s[i] - 'a']++;
        }
        
        for (int i = 0; i < t.size(); i++) {
            hash_count[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (hash_count[i] != 0) {
                return false;
            }
            
        }
        
        return true;
    }
};

// O(N) 24ms
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, int> count_s;
        unordered_map<char, int> count_t;
        
        for (int i = 0; i < s.size(); i++) {
            count_s[s[i]]++;
            count_t[t[i]]++;
        }
        
        return count_s == count_t;
    }
};
