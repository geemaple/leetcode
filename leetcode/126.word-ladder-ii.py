#  Tag: Hash Table, String, Backtracking, Breadth-First Search
#  Time: O((N*L)^C)
#  Space: O(N)
#  Ref: -
#  Note: -

#  A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
#  
#  Every adjacent pair of words differs by a single letter.
#  Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
#  sk == endWord
#  
#  Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
#   
#  Example 1:
#  
#  Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
#  Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
#  Explanation: There are 2 shortest transformation sequences:
#  "hit" -> "hot" -> "dot" -> "dog" -> "cog"
#  "hit" -> "hot" -> "lot" -> "log" -> "cog"
#  
#  Example 2:
#  
#  Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
#  Output: []
#  Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
#  
#   
#  Constraints:
#  
#  1 <= beginWord.length <= 5
#  endWord.length == beginWord.length
#  1 <= wordList.length <= 500
#  wordList[i].length == beginWord.length
#  beginWord, endWord, and wordList[i] consist of lowercase English letters.
#  beginWord != endWord
#  All the words in wordList are unique.
#  The sum of all shortest transformation sequences does not exceed 105.
#  
#  

import collections
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:

        words_distance = {}
        for w in wordList:
            words_distance[w] = 0

        if endWord not in words_distance:
            return []

        self.bfs(endWord, words_distance)
        
        res = []
        self.dfs(words_distance, endWord, {beginWord}, [beginWord], res)
            
        return res
        
    def dfs(self, words_distance: dict, endWord: str, visited:set, tmp: List[str], res: List[List[str]]):
        word = tmp[-1]
        if word == endWord:
            res.append(tmp.copy())
            return
        
        distance = words_distance.get(word, float('inf'))
        for n in self.get_next(word, visited, words_distance):
            if words_distance[n] >= distance:
                continue

            visited.add(n)
            self.dfs(words_distance, endWord, visited, tmp + [n], res)
            visited.remove(n)


    def bfs(self, endWord: str, words_distance: dict):
        distance = 0
        q = collections.deque([endWord])
        visited = {endWord}

        while len(q) > 0:
            c = len(q)
            for _ in range(c):
                word = q.popleft()
                words_distance[word] = distance

                for n in self.get_next(word, visited, words_distance):
                    visited.add(n)
                    q.append(n)

            distance += 1

    def get_next(self, word: str, visited: set, words_distance: dict) -> List:
        res = []
        for i in range(len(word)):
            for l in 'abcdefghijklmnopqrstuvwxyz':
                if l == word[i]:
                    continue

                n = word[:i] + l + word[i + 1:]
                if n not in words_distance or n in visited:
                    continue

                res.append(n)

        return res