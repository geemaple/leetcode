---
layout: post
index: 97
title: "LeetCode-97.交错字符串(Interleaving String)"
categories: Leetcode
tags: Leetcode String DP
excerpt: "顺其自然"
---

* content
{:toc}

## 97. 交错字符串

给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

```python
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
# 提示：a + b 意味着字符串 a 和 b 连接。
```

示例 1：

![图片说明](./images/leetcode-algorithm-97.jpg)

```
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
```

示例 2：

```
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false
```

示例 3：

```
输入：s1 = "", s2 = "", s3 = ""
输出：true
```

提示：

```
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1、s2、和 s3 都由小写英文字母组成
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/interleaving-string](https://leetcode-cn.com/problems/interleaving-string)

Link：[https://leetcode.com/problems/interleaving-string/](https://leetcode.com/problems/interleaving-string/)

## 递归 + 记忆化搜索

我其实一直在纠结如何满足```|n - m| <= 1```条件, 但其实，两个字符串互相拼接，就自然满足条件。

这道题，挺难的，虽然2018年做了一遍，但是完全没有印象

```python
[1,2,3,4]

=>

[1 + 2 + 3 + 4]  # abs(4 - 3) <= 1
[+ 1 + 2 + 3 + 4]  # abs(4 - 4) <= 1
[+ 1 + 2 + 3 + 4 +] # abs(4 - 5) <= 1
```

例如想把上述链接起来，那么另一个要把每个元素都连接起来，

i, j分别代表已经有那些字母投入匹配了

```python
from functools import lru_cache
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        
        if len(s1) + len(s2) != len(s3):
            return False
        
        return self.helper(s1, 0, s2, 0, s3, '')
        
    @lru_cache(maxsize=None)
    def helper(self, s1: str, i: int, s2: str, j, s3: str, match: str) -> bool:
        
        if i == len(s1) and j == len(s2) and match == s3:
            return True
        
        if i < len(s1) and s1[i] == s3[i + j]:
            if self.helper(s1, i + 1, s2, j, s3, match + s1[i]):
                return True
        
        if j < len(s2) and s2[j] == s3[i + j]:
            if self.helper(s1, i, s2, j + 1, s3, match + s2[j]):
                return True

        return False
```

## 动态规划

### 状态定义

dp[i][j]定义s1的前i个字符 + s2的前j个字符和s3的前(i + j)匹配情况

### 状态转移 

```python

"-----" + "s1[i - 1]"
 i - 1       1

"-----------"
      j

"-----" + "-----------" + "s3[i + j - 1]"
 i - 1            j            1

# 如果s1[i - 1] == s3[i + j - 1] 并且 dp[i - 1][j]
dp[i][j] = True

"-----"
   i

"-----------" + "s2[j - 1]"
    j - 1            1

"-----" + "-----------" + "s3[i + j - 1]"
   i          j - 1             1

# 如果s2[j] == s3[i + j - 1] 并且 dp[i][j - 1]
dp[i][j] = True

```

### 初始条件

dp[0][0] = 0, s1前0个字符+s2前0个字符与s3前(0 + 0)个字符相匹配

### 计算方向

矩阵由左上到右下

```python
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        
        m = len(s1)
        n = len(s2)
        
        if m + n != len(s3):
            return False
        
        dp = [[False for j in range(n + 1)] for i in range(m + 1)]
        
        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 and j == 0:
                    dp[0][0] = True
                    continue
                    
                if i > 0 and s1[i - 1] == s3[i + j - 1] and dp[i - 1][j]:
                    dp[i][j] = True
                    
                if j > 0 and s2[j - 1] == s3[i + j - 1] and dp[i][j - 1]:
                    dp[i][j] = True
            
        return dp[-1][-1] 
```

--End--
