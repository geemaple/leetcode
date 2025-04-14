#  Tag: Hash Table, String, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/KceY_w1PJ-Y

#  You are given a string word and a non-negative integer k.
#  Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
#   
#  Example 1:
#  
#  Input: word = "aeioqq", k = 1
#  Output: 0
#  Explanation:
#  There is no substring with every vowel.
#  
#  Example 2:
#  
#  Input: word = "aeiou", k = 0
#  Output: 1
#  Explanation:
#  The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".
#  
#  Example 3:
#  
#  Input: word = "ieaouqqieaouqq", k = 1
#  Output: 3
#  Explanation:
#  The substrings with every vowel and one consonant are:
#  
#  word[0..5], which is "ieaouq".
#  word[6..11], which is "qieaou".
#  word[7..12], which is "ieaouq".
#  
#  
#   
#  Constraints:
#  
#  5 <= word.length <= 2 * 105
#  word consists only of lowercase English letters.
#  0 <= k <= word.length - 5
#  
#  

from collections import defaultdict
class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        return self.count(word, k) - self.count(word, k + 1)

    def count(self, word: str, k: int) -> int:
        n = len(word)
        vowel = defaultdict(int)
        count = 0
        i = 0
        res = 0
        for j in range(n):
            if word[j] in 'aeiou':
                vowel[word[j]] += 1
            else:
                count += 1

            while len(vowel) == 5 and count >= k:
                res += n - j
                if word[i] in 'aeiou':
                    vowel[word[i]] -= 1
                    if vowel[word[i]] == 0:
                        del vowel[word[i]]
                else:
                    count -= 1
                i += 1
                
        return res

from collections import defaultdict
class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        next_consonant = {}
        val = n
        for i in range(n - 1, -1, -1):
            next_consonant[i] = val
            if word[i] not in 'aeiou':
                val = i

        counter = defaultdict(int)
        consonants = 0
        res = 0
        i = 0
        for j in range(n):
            if word[j] in 'aeiou':
                counter[word[j]] += 1
            else:
                consonants += 1

            while consonants > k:
                if word[i] in 'aeiou':
                    counter[word[i]] -= 1
                    if counter[word[i]] == 0:
                        del counter[word[i]]
                else:
                    consonants -= 1

                i += 1

            while len(counter) == 5 and consonants == k:
                res += (next_consonant[j] - j)

                if word[i] in 'aeiou':
                    counter[word[i]] -= 1
                    if counter[word[i]] == 0:
                        del counter[word[i]]
                else:
                    consonants -= 1

                i += 1

        return res