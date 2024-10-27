#  Tag: Hash Table
#  Time: O(NL)
#  Space: O(N)
#  Ref: Leetcode-527
#  Note: -

#  Given an array of n distinct non-empty strings, you need to generate **minimal** possible abbreviations for every word following rules below.
#  
#  1.
#  Begin with the first character and then the number of characters abbreviated, which followed by the last character.
#  2.
#  If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique.
#  In other words, a final abbreviation cannot map to more than one original words.
#  3.
#  If the abbreviation doesn't make the word shorter, then keep it as original.
#  
#  **Example 1:**
#  ```
#  Input:
#  ["like","god","internal","me","internet","interval","intension","face","intrusion"]
#  Output:
#  ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
#  ```
#  
#  **Example 2:**
#  ```
#  Input:
#  ["where","there","is","beautiful","way"]
#  Output:
#  ["w3e","t3e","is","b7l","way"]
#  ```
#  
#  1. Both n and the length of each word will not exceed 400.
#  2. The length of each word is greater than 1.
#  3. The words consist of lowercase English letters only.
#  4. The return answers should be in the same order as the original array.

from typing import (
    List,
)

from collections import defaultdict
class Solution:
    """
    @param dict: an array of n distinct non-empty strings
    @return: an array of minimal possible abbreviations for every word
    """
    def words_abbreviation(self, dict: List[str]) -> List[str]:
        # write your code here
        heap = []
        n = len(dict)
        prefix = [1 for i in range(n)]
        counter = defaultdict(int)
        res = []
        for i in range(n):
            abbr = self.abbreviate(dict[i], prefix[i])
            res.append(abbr)
            counter[abbr] += 1

        duplicate = True
        while duplicate:

            duplicate = False
            for i in range(n):
                abbr = res[i]
                if counter[abbr] > 1:
                    duplicate = True
                    prefix[i] += 1
                    new_abbr = self.abbreviate(dict[i], prefix[i])
                    counter[new_abbr] += 1
                    res[i] = new_abbr

        return res

    def abbreviate(self, word, pos) -> str:
        if pos + 2 >= len(word):
            return word

        return word[:pos] + str(len(word) - 1 - pos) + word[-1]