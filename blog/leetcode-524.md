---
layout: post
index: 524
title: "LeetCode-524.通过删除字母匹配到字典里最长单词(Longest Word in Dictionary through Deleting)"
categories: Leetcode
tags: Leetcode TwoPointers Sort
excerpt: ""
---

* content
{:toc}

## 524. 通过删除字母匹配到字典里最长单词

给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。

示例 1:

```
输入:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

输出: 
"apple"
```

示例 2:

```
输入:
s = "abpcplea", d = ["a","b","c"]

输出: 
"a"
```

说明:

```
所有输入的字符串只包含小写字母。
字典的大小不会超过 1000。
所有输入的字符串长度不会超过 1000。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting)

Link：[https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)

## 双指针

O(K * KNlogK)

对于普通快排，数字值比较一次即可判断大小，复杂度=O(N * logN)

但是对于长度为l的字符串排序，字符串比较l次才能判断大小，复杂度O(lN * logN)

先排个序，这样在遇到相等的时候，可以返回字典序最小的结果

然后用双指针判断两个，字符串能否转换。类似于归并两个有序数组

```python
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        
        res = ''
        d.sort()
        for target in d:
            if self.canForm(s, target):
                if len(res) < len(target):
                    res = target
                    
        return res
        
    def canForm(self, source: str, target: str) -> bool:
        if len(source) < len(target):
            return False
        
        i = j = 0
        while i < len(source) and j < len(target):
            if source[i] != target[j]:
                i += 1
            else:
                i += 1
                j += 1
        
        return j == len(target)
```

O(KN)

可以不排序，只有在相等的时候，在比较两个字符串

```python
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        
        res = ''
        for target in d:
            if self.canForm(s, target) and len(res) <= len(target):
                if len(res) < len(target) or target < res:
                    res = target
                    
        return res
    
    def canForm(self, source: str, target: str) -> bool:
        if len(source) < len(target):
            return False
        
        i = j = 0
        while i < len(source) and j < len(target):
            if source[i] != target[j]:
                i += 1
            else:
                i += 1
                j += 1
        
        return j == len(target)
```

--End--


