---
layout: post
index: 42
title: "LeetCode-42.接雨水(Trapping Rain Water)"
categories: Leetcode
tags: Leetcode Array TwoPointers Stack
excerpt: "木桶效应"
---

* content
{:toc}

## 42. 接雨水

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

![图片说明](./images/leetcode-algorithm-42.png)

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

```
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/trapping-rain-water/](https://leetcode-cn.com/problems/trapping-rain-water/)

Link：[https://leetcode.com/problems/trapping-rain-water/](https://leetcode.com/problems/trapping-rain-water/)

## 两遍扫描

O(N)

如果下雨后能存下水，那么就需要有低洼处。能存水的量，取决于最短的的那个木桶

木桶是二维的，只需要考虑左右即可。后续有三维木桶的题目

```

   x
   x
   x
   x                        x
   x          ##            x
   x          ##            x       
---------------------------------
左边最高         i         右边最高
```

1. 从左到右扫描, 记录到扫描位置i为止，最高的左边
2. 从右到左扫描, 记录到扫描位置j为止，最高的右边

那么对于i, 左右最高点都知道了

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        
        lefts = [0 for i in range(len(height))]
        rights = [0 for i in range(len(height))]
        
        cur = 0
        for i in range(len(height)):
            cur = max(cur, height[i])
            lefts[i] = cur
              
        cur = 0
        for j in range(len(height))[::-1]:
            cur = max(cur, height[j])
            rights[j] = cur
            
        water = 0
        for i in range(len(height)):
            water += min(lefts[i], rights[i]) - height[i]
        
        return water
```

## 双指针

O(N)

对于坐标i处能存多少水, 只需要考虑**drops = min(left, right) - height[i]**, 累加即可

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        
        if len(height) < 2:
            return 0
        
        water = 0
        left = 0
        right = len(height) - 1
        left_boundry = height[left]
        right_boundry = height[right]
        
        while left < right:
            
            if height[left] > left_boundry:
                left_boundry = height[left]
                
            if height[right] > right_boundry:
                right_boundry = height[right]
                
            if left_boundry < right_boundry:
                water += left_boundry - height[left]
                left += 1
            else:
                water += right_boundry - height[right]
                right -= 1
                
        return water 
```

## 单调栈

O(N)

单调栈是**单调递减的栈**或者**单调递增的栈**

⚠️注意，该答案存储的水，是一层层计算的

使用单调非递增的栈。当不满足条件时，计算答案

以```[0,1,0,2,1,0,1,3,2,1,2,1]```为例:

```
第1步, 数字0入栈
[0]

第2步, 数字1, 不满足单调栈
[0], 1 => [1]

   x
----
0  1

第3步, 数字0入栈
[1, 0]

第4步, 数字2, 不满足单调栈, w += 1
[1, 0], 2 => [2]

      x
x  w  x
-------
1  0  2

第5步，数字1入栈
[2, 1]

第6步，数字0入栈
[2, 1, 0]

第7步，数字1, 不满足单调栈, w += 1
[2, 1, 0], 1 => [2, 1, 1]

x         
x  x  w  x  => 第一层计算
----------
2  1  0  1 

第8步，数字3, 不满足单调栈, w += 3， ⚠️注意是一层层算得，要计算(长 * 高)
[2, 1, 1], 3 => [3]

            x
x  w  w  w  x  => 第二层计算
x  x  x  x  x
-------------
2  1  0  1  3

第9步，数字2入栈
[3, 2]

第10步，数字1入栈
[3, 2, 1]

第11步，数字2，不满足单调栈，w += 1
[3, 2, 1], 2 => [3, 2, 2]

x        
x  x  w  x 
x  x  x  x
----------
3  2  1  3

第12步，数字1入栈
[3, 2, 2, 1]

```

代码如下：

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        stack = []
        water = 0
        j = 0
        while j < len(height):
            # 栈为空 or 满足递减条件
            if len(stack) == 0 or height[stack[-1]] >= height[j]:
                stack.append(j)
                j += 1
            else:
                bar = stack.pop()
                if len(stack) > 0:
                    i = stack[-1]
                    left_boundry = height[i]
                    right_boundry = height[j]
                    water += (min(left_boundry, right_boundry) - height[bar]) * (j - i - 1)

        return water
```

--End--


