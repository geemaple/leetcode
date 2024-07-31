---
layout: post
index: 1720
title: "LeetCode-1720.解码异或后的数组(Decode XORed arrayay)"
categories: Leetcode
tags: Leetcode BitManipulation
excerpt: "Just do it"
---

* content
{:toc}

## 前言

好多事情，做了反而烦恼会少一些

而且很多事情，并不是你原本想象的需要大块时间才能开始

明天除夕了，但刷题永不停

## 1720. 解码异或后的数组

编码前的数组 array 由 n 个非负整数组成。

经编码后变为长度为 n - 1 的另一个整数数组 encoded ，其中 encoded[i] = array[i] XOR array[i + 1] 。例如，array = [1,0,2,1] 经编码后得到 encoded = [1,2,3] 。

给你编码后的数组 encoded 和原数组 array 的第一个元素 first（array[0]）

请解码返回原数组 array 。可以证明答案存在并且是唯一的。

示例 1：

```
输入：encoded = [1,2,3], first = 1
输出：[1,0,2,1]
解释：若 array = [1,0,2,1] ，那么 first = 1 且 encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
```

示例 2：

```
输入：encoded = [6,2,7,3], first = 4
输出：[4,2,0,7,4]
```

提示：

```
2 <= n <= 104
encoded.length == n - 1
0 <= encoded[i] <= 105
0 <= first <= 105
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/decode-xored-arrayay](https://leetcode-cn.com/problems/decode-xored-arrayay)

Link：[https://leetcode.com/problems/decode-xored-arrayay/](https://leetcode.com/problems/decode-xored-arrayay/)


## 二进制

O(N)

两个数字异或操作的结果，再和其中一个异或，总能得到另一个数字的值

```
C = A ^ B

A ^ C = A ^ A ^ B = 0 ^ B = B
```

代码如下:

```python
class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        res = [first]
        for num in encoded:
            res.append(res[-1] ^ num)
            
        return res
```

--End--


