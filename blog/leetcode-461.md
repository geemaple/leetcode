---
layout: post
index: 461
title: "LeetCode-461.汉明距离(Hamming Distance)"
categories: Leetcode
tags: Leetcode BitManipulation
excerpt: ""
---

* content
{:toc}

## 461. 汉明距离

两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 231.

示例:

```
输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/hamming-distance/](https://leetcode-cn.com/problems/hamming-distance/)

Link：[https://leetcode.com/problems/hamming-distance/](https://leetcode.com/problems/hamming-distance/)


## 二进制

O(1)

将两个数字异或处理，然后统计有多少个'1'

**bits & (bits - 1)**能够打掉最低位数的**1**

```python
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:

        bits = x ^ y
        count = 0
        
        while bits > 0:
            bits = bits & (bits - 1)
            count += 1
            
        return count
```

右移最多32次就能够得到结果

```python
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        bits = x ^ y
        count = 0
        
        while bits > 0:
            if bits & 1 == 1:
                count += 1
            
            bits = bits >> 1
            
        return count
```

一行处理，凑个字数

```python
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x ^ y).count('1')
```

--End--


