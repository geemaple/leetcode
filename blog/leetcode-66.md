---
layout: post
index: 66
title: "LeetCode-66.加一(Plus One)"
categories: Leetcode
tags: Leetcode Array
excerpt: "教室那一间"
---

* content
{:toc}

## 66. 加一

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

```
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
```

示例 2:

```
输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/plus-one](https://leetcode-cn.com/problems/plus-one)

Link：[https://leetcode.com/problems/plus-one/](https://leetcode.com/problems/plus-one/)

## 模拟加

O(N)

### 加后反转

数组分别放入个位，十位，百位... 最后反转

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        
        carry = 1
        res = []
        index = len(digits) - 1
        
        while index >= 0 or carry > 0:
            digit = 0 if index < 0 else digits[index]
            val = digit + carry
            
            res.append(val % 10)
            carry = val // 10
            
            index -= 1
            
        return res[::-1]
```

### 加后拼接

[进位]? + [结果]

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        
        carry = 1
        index = len(digits) - 1
        
        while carry > 0 and index >= 0:

            val = digits[index] + carry

            digits[index] = val % 10
            carry = val // 10
            
            index -= 1
            
        return digits if carry == 0 else [carry] + digits
```

### 末尾追加

如果哪一位加一不需进位，+1直接返回 

如果是999..., 首位变成1, 末尾添加个0

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        
        for i in range(len(digits))[::-1]:
            
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] += 1
                return digits

        digits[0] = 1
        digits.append(0)
            
        return digits
```

--End--