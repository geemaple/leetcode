---
layout: post
index: 49
title: "LeetCode-49.字母异位词分组(Group Anagrams)"
categories: Leetcode
tags: Leetcode String HashTable
excerpt: "B计划"
---

* content
{:toc}

## 49. 字母异位词分组

给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

```
输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```

说明：

所有输入均为小写字母。

不考虑答案输出的顺序。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/group-anagrams/](https://leetcode-cn.com/problems/group-anagrams/)

Link：[https://leetcode.com/problems/group-anagrams/](https://leetcode.com/problems/group-anagrams/)

## 排序+哈希

O(N * KlogK), N等于单词个数，K等于单词平均长度 

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        seen = {}
        res = []
        
        for word in strs:
            sort_word = ''.join(sorted(word))
            if sort_word in seen:
                index = seen[sort_word]
                res[index].append(word)
            else:
                ans = [word]
                index = len(res)
                res.append(ans)
                seen[sort_word] = index
                
        return res 
```

## 哈希

O(N * K), 理论上更快一些，python代码实际并不是

将字符串用数组表示, 例如: "eat"

```python
[a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z]
 1           1                                            1 
```

代码如下：

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        seen = {}
        res = []
        base = ord('a')
        
        for word in strs:
            word_count = [0 for i in range(26)] 
            for char in word:
                index = ord(char) - base
                word_count[index] += 1
            # ​换成tuple, 因为list是可变的, 不支持哈希
            word_count = tuple(word_count)
            
            if word_count in seen:
                index = seen[word_count]
                res[index].append(word)
            else:
                ans = [word]
                index = len(res)
                res.append(ans)
                seen[word_count] = index
                
        return res
```

--End--