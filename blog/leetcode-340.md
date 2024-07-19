---
layout: post
index: 340
title: "LeetCode-340.至多包含K个不同字符的最长子串(Longest Substring with At Most K Distinct Characters)"
categories: Leetcode
tags: Leetcode HashTable TwoPointers String SlidingWindow
excerpt: ""
---

* content
{:toc}

## 340. 至多包含K个不同字符的最长子串

给一个字符串 s 和整数 k ， 要求返回最多由k个不同字符组成的最长子串

示例 1:

```
输入: s = "eceba", k = 2
输出: 3
解释: 子字符串 "ece" 长度为 3.
```

示例 2:

```
输入: s = "aa", k = 1
输出: 2
解释: 子字符串 "aa" 长度为 2.
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/](https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/)

Link：[https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)



## 双指针 + 哈希

使用双指针left + right作为一个滑动窗口，窗口内包含符合条件的字符串。

若不满足条件, 由移动left指针, 直到满足条件为止

```python
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        visited = {}
        
        res = 0
        i = 0
        for j in range(len(s)): 

            visited[s[j]] = visited.get(s[j], 0) + 1

            while len(visited) > k:
                visited[s[i]] -= 1
                if visited[s[i]] == 0:
                    del visited[s[i]]
                i += 1
                        
            res = max(res, j - i + 1)
            
        return res
```

--End--


