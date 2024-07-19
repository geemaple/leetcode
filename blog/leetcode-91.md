---
layout: post
index: 91
title: "LeetCode-91.解码方法(Decode Ways)"
categories: Leetcode
tags: Leetcode String DP
excerpt: "Carry On My Wayward Son"
---

* content
{:toc}

## 91. 解码方法

一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

题目数据保证答案肯定是一个 32 位的整数。

示例 1：

```
输入：s = "12"
输出：2
解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
```

示例 2：

```
输入：s = "226"
输出：3
解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
```

示例 3：

```
输入：s = "0"
输出：0
```

示例 4：

```
输入：s = "1"
输出：1
```

示例 5：

```
输入：s = "2"
输出：1
```
 
提示：

```
1 <= s.length <= 100
s 只包含数字，并且可能包含前导零。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/decode-ways/](https://leetcode-cn.com/problems/decode-ways/)

Link：[https://leetcode.com/problems/decode-ways/](https://leetcode.com/problems/decode-ways/)


## 递归 + 记忆化搜索

由于python的强大，加一个lru_cache就可以了

动态规划的本质是，从一个方向递推，防止重复计算，所以递归+记忆化搜索，也是一种动态规划

```python
from functools import lru_cache
class Solution:
    @lru_cache(maxsize=None)
    def numDecodings(self, s: str) -> int:
        if len(s) == 0 or s[0] == '0':
            return 0

        if len(s) == 1 and 1 <= int(s[0]) <= 9:
            return 1

        if len(s) == 2 and 10 <= int(s[0:2]) <= 26:
            return 1 if s[-1] == '0' else 2

        count = 0
        if 1 <= int(s[-1]) <= 9: # 末尾一个字符
            count += self.numDecodings(s[:-1]) # 去掉末尾一个字符
        
        if 10 <= int(s[-2:]) <= 26: #末尾两个字符
            count += self.numDecodings(s[:-2]) # 去掉末尾两个字符

        return count
```

代码是对称的

```python
from functools import lru_cache
class Solution:
    @lru_cache(maxsize=None)
    def numDecodings(self, s: str) -> int:
        if len(s) == 0 or s[0] == '0':
            return 0

        if len(s) == 1 and 1 <= int(s[0]) <= 9:
            return 1

        if len(s) == 2 and 10 <= int(s[0:2]) <= 26:
            return 1 if s[-1] == '0' else 2

        count = 0
        if 1 <= int(s[0]) <= 9: # 前一个字符
            count += self.numDecodings(s[1:]) # 去掉前一个字符
        
        if 10 <= int(s[:2]) <= 26: # 前两个字符
            count += self.numDecodings(s[2:]) # 去掉前两个字符

        return count
```


## 动态规划

### 状态定义

dp[i]代表前i个字符串有多少种解码方式

### 状态方程

如果最后数字，可以作为1位数解码(1-9)
```
table[i] += table[i - 1]
```

如果最后两位数，可以作为2位数解码(10-26)
```
table[i] += table[i - 2]
```

### 计算方向

从第二个开始，从小到大计算

### 边界条件

如果第一个数字为0

```
table[0] = table[1] = 0
```

相反

```
table[0] = table[1] = 1
```

### 代码实现

```python
class Solution:
    def numDecodings(self, s: str) -> int:
        dp = [0 for i in range(len(s) + 1)]
        dp[0] = dp[1] = 0 if s[0] == '0' else 1
        
        for i in range(2, len(s) + 1):
            if s[i - 1] != '0':
                dp[i] += dp[i - 1]
                
            if (s[i - 2] == '1' and s[i - 1] in '0123456789') or (s[i - 2] == '2' and s[i - 1] in '0123456'):
                dp[i] += dp[i - 2]
                
        return dp[-1]
```

--End--
