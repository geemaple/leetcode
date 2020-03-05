/*
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (22.51%)
 * Total Accepted:    162.7K
 * Total Submissions: 656.8K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.size() == 0 || words.size() == 0 || words[0].size() == 0) return ans;
        
        int num = (int)words.size();
        int word_len = (int)words[0].size();
        int substring_len = num * word_len;
        
        unordered_map<string, int> word_count;
        for (int i = 0; i < words.size(); i++) {
            word_count[words[i]] += 1;
        }
        
        for (int i = 0; i < num - substring_len + 1; i++) {
            string test_string = s.substr(i, substring_len);
            unordered_map<string, int> test_count;
            int count = 0;
            for (int j = 0; j < substring_len; j += word_len) {
                string test_word = test_string.substr(j, word_len);

                if (word_count.count(test_word) && test_count[test_word] < word_count[test_word]) {
                    count++;
                    test_count[test_word] += 1;
                } else {
                    break;
                }
            }
            
            if (count == num) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string a[] = {"foo","bar"};
    vector<string> vec(a, a + 3);
    Solution s;
    vector<int> res = s.findSubstring("barfoothefoobarman", vec);

    return 0;
}
