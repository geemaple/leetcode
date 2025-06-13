#  Tag: Enumerate, Array
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-243
#  Note: -

#  Given a list of `words` and two words `word1` and `word2`, return the shortest distance between these two words in the list.
#  
#  **Example 1:**
#  ```
#  Input：["practice", "makes", "perfect", "coding", "makes"],"coding","practice"
#  Output：3
#  Explanation：index("coding") - index("practice") = 3
#  ```
#  
#  
#  **Example 2:**
#  ```
#  Input：["practice", "makes", "perfect", "coding", "makes"],"makes","coding"
#  Output：1
#  Explanation：index("makes") - index("coding") = 1
#  ```
#  
#  You may assume that `word1 does not equal to word2`, and word1 and word2 are `both` in the list.

from typing import (
    List,
)

class Solution:
    """
    @param words: a list of words
    @param word1: a string
    @param word2: a string
    @return: the shortest distance between word1 and word2 in the list
    """
    def shortest_distance(self, words: List[str], word1: str, word2: str) -> int:
        # Write your code here
        n = len(words)
        res = n
        a = -1
        b = -1
        for i in range(n):
            if words[i] == word1:
                a = i
            elif words[i] == word2:
                b = i

            if a >= 0 and b >= 0:
                res = min(res, abs(a - b))

        return res