---
layout: post
index: 5
title: "LeetCode-5.最长回文子串(Longest Palindromic Substring)"
categories: Leetcode
tags: Leetcode String DP
excerpt: "Your shine is something like a mirror"
---

* content
{:toc}

## 5. 最长回文子串

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

```
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
```

示例 2：

```
输入: "cbbd"
输出: "bb"
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/longest-palindromic-substring/](https://leetcode-cn.com/problems/longest-palindromic-substring/)

Link：[https://leetcode.com/problems/longest-palindromic-substring/](https://leetcode.com/problems/longest-palindromic-substring/)

### 暴力破解

O(N^3), 时间超时

两次For循环, 判断是否是回文串，然后**打擂台**保存长度最大的结果。

```python

# s[start: stop] = s[start: end + 1]

class Solution:
    def longestPalindrome(self, s: str) -> str:
        start = 0
        end = -1
        for i in range(len(s)):
            for j in range(i, len(s)):
                if self.isPalindrome(s, i , j) and j - i + 1 > end - start + 1:
                    start = i
                    end = j

        return s[start : end + 1]
                    
    def isPalindrome(self, s: str, start: int, end: int) -> bool:
        while start <= end:
            if s[start] != s[end]:
                return False
            else:
                start += 1
                end -= 1
        return True
```

### 动态规划

O(N^2)

暴力的解法，问题在于有大量重复计算, 比如"acdca", "cdc",分别要单独计算。前者并没有利用后者的结论。

字符串长度=n, 开一个n * n的布尔矩阵, 用来记录从下标i 到 j 是否为回文串

#### 计算公式
```python
# s[start : end] 表示包含end 
# s[start : stop) 表示不包含stop

# 条件1 如果子串为空
s[start : end] = (s[start] == start[end])

# 条件2 如果子串不为空，使用table里面已经计算的值
s[start : end] = (s[start] == start[end] and table[start + 1][end - 1])
```

#### 初始条件

长度等于1的字符串，都是回文串，将table记录中对应标记True，如果将table视为矩阵，那么斜对角线都是True

#### 计算方向

从长度2开始，到长度n结束，这样才能利用上已经计算的值

#### 边界条件

如果判断字符串 < 2, 直接返回

子串为空的条件特殊判断

```python

class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        if len(s) < 2:
            return s
        
        start = 0
        end = 0
        
        n = len(s)
        table = [[True if i == j else False for j in range(n)] for i in range(n)]
        
        for l in range(2, n + 1): # 从长度2到n遍历
            for i in range(n - l + 1):
                j = i + l - 1
                
                if i + 1 > j - 1: # 如果子串为空
                    table[i][j] = s[i] == s[j]
                else:
                    table[i][j] = s[i] == s[j] and table[i + 1][j - 1]

                if table[i][j] and j - i + 1 > end - start + 1:
                    start = i
                    end = j
                        
        return s[start : end + 1]
```

### 字符拓展

O(N^2)

从回文串的特性, 可以从**单个字符**开始拓展，也可以从**空串**开始拓展

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 0:
            return ""
        
        longest = s[0]
        
        for t in range(len(s)):
            i = t - 1
            j = t + 1 
            # 单个字符，即奇数个，开始拓展
            while (i >= 0 and j < len(s) and s[i] == s[j]):
                length = j - i + 1
                if length > len(longest):
                    longest = s[i : j + 1]
                
                i -= 1
                j += 1
                    
            i = t - 1
            j = t
            # 空字符，即偶数个，开始拓展
            while (i >= 0 and j < len(s) and s[i] == s[j]):
                length = j - i + 1
                if length > len(longest):
                    longest = s[i : j + 1]
                i -= 1
                j += 1
                
        return longest
```

--End--


