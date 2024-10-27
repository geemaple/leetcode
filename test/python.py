
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math

from typing import (
    List,
)

from typing import (
    List,
)

from collections import defaultdict
class Solution:
    """
    @param dict: an array of n distinct non-empty strings
    @return: an array of minimal possible abbreviations for every word
    """
    def words_abbreviation(self, dict: List[str]) -> List[str]:
        # write your code here
        heap = []
        n = len(dict)
        prefix = [1 for i in range(n)]
        counter = defaultdict(int)
        res = []
        for i in range(n):
            abbr = self.abbreviate(dict[i], prefix[i])
            res.append(abbr)
            counter[abbr] += 1

        duplicate = True
        while duplicate:

            duplicate = False
            for i in range(n):
                abbr = res[i]
                if counter[abbr] > 1:
                    duplicate = True
                    prefix[i] += 1
                    new_abbr = self.abbreviate(dict[i], prefix[i])
                    counter[new_abbr] += 1
                    res[i] = new_abbr

        return res

    def abbreviate(self, word, pos) -> str:
        if pos + 2 >= len(word):
            return word

        return word[:pos] + str(len(word) - 1 - pos) + word[-1]

    

s = Solution()
ts = datetime.now()

res = s.words_abbreviation(["like","god","internal","me","internet","interval","intension","face","intrusion"])

print(datetime.now() - ts)
print(res)
