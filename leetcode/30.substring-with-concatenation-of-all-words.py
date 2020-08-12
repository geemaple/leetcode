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
from collections import Counter
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        
        if len(s) == 0 or len(words) == 0 or len(words[0]) == 0:
            return []
        
        words_count = Counter()
        for word in words:
            words_count[word] += 1
            
        res = []
        word_length = len(words[0])
        sub_length = len(words) * word_length
        
        for i in range(word_length):
            left = i
            check_count = Counter()
            count = 0
            
            for j in range(i, len(s) - word_length + 1, word_length):
                in_word = s[j: j + word_length]
  
                if in_word in words_count:
                    check_count[in_word] += 1
                    
                    if check_count[in_word] <= words_count[in_word]:
                        count += 1
                    else:
                        while check_count[in_word] > words_count[in_word]:
                            out_word = s[left: left + word_length]
                            check_count[out_word] -= 1
                            
                            if check_count[out_word] < words_count[out_word]:
                                count -= 1
                            left += word_length
                        
                    if count == len(words):
                        res.append(left)
                        out_word = s[left: left + word_length]
                        check_count[out_word] -= 1
                        count -= 1
                        left += word_length
                else:
                    check_count = Counter()
                    left = j + word_length
                    count = 0
                
        return res

from collections import Counter
class Solution2:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        
        if len(s) == 0 or len(words) == 0 or len(words[0]) == 0:
            return []
        
        words_count = Counter()
        for word in words:
            words_count[word] += 1
            
        res = []
        word_length = len(words[0])
        sub_length = len(words) * word_length

        for i in range(len(s) - sub_length + 1):
            check_count = Counter()
            
            for j in range(i, i + sub_length, word_length):
                word = s[j : j + word_length]          
                if word in words_count:
                    check_count[word] += 1
                else:
                    break

            if check_count == words_count:
                res.append(i)
            
        return res