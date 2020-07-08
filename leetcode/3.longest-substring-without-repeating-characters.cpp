/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (30.10%)
 * Total Accepted:    1.6M
 * Total Submissions: 5.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int left = 0;
        unordered_set<char> visited;

        for(int i = 0; i < s.size(); ++i){
            while(visited.count(s[i]) > 0){
                visited.erase(s[left++]);
            }

            visited.insert(s[i]);
            res = max(res, i - left + 1);
        }

        return res;
    }
};

class Solution2 {
private:
    static const int ASCII_COUNT = 256;
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int left = 0;
        vector<int> visited(ASCII_COUNT, - 1);

        for(int i = 0; i < s.size(); ++i){

            if (visited[s[i]] >= 0){
                left  = max(visited[s[i]] + 1, left);
            }

            visited[s[i]] = i;
            res = max(res, i - left + 1);
        }

        return res;
    }
};



