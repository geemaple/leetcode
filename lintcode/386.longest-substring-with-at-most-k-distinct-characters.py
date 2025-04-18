#  Tag: Same Direction Two Pointers, Two Pointers
#  Time: O(N)
#  Space: O(K)
#  Ref: Leetcode-340
#  Note: -

#  Given a string *S*, find the length of the longest substring *T* that contains at most k distinct characters.
#  
#  **Example 1:**
#  
#  ```
#  Input: S = "eceba" and k = 3
#  Output: 4
#  Explanation: T = "eceb"
#  ```
#  
#  **Example 2:**
#  
#  ```
#  Input: S = "WORLD" and k = 4
#  Output: 4
#  Explanation: T = "WORL" or "ORLD"
#  ```
#  
#  

from collections import defaultdict
class Solution:
    """
    @param s: A string
    @param k: An integer
    @return: An integer
    """
    def length_of_longest_substring_k_distinct(self, s: str, k: int) -> int:
        # write your code here
        n = len(s)
        res = 0
        i = 0
        counter = defaultdict(int)
        for j in range(n):
            counter[s[j]] += 1
            while len(counter) > k:
                counter[s[i]] -= 1
                if counter[s[i]] == 0:
                    del counter[s[i]]
                i += 1

            res = max(res, j - i + 1)
        return res
