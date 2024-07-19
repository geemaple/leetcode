---
layout: post
index: 131
title: "LeetCode-131.分割回文串(Palindrome Partitioning)"
categories: Leetcode
tags: Leetcode DP Backtracking DFS
excerpt: "Every doge has its day"
---

* content
{:toc}

## 131. 分割回文串

给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。

示例 1：

```
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
```

示例 2：

```
输入：s = "a"
输出：[["a"]]
```

提示：

```
1 <= s.length <= 16
s 仅由小写英文字母组成
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/palindrome-partitioning](https://leetcode-cn.com/problems/palindrome-partitioning)

Link：[https://leetcode.com/problems/palindrome-partitioning](https://leetcode.com/problems/palindrome-partitioning)

## 深度优先搜索

O(N * 2^N)

```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        self.helper(s, [], 0, res)
        return res
        
    def helper(self, s: str, ans:List[str], start: int, res: List[List[str]]):
        if start == len(s):
            res.append(list(ans))
        
        for i in range(start, len(s)):
            test = s[start: i + 1]
            if self.isPalindrome(test):
                ans.append(test)
                self.helper(s, ans, i + 1, res)
                ans.pop()
        
    def isPalindrome(self, s: str) -> bool:
        start = 0
        end = len(s) - 1
        
        while start < end:
            if s[start] != s[end]:
                return False
            
            start += 1
            end -= 1
            
        return True
```

## 动态规划

O(N * 2^N), 少了一步回文判断

### 状态定义

定义dp[i][j]字符串从i到j是不是回文

### 状态转移

```python     
 'x'  +  abcddcba  +  'x'
         dp[i][j]
```

如果在原来是回文的基础上，左右是相同的字母，新的就是回文

### 边界条件

单个字母是回文

​两个字母若相等也是回文

### 计算方向

从长度2计算到长度

```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        
        dp = [[False for i in range(len(s))] for j in range(len(s))]
        
        for i in range(len(s)):
            dp[i][i] = True
            
        for j in range(len(s) - 1):
            dp[j][j + 1] = s[j] == s[j + 1]
            
        for k in range(2, len(s)):
            for i in range(len(s) - k):
                if s[i] == s[i + k]:
                    dp[i][i + k] = dp[i + 1][i + k - 1]
        
        res = []
        self.helper(s, [], 0, res, dp)
        return res
            
    def helper(self, s: str, ans:List[str], start: int, res: List[List[str]], dp: List[List[bool]]):
        if start == len(s):
            res.append(list(ans))
        
        for i in range(start, len(s)):
            test = s[start: i + 1]
            if dp[start][i]:
                ans.append(test)
                self.helper(s, ans, i + 1, res, dp)
                ans.pop()
```

--End--