---
layout: post
index: 67
title: "LeetCode-67.二进制求和(Add Binary)"
categories: Leetcode
tags: Leetcode Math String
excerpt: "牛德华牛逼"
---

* content
{:toc}

## 67. 二进制求和 

给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

示例 1:

```
输入: a = "11", b = "1"
输出: "100"
```

示例 2:

```
输入: a = "1010", b = "1011"
输出: "10101"
```
 
提示：

```
每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/add-binary](https://leetcode-cn.com/problems/add-binary)

Link：[https://leetcode.com/problems/add-binary/](https://leetcode.com/problems/add-binary/)

## 模拟加

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        
        carry = 0
        i = len(a) - 1
        j = len(b) - 1
        res = ''
        
        while i >= 0 or j >=0 or carry > 0:
            
            left = int(a[i]) if i >=0 else 0
            right = int(b[j]) if j >=0 else 0        
            val = left + right + carry
    
            res = str(val % 2) + res # str(val & 1) + res
            carry = val // 2 # val >> 1
            
            i -= 1
            j -= 1
            
        return res
```

## 题外话

### 为什么我要写这个公众号

我是2018年开始刷题的，当时LeetCode还没有过千，从同学那里得知FANNG面试比重非常大。

那个时候300来道题，在知乎上看到一篇问答《刷 LeetCode 吃力正常吗？》随手回答了一下，没想到点赞过千了。

学算法是非常反人类的事情，不只吃力这么简单，简直会怀疑自己根本不适合做计算机行业

300百虽然不多，但是回头看，还是挺有成就感的，甚至有些感动

这条路很艰难，每学会新的东西，都觉得这些只是基础

这里的分享，只是个人的标准，希望帮助到你

原稿博客: [http://geemaple.github.io/](http://geemaple.github.io/)

--End--