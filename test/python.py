
from typing import List
from collections import defaultdict
import heapq

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        counter = defaultdict(list)
        for s in strs:
            print(s, sorted(s))
            counter[sorted(s)].append(s)

        return [counter[k] for k in counter]


s = Solution()
res = s.groupAnagrams(["eat","tea","tan","ate","nat","bat"])
print(res)