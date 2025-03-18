#  Tag: Hash Table, String, Divide and Conquer, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
#  if no such substring exists, return 0.
#   
#  Example 1:
#  
#  Input: s = "aaabb", k = 3
#  Output: 3
#  Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
#  
#  Example 2:
#  
#  Input: s = "ababbc", k = 2
#  Output: 5
#  Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 104
#  s consists of only lowercase English letters.
#  1 <= k <= 105
#  
#  

from collections import Counter
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        counter = Counter(s)
        for x, count in counter.items():
            if count < k:
                return max(self.longestSubstring(s, k) for s in s.split(x))                

        return len(s)
    
from collections import defaultdict
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        res = 0
        for i in range(1, 27):
            res = max(res, self.longestSubstringWithUnique(s, k, i))
        return res

    def longestSubstringWithUnique(self, s: str, k: int, target: int) -> int:

        n = len(s)
        counter = defaultdict(int)
        count = 0
        i = 0
        res = 0
        for j in range(n):
            counter[s[j]] += 1
            if counter[s[j]] == k:
                count += 1

            while (len(counter) > target):
                counter[s[i]] -= 1
                if counter[s[i]] == k - 1:
                    count -= 1
                if counter[s[i]] == 0:
                    del counter[s[i]]
                i += 1
            
            if len(counter) == target and len(counter) == count:
                res = max(res, j - i + 1)

        return res