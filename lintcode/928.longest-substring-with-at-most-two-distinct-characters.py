#  Tag: Same Direction Two Pointers, Two Pointers, Hash Table, String
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-159
#  Note: -

#  Given a string, find the length of the longest substring T that contains at most `2` distinct characters.
#  
#  ---
#   
#  
#  ### Example 1
#  ```
#  Input: “eceba”
#  Output: 3
#  Explanation:
#  T is "ece" which its length is 3.
#  ```
#  
#  ### Example 2
#  ```
#  Input: “aaa”
#  Output: 3
#  ```
#  
#  

from collections import defaultdict
class Solution:
    """
    @param s: a string
    @return: the length of the longest substring T that contains at most 2 distinct characters
    """
    def length_of_longest_substring_two_distinct(self, s: str) -> int:
        # Write your code here
        n = len(s)
        res = 0
        i = 0
        counter = defaultdict(int)
        for j in range(n):
            counter[s[j]] += 1
            while len(counter) > 2:
                counter[s[i]] -= 1
                if counter[s[i]] == 0:
                    del counter[s[i]]
                i += 1

            res = max(res, j - i + 1)
        return res