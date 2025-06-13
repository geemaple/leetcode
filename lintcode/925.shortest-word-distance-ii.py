#  Tag: Hash Table
#  Time: O(N)
#  Space: O(N)
#  Ref: Leetcode-244
#  Note: -

#  This is a **follow up** of [Shortest Word Distance](https://www.lintcode.com/problem/924/).
#  The only difference is now you are given the list of words and your method will be called `repeatedly` many times with different parameters.
#  How would you optimize it?
#  
#  Design a class which receives a list of words in the constructor, and implements a method that takes two words `word1` and `word2` and return the shortest distance between these two words in the list.
#  
#  **Example 1**
#  
#  Input:
#  
#  ```plaintext
#  ["practice", "makes", "perfect", "coding", "makes"]
#  ["practice", "coding"]
#  ["coding", "makes"]
#  ```
#  
#  Output:
#  
#  ```plaintext
#  3
#  1
#  ```
#  
#  **Example 2**
#  
#  input:
#  
#  ```plaintext
#  ["quia", "blanditiis", "dolores", "sed", "tenetur", "eos", "unde", "tenetur", "blanditiis", "ducimus"]
#  ["tenetur", "blanditiis"]
#  ["blanditiis", "dolores"]
#  ["unde", "eos"]
#  ```
#  
#  Output:
#  
#  ```plaintext
#  1
#  1
#  1
#  ```
#  
#  You may assume that $ word1 \neq word2$, and `word1` and `word2` are **both in the list**.

from typing import List
from collections import defaultdict
class WordDistance:

    def __init__(self, wordsDict: List[str]):
        self.indexes = defaultdict(list)
        for i in range(len(wordsDict)):
            self.indexes[wordsDict[i]].append(i)

    """
    @param word1: word1
    @param word2: word2
    @return: the shortest distance between two words
    """
    def shortest(self, word1: str, word2: str) -> int:
        # write your code here
        index1 = self.indexes[word1]
        index2 = self.indexes[word2]
        n = len(index1)
        m = len(index2)
        i = 0
        j = 0
        res = float('inf')
        while i < n and j < m:
            res = min(res, abs(index1[i] - index2[j]))
            if index1[i] < index2[j]:
                i += 1
            else:
                j += 1

        return res