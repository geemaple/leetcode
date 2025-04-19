#  Tag: Hash Table, String, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given a string text. You can swap two of the characters in the text.
#  Return the length of the longest substring with repeated characters.
#   
#  Example 1:
#  
#  Input: text = "ababa"
#  Output: 3
#  Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
#  
#  Example 2:
#  
#  Input: text = "aaabaaa"
#  Output: 6
#  Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
#  
#  Example 3:
#  
#  Input: text = "aaaaa"
#  Output: 5
#  Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
#  
#   
#  Constraints:
#  
#  1 <= text.length <= 2 * 104
#  text consist of lowercase English characters only.
#  
#  

from collections import Counter
class Solution:
    def maxRepOpt1(self, text: str) -> int:
        res = 0
        counter = Counter(text)
        for k in counter:
            count = min(counter[k], self.count(text, k))
            res = max(res, count)
        return res

    def count(self, text: str, target: str) -> int:
        n = len(text)
        res = 0
        i = 0
        count = 0
        for j in range(n):
            count += text[j] != target
            while count > 1:
                count -= text[i] != target
                i += 1

            res = max(res, j - i + 1)
        return res

from collections import defaultdict
class Solution:
    def maxRepOpt1(self, text: str) -> int:
        n = len(text)
        group = []
        counter = defaultdict(int)
        count = 1
        for i in range(n):
            counter[text[i]] += 1
            if i == n - 1 or text[i] != text[i + 1]:
                group.append([text[i], count])
                count = 1
            else:
                count += 1

        res = 0
        for x, count in group:
            res = max(res, min(count + 1, counter[x]))

        for i in range(1, len(group) - 1):
            if group[i - 1][0] == group[i + 1][0] and group[i][1] == 1:
                res = max(res, min(group[i - 1][1] + group[i + 1][1] + 1, counter[group[i - 1][0]]))

        return res