---
layout: post
index: 680
title: "LeetCode-680.验证回文字符串 Ⅱ(Valid Palindrome II)"
categories: Leetcode
tags: Leetcode String
excerpt: ""
---

* content
{:toc}

## 680. 验证回文字符串 Ⅱ

给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

```
输入: "aba"
输出: True
```

示例 2:

```
输入: "abca"
输出: True
解释: 你可以删除c字符。
```

注意:

```
字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/valid-palindrome-ii/](https://leetcode-cn.com/problems/valid-palindrome-ii/)

Link：[https://leetcode.com/problems/valid-palindrome-ii/](https://leetcode.com/problems/valid-palindrome-ii/)

## 递归

O(N)

```
xxxx a...b xxxx
```

两端向中间比较, 直到遇到不相等的a != b, 删除a或者删除b

```python
class Solution:
    def validPalindrome(self, s: str) -> bool:
        
        return self.isValid(s, 0, len(s) - 1, 0)
        
        
    def isValid(self, s: str, left: int, right: int, delete: int) -> bool:
        
        if left >= right:
            return True
        
        if s[left] == s[right]:
            return self.isValid(s, left + 1, right - 1, delete)
        elif delete == 0:
            return self.isValid(s, left + 1, right, delete + 1) or self.isValid(s, left, right - 1, delete + 1)
        else:
            return False
```

## 双指针

O(N)

同上, 直到遇到不相等的a != b, 删除a或者删除b，判断剩余是否是回文串

代码有一种套娃的感觉

```python
class Solution:
    def validPalindrome(self, s: str) -> bool:
        
        left = 0
        right = len(s) - 1
        
        while left < right:
            if s[left] != s[right]:
                return self.isValid(s, left + 1, right) or self.isValid(s, left, right - 1)
            
            left += 1
            right -= 1
        
        return True
        
        
    def isValid(self, s: str, left: int, right: int) -> bool:
        
        while left < right:
            if s[left] != s[right]:
                return False
            
            left += 1
            right -= 1
            
        return True
```

--End--


