---
layout: post
index: 28
title: "LeetCode-28.实现 strStr()(Implement strStr())"
categories: Leetcode
tags: Leetcode String TwoPointers
excerpt: "薛定谔的难度"
---

* content
{:toc}

## 28. 实现 strStr()

实现C语言中的strStr()函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串首次出现位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

```
输入: haystack = "hello", needle = "ll"
输出: 2
```

示例 2:

```
输入: haystack = "aaaaa", needle = "bba"
输出: -1
```

说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/implement-strstr/](https://leetcode-cn.com/problems/implement-strstr/)

Link：[https://leetcode.com/problems/implement-strstr/](https://leetcode.com/problems/implement-strstr/)

## 暴力破解

O(M*N)

```
逐个比较，如果不匹配，右移动一格

ABCDEFG    ->    ABCDEFG    ->    ABCDEFG    ->    ABCDEFG     
DEF               DEF               DEF               DEF
```

代码如下:

```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        
        if len(needle) > len(haystack):
            return -1
        
        index = 0
        for i in range(len(haystack) - len(needle) + 1):
            index = i
            for j in range(len(needle)):
                if needle[j] != haystack[i + j]:
                    index = -1
                    break
            
            if index == i:
                break
            
        return index
```

## Robin-karp算法

O(M + N), 如果哈希函数冲突很小的情况下, 不然就退化成暴力破解了

Robin-karp是对暴力破解的一个优化，将Pattern字符哈希取值。每次匹配只比较同长度字符串的哈希值。

如果哈希值相等，考虑到哈希冲突，需再次比较每一位字符。用来验证结果。

```
ABCDEFG
ABC    --哈希值-->   Hash(ABC)
 BCD    --哈希值-->   Hash(BCD)
  CDE    --哈希值-->   Hash(CDE)
   ...     

DEF    --哈希值-->   Hash(DEF)   
```

比较同长哈希值, 如果相等，逐个比较验证结果

```
hash(ABC)        hash(BCD)        hash(CDE)        hash(DEF) 
   !=               !=               !=               == (需验证结果)
hash(DEF)        hash(DEF)        hash(DEF)        hash(DEF)
   
ABCDEFG    ->    ABCDEFG    ->    ABCDEFG    ->    ABCDEFG
DEF               DEF               DEF               DEF
```

考虑到Hash的时间复杂度也是O(N), 那么这个过程，并没有优化时间复杂度，仍然是(M - N + 1）次比较, 每次哈希O(N)。

如果设计哈希函数如下, 就不必重复计算，每次去掉最高位，乘以K进制，再加上新的最低位

```
f(ABC) = A * K^2 + B * K^1 + C * K^0
f(BCD) =           B * K^2 + C * K^1 + D * K^0

存在递推关系:
f(BCD) = (f(ABC) - A * k^2) * k + D
```

令k=256进制, 代码如下:

```python
k_buckets = 131
k_characters = 256
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        
        m = len(haystack)
        n = len(needle)

        if n == 0:
            return 0

        if n > m:
            return -1

        target = 0
        tmp = 0
        high = 1

        for i in range(n - 1): # 最高位 = k ^ (n - 1)
            high = (high * k_characters) % k_buckets

        for i in range(n): # 初始Hash值
            tmp = (tmp * k_characters + ord(haystack[i])) % k_buckets
            target = (target * k_characters + ord(needle[i])) % k_buckets

        for i in range(m - n + 1):
            index = i
            if tmp == target:
                for j in range(n):
                    if haystack[i + j] != needle[j]:
                        index = -1
                        break

                if index == i:
                    return index

            if i < m - n:
                # 减去最高位的值tmp - haystack[i] * (k ^ (N - 1)), 结果乘以256, 再加上新的个位
                # 注意python中%不会出现负数，不需要额外处理
                tmp = ((tmp - ord(haystack[i]) * high) * k_characters  + ord(haystack[i + n])) % k_buckets

        return -1
```

--End--


