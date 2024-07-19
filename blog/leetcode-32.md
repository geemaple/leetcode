---
layout: post
index: 32
title: "LeetCode-32.最长有效括号(Longest Valid Parentheses)"
categories: Leetcode
tags: Leetcode String DP
excerpt: "It's Ok"
---

* content
{:toc}

## 32. 最长有效括号

给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

```
输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
```

示例 2:

```
输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/longest-valid-parentheses/](https://leetcode-cn.com/problems/longest-valid-parentheses/)

Link：[https://leetcode.com/problems/longest-valid-parentheses/](https://leetcode.com/problems/longest-valid-parentheses/)

## 暴力破解

O(N^3)

字符串的子串，有N^2个，然后依据[20. Valid Parentheses](http://geemaple.github.io/2020/07/28/leetcode-20/)来判断每一个子串是否有效, 每次判断时间复杂度O(N)

### 优化的暴力破解

O(N^2)

```
match == 0, # 代表已经全部匹配, 记录下答案
match > 0,  # 代表还有未匹配的左括号'('数量
match < 0,  # 代表左括号不足的数量，也就是right > left， 例如-1代表有括号')'多了一个
```

代码如下：

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        
        res = 0
        n = len(s)
        match = 0
            
        for i in range(len(s)):
            start = i
            for j in range(i, len(s)):
                if i == j:
                    match = 1 if s[j] == '(' else -1
                    
                elif s[j] == '(':
                    if match >= 0:
                        match += 1 
                    else:
                        start = j
                        match = 1
                elif s[j] == ')':
                    match -= 1
                    if match == 0 and j - start + 1 > res:
                        res = j - start  + 1

        return res
```

## 两遍扫描

O(N)

以```)()())```为例，图解一下上述优化的暴力破解的过程

```                            
 )    (    )    (    )    )
-1    1    0    1    0   -1     # i = 0, 已经算出答案
      1    0    1    0   -1     # i = 1, ❌重复计算
           -1   1    0   -1     # i = 2, ❌更短, 无需计算
                1    0   -1     # i = 3, ❌更短, 无需计算
                    -1   -2     # i = 4, ❌更短, 无需计算
                         -1     # i = 5, ❌更短, 无需计算         
# j = [i, len(s))
```

但是有一种情况例外，解决方案是反向扫描一遍

```
(    (    (    (    )
1    2    3    4    3     # 此时match不等于0, ❌拿不到答案
```

代码用**left+right**书写，比较直观清晰：

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        
        res = 0
        # 从左到右
        left = right = 0    
        for i in range(len(s)):
            if s[i] == '(':
                left += 1
            else:
                right += 1

            if left == right and right * 2 > res:
                res = right * 2
            elif right > left:
                left = right = 0

        # 从右到左
        left = right = 0   
        for i in range(len(s))[::-1]:
            if s[i] == ')':
                right += 1
            else:
                left += 1

            if left == right and right * 2 > res:
                res = right * 2
            elif left > right:
                left = right = 0

        return res
```

## 栈

O(N)

对于上述两遍扫描，可以用一个变量来**match**来存储左右括号的比较情况, match其实就是一个简化版本的栈, 

完整版的栈包含更多的存储信息，可以解决上述corner case:

首先: 栈可以消除最临近匹配的两个括号'()'，

其次: 没有匹配的字符串作为答案的边界, 可以计算答案的长度

最后: 用上哨兵节点, 代码写起来简单很多

### 栈的消消乐

```
LLLLLLL         RRRRRRR
       |  匹配  |
```

栈的思路是，如果匹配的括号在一起消失了, 那么它的左右边界还在，就可以计算长度

留一个哨兵**index = -1**，每一个多余的左括号'('的下标, 或者栈为空时右括号')'的下标，都成了新的哨兵

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        
        res = 0
        stack = [-1]
        
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if len(stack) == 0: #如果栈为空，说明右括号多了，那么右括号的index作为新的哨兵
                    stack.append(i)
                else:
                    if i - stack[-1] > res:
                        res = i - stack[-1]
                    
        return res

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        
        res = 0
        stack = [-1]
        
        for i in range(len(s)):
            top = stack[-1]
            if top != -1 and s[i] == ')' and s[top] == '(':
                stack.pop()
                if i - stack[-1] > res:
                    res = i - stack[-1]
            else:
                stack.append(i)
            
        return res
```

## 动态规划

O(N)

### 计算公式

定义以dp[i]为以i结尾的最长匹配字符串(包含i) 

```
# 1. 如果s[i] == '('

dp[i] = 0, 以'('结尾，不可能是答案

# 2. 如果s[i] == ')' and s[i - 1] == '('

S S S S S S S S S S S X X X X X X X ( )
                                      i
             x部分  =  | dp[i - 2] |

dp[i] = dp[i - 2] + 2 以'()'结尾

# 3. 如果s[i] == ')' 且 s[i - 1] == ')' 且 s[j] == '(‘

其中, j = i - dp[i - 1] - 1

S S S S S S S S S S ( X X X X X X X ) )
                                      i
                    j                  
       x部分+右括号  =  |  dp[i - 1]  |
|    dp[j - 1]    |  s[j]左侧部分

dp[i] = dp[j - 1] + dp[i - 1] + 2
```

### 边界条件

注意下标越界判断

### 初始条件

dp[0] = 0

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        
        if len(s) == 0:
            return 0
        
        dp = [0 for i in range(len(s))]
        
        for i in range(1, len(s)):
            if s[i] == ')':
                if s[i - 1] == '(':
                    dp[i] = dp[i - 2] + 2 if i -2 >= 0 else 2
                else:
                    j = i - dp[i - 1] - 1
                    if j >= 0 and s[j] == '(':
                        dp[i] = dp[i - 1] + 2
                        if j >= 1:
                            dp[i] += dp[j - 1]
                    
        return max(dp)
```

--End--


