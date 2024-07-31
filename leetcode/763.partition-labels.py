#  Tag: Greedy, Hash Table, Two Pointers, String
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
#  Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
#  Return a list of integers representing the size of these parts.
#   
#  Example 1:
#  
#  Input: s = "ababcbacadefegdehijhklij"
#  Output: [9,7,8]
#  Explanation:
#  The partition is "ababcbaca", "defegde", "hijhklij".
#  This is a partition so that each letter appears in at most one part.
#  A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
#  
#  Example 2:
#  
#  Input: s = "eccbbbbdec"
#  Output: [10]
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 500
#  s consists of lowercase English letters.
#  
#  

class Solution:
    def partitionLabels(self, s: str) -> List[int]:

        letters = {}
        for i in range(len(s)):
            letters[s[i]] = i

        res = []
        start = 0
        end = letters[s[0]]

        for i in range(1, len(s)):
            
            if i > end:
                res.append(end - start + 1)
                start = i
            
            end = max(end, letters[s[i]])

        res.append(end - start + 1)

        return res