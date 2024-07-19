---
layout: post
index: 115
title: "LeetCode-115.不同的子序列(Distinct Subsequences)"
categories: Leetcode
tags: Leetcode String DP
excerpt: "神秘海域"
---

* content
{:toc}

## 前言

以下关于动归的个人思考:

### 非连续：

比如子序列

前i个, 判断当前的节点是否要参与到方程式中

### 连续：

比如子数组，子串，窗口

以i为结尾，那么第i + 1个才有可能和i连续

## 115. 不同的子序列

给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。

示例 1：

```
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)
rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
```

示例 2：

```
输入：s = "babgbag", t = "bag"
输出：5
解释：
如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
(上箭头符号 ^ 表示选取的字母)
babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
```

提示：

```
0 <= s.length, t.length <= 1000
s 和 t 由英文字母组成
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/distinct-subsequences/](https://leetcode-cn.com/problems/distinct-subsequences/)

Link：[https://leetcode.com/problems/distinct-subsequences/](https://leetcode.com/problems/distinct-subsequences/)


## 动态规划

O(N^2)

### 状态定义

定义dp[i][j]为s前i个字符串与t前j个字符串有多少种可能

### 状态转移

```python
# 不使用s的第i个
dp[i][j] = dp[i - 1][j]

# 使用s的第i个, 但需要s[i - 1] == t[j - 1]
dp[i][j] += dp[i - 1][j - 1]
```

### 初始化

```python
   _  r  a  b  b  i  t
_ [1, 0, 0, 0, 0, 0, 0]
r [1, 0, 0, 0, 0, 0, 0]
a [1, 0, 0, 0, 0, 0, 0]
b [1, 0, 0, 0, 0, 0, 0]
b [1, 0, 0, 0, 0, 0, 0]
b [1, 0, 0, 0, 0, 0, 0]
i [1, 0, 0, 0, 0, 0, 0]
t [1, 0, 0, 0, 0, 0, 0]
```

第一列初始化为1, 也就是任何字符串都能和空串相匹配，且只有一种

### 计算方向

一列列从左到右计算

但由于矩阵的行列代表可能相反，如果反过来也可按照一行行计算


```python
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        
        dp = [[0 for i in range(len(t) + 1)] for j in range(len(s) + 1)]
        
        for i in range(len(s) + 1):
            dp[i][0] = 1
            
        for i in range(1, len(s) + 1):
            for j in range(1, len(t) + 1):
                
                dp[i][j] = dp[i - 1][j]
                
                if s[i - 1] == t[j - 1]:
                    dp[i][j] += dp[i - 1][j - 1]
                
        return dp[-1][-1]
```

--End--


