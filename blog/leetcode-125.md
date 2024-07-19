---
layout: post
index: 125
title: "LeetCode-125.验证回文串(Valid Palindrome)"
categories: Leetcode
tags: Leetcode TwoPointers String
excerpt: "CX330"
---

* content
{:toc}

## 前言

运气决定了人生的上限，努力决定了人生的下限

## 125. 验证回文串

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

```
输入: "A man, a plan, a canal: Panama"
输出: true
```

示例 2:

```
输入: "race a car"
输出: false
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/valid-palindrome/](https://leetcode-cn.com/problems/valid-palindrome/)

Link：[https://leetcode.com/problems/valid-palindrome/](https://leetcode.com/problems/valid-palindrome/)


## 双指针

O(N)

回文串，一般都是用双指针来处理的。这道题稍微特殊一点，只计算数字+字母，所以其他的跳过即可

第一种写法要注意，里面的while循环也要判断start < end, 以免出现越界的错误

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        lowercase = s.lower()
        
        start = 0
        end = len(lowercase) - 1
        
        while start < end:
            while start < end and not lowercase[start].isalnum():
                start += 1
                
            while start < end and not lowercase[end].isalnum():
                end -= 1
                
            if lowercase[start] != lowercase[end]:
                return False
            
            start += 1
            end -= 1
            
        return True
```

另一种写法:

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        lowercase = s.lower()
        
        start = 0
        end = len(lowercase) - 1
        
        while start < end:
            if not lowercase[start].isalnum():
                start += 1
            elif not lowercase[end].isalnum():
                end -= 1
            elif lowercase[start] == lowercase[end]:
                start += 1
                end -= 1
            else:
                return False

        return True
```

--End--