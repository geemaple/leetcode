---
layout: post
index: 14
title: "LeetCode-14.最长公共前缀(Longest Common Prefix)"
categories: Leetcode
tags: Leetcode String
excerpt: "多远都无畏"
---

* content
{:toc}

## 14. 最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

```
输入: ["flower","flow","flight"]
输出: "fl"
```

示例 2:

```
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
```

说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/longest-common-prefix/](https://leetcode-cn.com/problems/longest-common-prefix/)

Link：[https://leetcode.com/problems/longest-common-prefix/](https://leetcode.com/problems/longest-common-prefix/)

## 扫描法

O(N), 其中N等于所有字符串中的字符个数

### 水平扫描

假设答案=就是第一个字符串，然后从第二个开始，不断缩短答案，直到满足前缀的条件。在进行下一个

```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        if len(strs) == 0 or len(strs[0]) == 0:
            return ''
        
        res = strs[0]
        for i in range(1, len(strs)):            
            while not strs[i].startswith(res):
                res = res[0 : len(res) - 1]
            
        return res
```

### 垂直扫描

答案初始为空，所有字符串首字母对齐，想象有一条垂直的激光，由左到右扫描。直到发现不满足的条件停止

```python

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        if len(strs) == 0 or len(strs[0]) == 0:
            return ''
        
        res = ''
        for i in range(len(strs[0])):
            for j in range(1, len(strs)):
               if i >= len(strs[j]) or strs[j][i] != strs[0][i]:
                    return res
                
            res += strs[0][i]
            
        return res

```

## 排序法

排序整个字符串，然后找出(第一个+最后一个)公共前缀，因为这两个在排序结果中应该是差别最大的。

```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        if len(strs) == 0 or len(strs[0]) == 0:
            return ''
        
        strs.sort()
        first = strs[0]
        last = strs[-1]
    
        res = ''
        for i in range(len(first)):
            if first[i] == last[i]:
                res += first[i]
            else:
                break
            
        return res
```

## 其他思路

这道题，可能的考察点是，有几种解法

### Trie树

Trie(通常读作try)树, 也称为前缀树

该数据结构，也可以解决动态LCP(Longest Common Prefix), 多次重复调用问题

### 分治法

N个字符串(S1 ... SN)的答案 = (S1...SK)的答案 + (Sk+1 ... SN)的答案

### 二分答案法

将潜在答案S1二分，找到中间mid, 判断S1[0...mid]是否为其他字符串前缀

满足, 取mid右侧一部分

反之，取mid左侧一部分

最后，答案 = S1[0...mid]

--End--


