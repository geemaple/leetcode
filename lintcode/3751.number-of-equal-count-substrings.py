#  Tag: Sliding Window, String
#  Time: O(N)
#  Space: O(N)
#  Ref: Leetcode-2067
#  Note: -

#  Given a string `s` with subscripts starting at **0**, containing only lowercase English letters and given an integer `count`.
#  A **substring** of `s` is said to be an **equal count substring** of `s` if each letter occurs exactly `count` times in the substring.
#  
#  Returns **the number of equal count substrings in `s`.**
#  
#  Example 1:
#  ```
#  Input:
#  s = "dababcc"
#  count = 2
#  Output:
#  3
#  Explanation:
#  The substring "cc" from subscript 5 to subscript 6, the letter "c" appear 2 times
#  The substring "abab" from subscript 1 to subscript 4, the letters "a" and "b" both appear 2 times
#  The substring "ababcc" from subscript 1 to subscript 6, the letters "a", "b" and "c" all appear 2 times
#  ```
#  
#  Example 2:
#  ```
#  Input:
#  s = "abcdab"
#  count = 2
#  Output:
#  0
#  Explanation:
#  None of the letters in the substring will appear 2 times
#  ```
#  
#  $1 \leq s.length \leq 3  \times10^4$
#  $1 \leq count \leq 3 \times 10^4$
#  `s` contains lowercase letters only

from collections import defaultdict
class Solution:
    """
    @param s: A string containing only lowercase
    @param count: Number of occurrences of the same letter
    @return: Number of equal count substrings
    """
    def equal_count_substrings(self, s: str, count: int) -> int:
        # write your code here
        n = len(s)
        res = 0
        for r in range(1, 27):
            k = r * count
            counter = defaultdict(int)
            hit = 0
            if k > n:
                break

            for i in range(n):
                if i >= k:
                    if counter[s[i - k]] == count:
                        hit -= 1
                    counter[s[i - k]] -= 1
        

                counter[s[i]] += 1
                if counter[s[i]] == count:
                    hit += 1

                if i >= k - 1:
                    if hit == r:
                        res += 1

        return res