---
layout: post
index: 87
title: "LeetCode-87.扰乱字符串(Scramble String)"
categories: Leetcode
tags: Leetcode String DP
excerpt: "里程对于滑雪是很重要的"
---

* content
{:toc}

> 这道题中文版翻译的已经有一部分提示了，还把树的结构给画了出来。英文版新版只给了两个转换规则

```
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
```

## 87. 扰乱字符串

给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。

下图是字符串 s1 = "great" 的一种可能的表示形式。

```
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
```

在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。

```
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
```

我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。

```
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
```

我们将 "rgtae” 称作 "great" 的一个扰乱字符串。

给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

示例 1:

```
输入: s1 = "great", s2 = "rgeat"
输出: true
```

示例 2:

```
输入: s1 = "abcde", s2 = "caebd"
输出: false
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/scramble-string](https://leetcode-cn.com/problems/scramble-string)

Link：[https://leetcode.com/problems/scramble-string/](https://leetcode.com/problems/scramble-string/)

## 暴力破解

O(5^N)

如果切割，使得原字符串与目标字符串分别**左右相等**或者**交叉相等**, 就说明能够转换成功

这里需要保证，每次递归调用函数，两个入参长度相等，len(s1) == len(s2)

```
# 分割不交换
left     right

 ｜        ｜ 
 
left     right

# 分割交换
left  |  right
    \   /
      X
    /   \
left  |  right
```

### 代码实现

```python
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        
        length = len(s1)
        for k in range(1, length):
            if self.isScramble(s1[0 : k], s2[0 : k]) and self.isScramble(s1[k : length], s2[k : length]):
                return True
            
            if self.isScramble(s1[0 : k], s2[length - k : length]) and self.isScramble(s1[k : length], s2[0 : length - k]):
                return True
```

### 时间复杂度

```
# for循环中判断时间 = T(K) + T(N - K), 一共有两个判断x2
T(N) = for k in 1...n-1: 2 * (T(k) + T(N - k))

     = 2(T(1) + T(N - 1) + T(2) + T(N - 2) + ... + T(N - 1) + T(1))

     = 2 * 2(T(1) + T(2) + ... + T(N - 1))

     = 4(T(1) + T(2) + ... + T(N - 1))

# 同理, 替换下面左边部分
T(N - 1) = 4(T(1) + T(2) + ... + T(N - 2))

     = 4(T(1) + T(2) + ... + T(N - 2)) + 4T(N - 1)

     = T(N - 1) + 4T(N - 1)

     = 5T(N - 1)

# 所以
T(N) = 5 * T(N - 1) = 5^2 * T(N - 2) = 5 ^ N * T(1) = 5^N
```

## 递归 + 记忆化搜索 + 剪枝

剪枝: 只是在暴力搜索的过程中，如果能够提前判断结果，比如"aab", "aac"里面字符个数不相等, 就不用再判断了

记忆化搜索: 是指可能出现重复的调用过程，使用缓存来记录(入参1, 入参2) -> (结果), 就不用再计算一遍了

理论上: 搜索 + 记忆化搜索 = 动态规划

⚠️剪枝能够提高搜索效率，但是理论的时间复杂度并没有减少，可以假设一个Case，每次判断都能通过剪枝拦截

```python
from functools import lru_cache
from collections import Counter
class Solution:
    @lru_cache(maxsize=None) # 记忆化搜索
    def isScramble(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        
        # 剪枝
        if Counter(s1) != Counter(s2):
            return False

        length = len(s1)
        for k in range(1, length):
            if self.isScramble(s1[0 : k], s2[0 : k]) and self.isScramble(s1[k : length], s2[k : length]):
                return True
            
            if self.isScramble(s1[0 : k], s2[length - k : length]) and self.isScramble(s1[k : length], s2[0 : length - k]):
                return True
```

## 动态规划

### 状态定义

dp[i][j][k], 定义**同长度的**s1[i : i + k], s2[j : j + k]是否可以成功转换

### 状态转换

```
# 左右分别可转换
s1 [    left1    |        right1        ]
   i             i + cut                i + k -1

         |                  |            

s2 [    left2    |        right2        ]
   j             j + cut                j + k - 1


dp[i][j][k] = (dp[i][j][cut] and dp[i + cut][j + cut][k - cut])

# 左右交叉可转换
s1 [    left1    |        right1        ]
   i             i + cut                i + k -1

                 \   /
                   X
                 /   \

s2 [        left2        |    right2    ]
   j                     j + k - cut   j + k - 1


dp[i][j][k] = (dp[i][j + k - cut][cut] and dp[i + cut][j][k - cut])
```

### 计算方向

字符串k = 1到N

### 边界条件

长度k从1开始，所以开数组的时候要多一位

当k = 1时，只要判断单个字符串是否相等即可

```python
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        length = len(s1)
        dp = [[[False for _ in range(length + 1)] for _ in range(length)] for _ in range(length)]

        # length = 1
        for i in range(length):
            for j in range(length):
                dp[i][j][1] = (s1[i] == s2[j])

        for k in range(2, length + 1):
            for i in range(length - k + 1):
                for j in range(length - k + 1):
                    for cut in range(1, k - 1 + 1):

                        if (dp[i][j][cut] and dp[i + cut][j + cut][k - cut]):
                            dp[i][j][k] = True
                            break

                        if (dp[i][j + k - cut][cut] and dp[i + cut][j][k - cut]):
                            dp[i][j][k] = True
                            break

        return dp[0][0][length]
```

--End--
