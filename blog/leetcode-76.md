---
layout: post
index: 76
title: "LeetCode-76.最小覆盖子串(Minimum Window Substring)"
categories: Leetcode
tags: Leetcode HashTable TwoPointers String SlidingWindow
excerpt: "为了这一刻"
---

* content
{:toc}

## 76. 最小覆盖子串

给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，从字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

```
输入：S = "ADOBECODEBANC", T = "ABC"
输出："BANC"
```

提示：

```
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/minimum-window-substring](https://leetcode-cn.com/problems/minimum-window-substring)

Link：[https://leetcode.com/problems/minimum-window-substring](https://leetcode.com/problems/minimum-window-substring)

## 暴力破解

O(N^3), 遍历所有子字符串，判断是否匹配

## 滑动窗口

O(N)

使用双指针[start, end]来分别代表窗口大小, 用哈希checker来记录字母数量，remain来记录剩余要匹配的长度

1. 依次右移动end, 知道完全匹配目标t(checker计数全部<=0 **并且** remain==0)
2. 如果满足条件, 记录答案，右移动start, 恢复checker+remain, 然后移动start直到下一个可能的字母停下(也就是t中的任意一个)
3. 重复2, 然后继续执行1

⚠️注意checker里面计数经过0的时候的细节判断，以及remain的使用

代码如下:

```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
    
        checker = {}
        remain = len(t)
        start = 0
        res = ''
        
        for char in t:
            checker[char] = checker.get(char, 0) + 1
        
        for end in range(len(s)):
            char = s[end]
            if char in checker:
                checker[char] -= 1
                if checker[char] >= 0:
                    remain -= 1
                
            while remain == 0:
                if len(res) == 0 or end - start + 1 < len(res):
                    res = s[start: end + 1]
                    
                char = s[start]
                if char in checker:
                    checker[char] += 1
                    if checker[char] > 0:
                        remain += 1
                        
                start += 1

                # 开始:这两行可以删除, 个人偏好喜欢留着
                while start < len(s) and s[start] not in checker:
                    start += 1
                # 结束:这两行可以删除
                    
        return res
```

--End--
