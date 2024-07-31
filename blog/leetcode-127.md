---
layout: post
index: 127
title: "LeetCode-127.单词接龙(Word Ladder)"
categories: Leetcode
tags: Leetcode BFS
excerpt: "风林一叶下"
---

* content
{:toc}

## 127. 单词接龙

字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：

```
序列中第一个单词是 beginWord 。
序列中最后一个单词是 endWord 。
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典 wordList 中的单词。
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。
```
 
示例 1：

```
输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
```

示例 2：

```
输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
输出：0
解释：endWord "cog" 不在字典中，所以无法进行转换。
```

提示：

```
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord、endWord 和 wordList[i] 由小写英文字母组成
beginWord != endWord
wordList 中的所有字符串 互不相同
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/word-ladder](https://leetcode-cn.com/problems/word-ladder)

Link：[https://leetcode.com/problems/word-ladder/](https://leetcode.com/problems/word-ladder/)


## 宽度优先搜索

O(NL)

```python
             'hit'
               |
             'hot'
            /     \
         'dot' - 'lot'
           |       |
         'dog' - 'log'
            \     /
             'cog'
```

从开始单词**到**结束单词之间会形成一张图，也就是说，用宽度优先搜索，找到路径最短的变换

问题在于如何找到，只差一个字母的所有邻居，一点点变化，时间复杂度是不一样的

时间复杂度: O(N * N * L)

```python
from collections import deque
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        
        wordset = set(wordList)
        if endWord not in wordset:
            return 0
        
        distance = 0
        visited = set([beginWord])
        queue = deque([beginWord])
        
        while len(queue) > 0:
            
            count = len(queue)
            distance += 1
            
            for i in range(count):
                word = queue.popleft()
 
                if word == endWord:
                    return distance
                
                for target in wordset:
                    if target not in visited and self.changeable(word, target):
                        queue.append(target)
                        visited.add(target)
        
        return 0
        
    def changeable(self, beginWord: str, endWord: str) -> bool:
        
        diff = 0
        for i in range(len(beginWord)):
            diff += 0 if beginWord[i] == endWord[i] else 1
            
        return diff == 1
```

优化的时间复杂度: O(N * 26 * L)

```python
from collections import deque
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        
        wordset = set(wordList)
        if endWord not in wordset:
            return 0
        
        level = 0
        visited = set([beginWord])
        queue = deque([beginWord])
        
        while len(queue) > 0:
            
            count = len(queue)
            level += 1
            
            for i in range(count):
                word = queue.popleft()
 
                if word == endWord:
                    return level
                
                for target in self.findNeighbors(word, wordset, visited):    
                    queue.append(target)
                    visited.add(target)
        
        return 0
        
    def findNeighbors(self, word: str, wordset: set, visited: set) -> [str]:
        
        res = []

        for i in range(len(word)):
            for char in 'abcdefghijklmnopqrstuvwxyz':
                candidate = word[:i] + char + word[i + 1:]
                if candidate == word:
                    continue
                    
                if candidate in visited:
                    continue
                    
                if candidate not in wordset:
                    continue
                    
                res.append(candidate)
                
        return res
```

精简代码如下:

```python
from collections import deque
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        
        wordset = set(wordList)        
        queue = deque([beginWord])
        level = 0
        
        while len(queue) > 0:
            count = len(queue)
            level += 1
            
            for i in range(count):
                word = queue.popleft()
                
                if word == endWord:
                    return level
                
                for j in range(len(word)):
                    for k in 'abcdefghijklmnopqrstuvwxyz':
                        candidate = word[:j] + k + word[j + 1:]
                        if candidate in wordset:
                            queue.append(candidate)
                            wordset.remove(candidate)
  
        return 0
```

--End--