#  Tag: Hash Table, String, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
#  Return the length of the longest substring containing the same letter you can get after performing the above operations.
#   
#  Example 1:
#  
#  Input: s = "ABAB", k = 2
#  Output: 4
#  Explanation: Replace the two 'A's with two 'B's or vice versa.
#  
#  Example 2:
#  
#  Input: s = "AABABBA", k = 1
#  Output: 4
#  Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
#  The substring "BBBB" has the longest repeating letters, which is 4.
#  There may exists other ways to achieve this answer too.
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  s consists of only uppercase English letters.
#  0 <= k <= s.length
#  
#  

from collections import defaultdict
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counter = defaultdict(int)
        n = len(s)
        j = 0
        res = 0
        most_frequent = 0

        for i in range(n):
            counter[s[i]] += 1
            most_frequent = max(most_frequent, counter[s[i]])

            # length - most_frequent <= k
            # kepp most_frequent unchanged since smaller frequnt won't contribute to the result
            while i - j + 1 - most_frequent > k:
                counter[s[j]] -= 1
                j += 1

            res = max(res, i - j + 1)

        return res


from collections import defaultdict
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counter = defaultdict(int)
        n = len(s)
        j = 0
        res = 0
        for i in range(n):
            counter[s[i]] += 1
            while i - j + 1 - self.most_frequent(counter) > k:
                counter[s[j]] -= 1
                j += 1

            res = max(res, i - j + 1)

        return res

    def most_frequent(self, counter: dict) -> int:
        res = 0
        for key in counter:
            res = max(res, counter[key])
        return res