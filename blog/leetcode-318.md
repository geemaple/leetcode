---
layout: post
index: 318
title: "LeetCode-318.最大单词长度乘积(Maximum Product of Word Lengths)"
categories: Leetcode
tags: Leetcode BitManipulation
excerpt: ""
---

* content
{:toc}

## 318. 最大单词长度乘积

给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

示例 1:

```
输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
输出: 16 
解释: 这两个单词为 "abcw", "xtfn"。
```

示例 2:

```
输入: ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4 
解释: 这两个单词为 "ab", "cd"。
```

示例 3:

```
输入: ["a","aa","aaa","aaaa"]
输出: 0 
解释: 不存在这样的两个单词。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/maximum-product-of-word-lengths](https://leetcode-cn.com/problems/maximum-product-of-word-lengths)

Link：[https://leetcode.com/problems/maximum-product-of-word-lengths/](https://leetcode.com/problems/maximum-product-of-word-lengths/)

## 哈希

O(N^2)
```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        
        res = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if len(set(words[i]) & set(words[j])) == 0:
                    res = max(res, len(words[i]) * len(words[j]))
        
        return res
```

加上预处理, 速度会快一些

```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        
        # 预处理
        word_sets = [set(word) for word in words]
        
        res = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if len(word_sets[i] & word_sets[j]) == 0:
                    res = max(res, len(words[i]) * len(words[j]))
        
        return res
```

## 比特位

O(N^2)

因为字母只有26个，所以可以使用比特位分别代表a-z字母。

判断有没有相同字符, 按位与==0

```python
from functools import lru_cache
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        
        res = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):

                if (self.wordToBit(words[i]) & self.wordToBit(words[j])) == 0:
                    res = max(res, len(words[i]) * len(words[j]))
        
        return res
    
    @lru_cache(maxsize=None)
    def wordToBit(self, word: str) -> int:
        num = 0
        for l in word:
            bits = ord(l) - ord('a')
            num |= 1 << bits

        return num
```

加上预处理, 速度会快一些

```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:
             
        mask = [0 for _ in range(len(words))]
        
        for i in range(len(words)):
            for c in words[i]:
                mask[i] |= 1 << (ord(c) - ord('a'))
                
        res = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if mask[i] & mask[j] == 0:
                    res = max(res, len(words[i]) * len(words[j]))
                    
        return res
```

--End--


