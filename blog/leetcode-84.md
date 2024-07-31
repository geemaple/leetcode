---
layout: post
index: 84
title: "LeetCode-84.柱状图中最大的矩形(Largest Rectangle in Histogram)"
categories: Leetcode
tags: Leetcode Stack Array
excerpt: "疯狂的BTC"
---

* content
{:toc}

## 84. 柱状图中最大的矩形

给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

![图片说明](./images/leetcode-algorithm-84-1.png)

以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

![图片说明](./images/leetcode-algorithm-84-2.png)

图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

示例:

```
输入: [2,1,5,6,2,3]
输出: 10
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/largest-rectangle-in-histogram/](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)

Link：[https://leetcode.com/problems/largest-rectangle-in-histogram/](https://leetcode.com/problems/largest-rectangle-in-histogram/)

## 暴力破解

O(N^2)

从第i个开始, 分别向左右延展，看看以i为高度的长方形面积是多少

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
        res = 0
        
        for i in range(len(heights)):
            res = max(res, self.calculateMaxArea(heights, i))
            
        return res
        
    def calculateMaxArea(self, heights: List[int], index: int) -> int:
        
        start = end = index
        while start - 1 >= 0 and heights[start - 1] >= heights[index]:
            start -= 1
            
        while end + 1 < len(heights) and heights[end + 1] >= heights[index]:
            end += 1
            
        return (end - start + 1) * heights[index]
```

## 单调栈

O(N)

固定高，使用变长来计算最大面积

从左到右扫描，当heights[i]可以被计算面积的时候, 用O来表示

第一个高度是2, 第二个高度是1, 此时O部分的最大面积可以被确定

```
|
|                   #
|              #    #
|              #    #
|              #    #         #
|    #         #    #    #    #
|    #    #    #    #    #    #  
---------------------------------------
    [2,   1,   5,   6,   2,   3]
     ^

|
|                   #
|              #    #
|              #    #
|              #    #         #
|    O         #    #    #    #
|    O    #    #    #    #    #  
---------------------------------------
    [2,   1,   5,   6,   2,   3]
          ^
left      i
```

第3-4个的时候，面积都无法确认，继续

```
|
|                   #
|              #    #
|              #    #
|              #    #         #
|    O         #    #    #    #
|    O    #    #    #    #    #  
---------------------------------------
    [2,   1,   5,   6,   2,   3]
               ^    ^
```

第5个的时候，高度6最大面积可以确认

同时，高度5的面积，也可以确认下来

```
|
|                   O
|              #    O
|              #    O
|              #    O         #
|    O         #    O    #    #
|    O    #    #    O    #    #  
---------------------------------------
    [2,   1,   5,   6,   2,   3]
                         ^
              left       i
|
|                   O
|              O    O
|              O    O
|              O    O         #
|    O         O    O    #    #
|    O    #    O    O    #    #  
---------------------------------------
    [2,   1,   5,   6,   2,   3]
                         ^
         left            i
```

后扫描到的，先被计算，满足**栈**的特点。

同时，还未被计算的高度从小到高，满足**单点递增**(允许相同的情况)

此时末尾，没有更低的，我们加入一个**哨兵**-1，来计算剩余部分

代码如下:

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
        heights = heights + [-1]
        stack = []
        res = 0
        
        for i in range(len(heights)):
            while stack and heights[stack[-1]] > heights[i]:
                index = stack.pop()
                left = stack[-1] if stack else -1
                area = (i - left - 1) * heights[index]
                if res < area:
                    res = area
            
            stack.append(i)
            
        return res
```

--End--
