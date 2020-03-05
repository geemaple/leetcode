#
# [30] Substring with Concatenation of All Words
#
# https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
#
# algorithms
# Hard (22.51%)
# Total Accepted:    162.7K
# Total Submissions: 656.8K
# Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
#
# You are given a string, s, and a list of words, words, that are all of the
# same length. Find all starting indices of substring(s) in s that is a
# concatenation of each word in words exactly once and without any intervening
# characters.
# 
# 
# 
# Example 1:
# 
# 
# Input:
# ⁠ s = "barfoothefoobarman",
# ⁠ words = ["foo","bar"]
# Output: [0,9]
# Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
# respectively.
# The output order does not matter, returning [9,0] is fine too.
# 
# 
# Example 2:
# 
# 
# Input:
# ⁠ s = "wordgoodgoodgoodbestword",
# ⁠ words = ["word","good","best","word"]
# Output: []
# 
# 
#
import collections
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if len(s) == 0 or len(words) == 0 or len(words[0]) == 0:
            return []

        word_len = len(words[0])
        substring_len = len(words) * word_len

        res = []
        word_count = collections.Counter()
        for word in words:
            word_count[word] += 1

        for i in range(len(s) - substring_len + 1):
            substring = s[i: i + substring_len]

            check_count = collections.Counter()
            for j in range(0, len(substring), word_len):
                test_word = substring[j: j + word_len]
                if test_word not in word_count or check_count[test_word] > word_count[test_word]:
                    break
                else:
                    check_count[test_word] += 1

            if check_count == word_count:
                res.append(i)

        return res