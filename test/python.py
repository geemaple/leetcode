
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
    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        vowels = defaultdict(int)
        j = 0
        res = 0
        for i in range(n):
            if word[i] in 'aeiou':
                vowels[word[i]] += 1
            else:
                if len(vowels) == 5:
                    while len(vowels) == 5 and k == 0:  
                        print(j, i)
                        res += 1
                        if word[j] in 'aeiou':
                            vowels[word[j]] -= 1
                            if vowels[word[j]] == 0:
                                del vowels[word[j]]
                        else:
                            k += 1

                        j += 1  
                    k -= 1
                else:
                    while k < 0 and j < n:
                        if word[j] in 'aeiou':
                            vowels[word[j]] -= 1
                            if vowels[word[j]] == 0:
                                del vowels[word[j]]
                        else:
                            k += 1

                    k -= 1

        return res



s = Solution()
ts = datetime.now()
res = s.countOfSubstrings("iqeaouqi", 2)
print(datetime.now() - ts)
print(res)
