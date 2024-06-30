#  Tag: Array, Two Pointers, String, Sorting
#  Time: O(N*logN + M * N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
#   
#  Example 1:
#  
#  Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
#  Output: "apple"
#  
#  Example 2:
#  
#  Input: s = "abpcplea", dictionary = ["a","b","c"]
#  Output: "a"
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 1000
#  1 <= dictionary.length <= 1000
#  1 <= dictionary[i].length <= 1000
#  s and dictionary[i] consist of lowercase English letters.
#  
#  

class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        dictionary.sort(key=lambda t: (-len(t), t))

        for t in dictionary:
            k = 0
            for i in range(len(s)):
                if k < len(t) and s[i] == t[k]:
                    k += 1

            if k == len(t):
                return t

        return ''   