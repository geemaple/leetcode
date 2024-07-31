---
layout: post
index: 1704
title: "LeetCode-1704.判断字符串的两半是否相似(Determine if String Halves Are Alike)"
categories: Leetcode
tags: Leetcode String
excerpt: "睡个好觉"
---

* content
{:toc}

## 1704. 判断字符串的两半是否相似

给你一个偶数长度的字符串 s 。将其拆分成长度相等的两半，前一半为 a ，后一半为 b 。

两个字符串 相似 的前提是它们都含有相同数目的元音（'a'，'e'，'i'，'o'，'u'，'A'，'E'，'I'，'O'，'U'）。注意，s 可能同时含有大写和小写字母。

如果 a 和 b 相似，返回 true ；否则，返回 false 。

示例 1：

```
输入：s = "book"
输出：true
解释：a = "bo" 且 b = "ok" 。如ab划线部分有相同的个数
           -          -
```

示例 2：

```
输入：s = "textbook"
输出：false
解释：a = "text" 且 b = "book" 。a有一个，b有两个，所以不相似
           -             --
```

示例 3：

```
输入：s = "MerryChristmas"
输出：false
```

示例 4：

```
输入：s = "AbCdEfGh"
输出：true
```

提示：

```
2 <= s.length <= 1000
s 由 大小写字母组成
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/determine-if-string-halves-are-alike](https://leetcode-cn.com/problems/determine-if-string-halves-are-alike)

Link：[https://leetcode.com/problems/determine-if-string-halves-are-alike/](https://leetcode.com/problems/determine-if-string-halves-are-alike/)


## 模拟

O(N)

使用一个函数来返回元音计数

```python
class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        
        k = len(s) // 2
        return self.vowelCount(s[:k]) == self.vowelCount(s[k:])
        

    def vowelCount(self, s: str) -> int:
        
        count = 0
        
        for c in s:
            if c in 'AaEeIiOoUu':
                count += 1
                
        return count
```

或者使用一个变量，来记录结果

```python
class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        
        vowels = set('AaEeIiOoUu')
        
        count = 0
        k = len(s) // 2
        for i in range(k):
            if s[i] in vowels:
                count += 1
                
            if s[i + k] in vowels:
                count -= 1
                
        return count == 0
```

--End--


