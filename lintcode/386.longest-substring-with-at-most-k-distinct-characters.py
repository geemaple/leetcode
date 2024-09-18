#  Tag: Same Direction Two Pointers, Two Pointers
#  Time: O(N)
#  Space: O(K)
#  Ref: -
#  Note: Leetcode-340

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

class Solution:
    """
    @param s: A string
    @param k: An integer
    @return: An integer
    """
    def length_of_longest_substring_k_distinct(self, s: str, k: int) -> int:
        # write your code here
        table = collections.defaultdict(int)
        count = 0
        l = 0
        length = 0
        for r in range(len(s)):
            if table[s[r]] == 0:
                count += 1
            table[s[r]] += 1

            while count > k:
                if table[s[l]] == 1:
                    count -= 1
                table[s[l]] -= 1
                l += 1

            if r - l + 1 > length:
                length = r - l + 1

        return length