
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)


from collections import defaultdict
class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
    
        counter = defaultdict(int)
        for x in word2:
            counter[x] += 1

        i = 0
        found = 0
        res = 0
        for j in range(n):
            if word1[j] in counter:
                counter[word1[j]] -= 1
                if counter[word1[j]] >= 0:
                    found += 1

            while found == m:
                res += n - j
                if word1[i] in counter:
                    counter[word1[i]] += 1
                    if counter[word1[i]] > 0:
                        found -= 1

                i += 1

        return res


s = Solution()
ts = datetime.now()
res = s.validSubstringCount("dcbdcdccb", "cdd")
print(datetime.now() - ts)
print(res)
