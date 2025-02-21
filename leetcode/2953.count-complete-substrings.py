#  Tag: Hash Table, String, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given a string word and an integer k.
#  A substring s of word is complete if:
#  
#  Each character in s occurs exactly k times.
#  The difference between two adjacent characters is at most 2. That is, for any two adjacent characters c1 and c2 in s, the absolute difference in their positions in the alphabet is at most 2.
#  
#  Return the number of complete substrings of word.
#  A substring is a non-empty contiguous sequence of characters in a string.
#   
#  Example 1:
#  
#  Input: word = "igigee", k = 2
#  Output: 3
#  Explanation: The complete substrings where each character appears exactly twice and the difference between adjacent characters is at most 2 are: igigee, igigee, igigee.
#  
#  Example 2:
#  
#  Input: word = "aaabbbccc", k = 3
#  Output: 6
#  Explanation: The complete substrings where each character appears exactly three times and the difference between adjacent characters is at most 2 are: aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc.
#  
#   
#  Constraints:
#  
#  1 <= word.length <= 105
#  word consists only of lowercase English letters.
#  1 <= k <= word.length
#  
#  

class Solution:
    def countCompleteSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        splits = []

        i = 0
        for j in range(1, n):
            if abs(ord(word[j]) - ord(word[j - 1])) > 2:
                splits.append(word[i: j])
                i = j
        splits.append(word[i: n]) 
        
        res = 0
        for s in splits:
            for r in range(1, 27):
                counter = defaultdict(int)   
                window_size = r * k
                if window_size > len(s):
                    break

                for i in range(len(s)):
                    if i >= window_size:
                        counter[s[i - window_size]] -= 1
                        if counter[s[i - window_size]] == 0:
                            del counter[s[i - window_size]]

                    counter[s[i]] += 1
                    if i >= window_size - 1:
                        if self.checkCount(counter, k):
                            res += 1
        return res

    def checkCount(self, counter: dict, target: int) -> bool:
        for word, count in counter.items():
            if count != target:
                return False
        return True