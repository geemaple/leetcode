#  Tag: Hash Table, String, Sorting, Heap (Priority Queue), Bucket Sort, Counting
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
#  Return the sorted string. If there are multiple answers, return any of them.
#   
#  Example 1:
#  
#  Input: s = "tree"
#  Output: "eert"
#  Explanation: 'e' appears twice while 'r' and 't' both appear once.
#  So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
#  
#  Example 2:
#  
#  Input: s = "cccaaa"
#  Output: "aaaccc"
#  Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
#  Note that "cacaca" is incorrect, as the same characters must be together.
#  
#  Example 3:
#  
#  Input: s = "Aabb"
#  Output: "bbAa"
#  Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
#  Note that 'A' and 'a' are treated as two different characters.
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 5 * 105
#  s consists of uppercase and lowercase English letters and digits.
#  
#  

class Solution:
    def frequencySort(self, s: str) -> str:
        counter = {}
        max_count = 0
        for l in s:
            counter[l] = counter.get(l, 0) + 1
            if counter[l] > max_count:
                max_count = counter[l]

        buckets = [[] for i in range(max_count + 1)]
        for k, v in counter.items():
            buckets[v].append(k)

        res = ''
        for i in range(max_count, 0, -1):
            for l in buckets[i]:
                res += l * i

        return res
        