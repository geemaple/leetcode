---
layout: post
index: 43
title: "LeetCode-43.字符串相乘(Multiply Strings)"
categories: Leetcode
tags: Leetcode Math String
excerpt: "降龙十八掌"
---

* content
{:toc}

> 算法是屠龙之术，但世界上龙又有多少呢？

## 43. 字符串相乘

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

```
输入: num1 = "2", num2 = "3"
输出: "6"
```

示例 2:

```
输入: num1 = "123", num2 = "456"
输出: "56088"
```

说明：

1. num1 和 num2 的长度小于110。
2. num1 和 num2 只包含数字 0-9。
3. num1 和 num2 均不以零开头，除非是数字 0 本身。
4. 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/multiply-strings/](https://leetcode-cn.com/problems/multiply-strings/)

Link：[https://leetcode.com/problems/multiply-strings/](https://leetcode.com/problems/multiply-strings/)

## 模拟乘法

模拟一下我们小学学过的乘法运算

以**124 X 45**为例:

```
# 'nums[i] * nums[j]'的下标分别是'[i + j, i + j + 1]'

       1  2  3        2 => 下标 1
X         4  5        4 => 下标 0
---------------
          1  5
       1  0
    0  5
- - - - - - - -
       1  2 
    0  8              0 => 下标1, 8 => 下标2 
 0  4           
---------------
 0  5  5  3  5

[0, 1, 2, 3, 4]       下标
```

代码如下：

```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        m = len(num1)
        n = len(num2)
        
        pos = [0 for i in range(m + n)]
        
        for i in range(0, m)[::-1]:
            for j in range(0, n)[::-1]:
                
                mul = int(num1[i]) * int(num2[j])
                p1 = i + j
                p2 = i + j + 1
                
                add = mul + pos[p2]
                
                pos[p1] += add // 10
                pos[p2] = add % 10

        res = ''
        for digit in pos:
            if digit == 0 and len(res) == 0:
                continue
                
            res += str(digit)
        return '0' if len(res) == 0 else res
```

## 模拟乘法2

了解了第一个答案，那么其他的都看着比较容易

这个解法，只是把数字结果全都放在p2的位置

```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        m = len(num1)
        n = len(num2)
        
        pos = [0 for i in range(m + n)]
        
        for i in range(0, m)[::-1]:
            for j in range(0, n)[::-1]: 
                mul = int(num1[i]) * int(num2[j])
                pos[i + j + 1 ] += mul

        res = ''
        carry = 0
        for i in range(m + n)[::-1]:
            number = pos[i] + carry
            carry = number // 10
            pos[i] = number % 10

        res = ''
        for digit in pos:
            if digit == 0 and len(res) == 0:
                continue
            res += str(digit)

        return '0' if len(res) == 0 else res
```

--End--


