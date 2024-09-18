#  Tag: Array, Hash Table, String, Sorting
#  Time: O(NL)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an array of strings strs, group the anagrams together. You can return the answer in any order.
#  An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
#   
#  Example 1:
#  Input: strs = ["eat","tea","tan","ate","nat","bat"]
#  Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
#  Example 2:
#  Input: strs = [""]
#  Output: [[""]]
#  Example 3:
#  Input: strs = ["a"]
#  Output: [["a"]]
#  
#   
#  Constraints:
#  
#  1 <= strs.length <= 104
#  0 <= strs[i].length <= 100
#  strs[i] consists of lowercase English letters.
#  
#  

from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        counter = defaultdict(list)
        for s in strs:
            key = "".join(sorted(s))
            counter[key].append(s)

        return [counter[k] for k in counter]