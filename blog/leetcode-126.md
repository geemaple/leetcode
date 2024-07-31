---
layout: post
index: 126
title: "LeetCode-126.单词接龙 II(Word Ladder II)"
categories: Leetcode
tags: Leetcode Array String Backtracking BFS
excerpt: "Be Klever"
---

* content
{:toc}

## 126. 单词接龙 II

给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换后得到的单词必须是字典中的单词。

说明:

```
如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
```

示例 1:

```
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
```

示例 2:

```
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []
```

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/word-ladder-ii](https://leetcode-cn.com/problems/word-ladder-ii)

Link：[https://leetcode.com/problems/word-ladder-ii/](https://leetcode.com/problems/word-ladder-ii/)


## 宽度优先搜索 + 深度优先搜索

O(N)

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

先用宽度优先搜索，记录下每个节点距离开始的距离，然后用深度优先搜索，每次都选择离目标更进一步的节点。

```python
from collections import deque
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        
        distances = {word : float('inf') for word in wordList}
        if endWord not in distances:
            return []
               
        self.bfs(beginWord, distances)
        
        res = []
        visited = set()
        candidate = [beginWord]
        self.dfs(beginWord, endWord, visited, distances, candidate, res)
        return res
    
    def bfs(self, word: str, distances: dict):
        level = 0
        visited = set(word)
        queue = deque([word])
        distances[word] = 0
        
        while len(queue) > 0:            
            count = len(queue)
            level += 1
            for i in range(count):
                word = queue.popleft()
    
                for target in self.findNeighbors(word, visited, distances):
                    visited.add(target)
                    queue.append(target)
                    distances[target] = min(distances[target], level)
            
    def dfs(self, word: str, endWord: str, visited: set, distances: dict, candidate: List[str], res: List[List[str]]):
        
        if word == endWord:
            res.append(list(candidate))
            return
        
        for target in self.findNeighbors(word, visited, distances):
            if distances[target] != distances[word] + 1:
                continue
                       
            candidate.append(target)     
            visited.add(target)
            self.dfs(target, endWord, visited, distances, candidate, res)
            visited.remove(target)        
            candidate.pop()
            
    def findNeighbors(self, word: str, visited: set, distances: dict) -> [str]:
        
        res = []

        for i in range(len(word)):
            for char in 'abcdefghijklmnopqrstuvwxyz':
                if word[i] == char:
                    continue
                
                candidate = word[:i] + char + word[i + 1:]
                if candidate in visited:
                    continue
                    
                if candidate not in distances:
                    continue
                    
                res.append(candidate)
                
        return res
```

另一种风格，创建的树，只有上一层和下一层有关联，其他关联都被去掉了：

```python
from collections import defaultdict
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordset = set(wordList)
        if endWord not in wordset:
            return []

        tree = defaultdict(set)
        level = set([beginWord])
        found = False

        while len(level) > 0 and not found:
            wordset -= level
            new_level = set()
            
            for word in level:
                for i in range(len(word)):
                    for char in 'abcdefghijklmnopqrstuvwxyz':
                        candidate = word[:i] + char + word[i + 1:]
                        if candidate in wordset:
                            new_level.add(candidate)
                            tree[word].add(candidate)
                            found = candidate == endWord
                                
            level = new_level
    
        res = []
        self.dfs(beginWord, endWord, tree, [beginWord], res)
        return res
    
    def dfs(self, word: str, endWord: str, tree: dict[str : set], path: list[str], res:list[list[str]]):
        if word == endWord:
            res.append(list(path))
            return
            
        for candidate in tree[word]:
            path.append(candidate)
            self.dfs(candidate, endWord, tree, path, res)
            path.pop()
```

### 双端遍历

上述代码的搜索数量和分支数目+深度有关系，假设深度有4层，每一个节点有两个分支，那么从开始到结束，遍历节点数目 1 + 2 + 4 + 8 + 16 = 31

如果从两端开始 2 * (1 + 2 + 4) = 14, 遍历节点数目会少很多

​实际上，是哪一边分叉比较少，就从哪边开始遍历

```python
from collections import defaultdict
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordset = set(wordList)
        if endWord not in wordset:
            return []

        tree = defaultdict(set)
        front_level = set([beginWord])
        back_level = set([endWord])
        
        reverse = False
        found = False
        while len(front_level) > 0 and not found:
            
            wordset -= front_level
            new_level = set()
            
            for word in front_level:
                for i in range(len(word)):
                    for char in 'abcdefghijklmnopqrstuvwxyz':
                        candidate = word[:i] + char + word[i + 1:]
                        if candidate in wordset:
                            new_level.add(candidate)
                            found = candidate == endWord
                        
                            if reverse:
                                tree[candidate].add(word)
                            else:
                                tree[word].add(candidate)
                                
            front_level = new_level
            
            if len(front_level) < len(back_level):
                front_level, back_level = back_level, front_level
                reverse = not reverse
        
        res = []
        self.dfs(beginWord, endWord, tree, [beginWord], res)
        return res
    
    def dfs(self, word: str, endWord: str, tree: dict[str : set], path: list[str], res:list[list[str]]):
        if word == endWord:
            res.append(list(path))
            return
            
        for candidate in tree[word]:
            path.append(candidate)
            self.dfs(candidate, endWord, tree, path, res)
            path.pop()
```

## 宽度优先搜索(分层遍历)

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

# layer1
'hit' => [['hit']]

# layer2
'hot' => [['hit', 'hot']]

# layer3
'dot' => [['hit', 'hot', 'dot']]
'lot' => [['hit', 'hot', 'lot']]

# layer4
'dog' => [['hit', 'hot', 'dot', 'dog']]
'log' => [['hit', 'hot', 'lot', 'dog']]

# layer5
'cog' => [['hit', 'hot', 'dot', 'dog', 'cog'], ['hit', 'hot', 'lot', 'dog', 'cog']]
```

标准的BFS保存的是用队列保存的节点，这里用key=>value字典，表示到key为止，value记录有多少path

```python
from collections import defaultdict
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordset = set(wordList)
        if endWord not in wordset:
            return []

        res = []
        layer = {}
        layer[beginWord] = [[beginWord]]

        while len(layer) > 0:
            new_layer = defaultdict(list)

            for word in layer:
                if word == endWord:
                    return layer[word]
                else:
                    for i in range(len(word)):
                        for char in 'abcdefghijklmnopqrstuvwxyz':
                            candidate = word[:i] + char + word[i + 1:]
                            if candidate in wordset:
                                for path in layer[word]:
                                    new_layer[candidate].append(path + [candidate])
            
            wordset -= set(new_layer.keys())
            layer = new_layer
            
        return []
```

--End--