---
layout: post
index: 1725
title: "LeetCode-1725.可以形成最大正方形的矩形数目(Number Of Rectangles That Can Form The Largest Square)"
categories: Leetcode
tags: Leetcode Greedy
excerpt: "风犬少年"
---

* content
{:toc}

## 前言

贪心是个直觉的策略，好多的时候，不知不觉就会使用了

通常贪心是局部最优解，恰好也是全局最优解

但是动态规划就会比较反直觉，因为，如果是动归，应该能举个反例证明贪心是错的

做一个好的工匠，懂得贪心与动归的区别

## 1725. 可以形成最大正方形的矩形数目

给一个数组rectangles，其中 rectangles[i] = [li, wi] 表示第 i 个矩形的长度为 li 、宽度为 wi 。

如果存在 k 同时满足 k <= li 和 k <= wi ，就可以将第 i 个矩形切成边长为 k 的正方形。例如，矩形 [4,6] 可以切成边长最大为 4 的正方形。

设 maxLen 为可以从矩形数组 rectangles 切分得到的最大正方形的边长。

返回可以切出边长为 maxLen 的正方形的矩形个数。

示例 1：

```
输入：rectangles = [[5,8],[3,9],[5,12],[16,5]]
输出：3
解释：能从每个矩形中切出的最大正方形边长分别是 [5,3,5,5] 。
最大正方形的边长为 5 ，可以由 3 个矩形切分得到。
```

示例 2：

```
输入：rectangles = [[2,3],[3,7],[4,3],[3,7]]
输出：3
```

提示：

```
1 <= rectangles.length <= 1000
rectangles[i].length == 2
1 <= li, wi <= 109
li != wi
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/number-of-rectangles-that-can-form-the-largest-square](https://leetcode-cn.com/problems/number-of-rectangles-that-can-form-the-largest-square)

Link：[https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/](https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/)


## 模拟

代码本身就是对题干描述的模拟

```python
class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        
        squares = []
        maxlen = 0
        for pair in rectangles:
            length = min(pair)
            maxlen = max(maxlen, length)
            squares.append(length)
            
        count = 0
        for l in squares:
            if l == maxlen:
                count += 1
                
        return count
```

一遍For循环

```python
class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        count = 0
        maxlen = 0
        for pair in rectangles:
            length = min(pair)
            if maxlen < length:
                count = 1
                maxlen = length
            elif maxlen == length:
                count += 1
                
        return count
```

--End--


