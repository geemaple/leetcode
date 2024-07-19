---
layout: post
index: 633
title: "LeetCode-633.平方数之和(Sum of Square Numbers)"
categories: Leetcode
tags: Leetcode Math
excerpt: ""
---

* content
{:toc}

## 633. 平方数之和

给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。

示例 1：

```
输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5
```

示例 2：

```
输入：c = 3
输出：false
```

示例 3：

```
输入：c = 4
输出：true
```

示例 4：

```
输入：c = 2
输出：true
```

示例 5：

```
输入：c = 1
输出：true
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/sum-of-square-numbers](https://leetcode-cn.com/problems/sum-of-square-numbers)

Link：[https://leetcode.com/problems/sum-of-square-numbers/](https://leetcode.com/problems/sum-of-square-numbers/)

## 双指针

O(sqrt(N))

这个是Two Sum的变形题之一

```python
import math
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        
        low = 0
        high = int(math.sqrt(c))
        
        while low <= high:
            val = low * low + high * high
            if val == c:
                return True
            
            if val > c:
                high -= 1
            else:
                low += 1
                
                
        return False
```

--End--


