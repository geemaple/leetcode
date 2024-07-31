---
layout: post
index: 118
title: "LeetCode-118.杨辉三角(Pascal's Triangle)"
categories: Leetcode
tags: Leetcode Array
excerpt: "平凡才是唯一的答案"
---

* content
{:toc}

## 前言

感觉题刷的越多，越觉得自己平凡，就越需要努力来拯救

> 兄弟会背叛你，女人会离开你，金钱会诱惑你，生活会刁难你，只有数学不会，不会就是不会，怎么学都不会。

## 118. 杨辉三角

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

![图片说明](./images/leetcode-algorithm-118.gif)

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/pascals-triangle/](https://leetcode-cn.com/problems/pascals-triangle/)

Link：[https://leetcode.com/problems/pascals-triangle/](https://leetcode.com/problems/pascals-triangle/)

## 模拟

O(N^2)

```python
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
```

题目给的例子是首元素不堆砌的，尝试对齐再试试.

这样的话从第一个起**line[j] = last_line[j - 1] + last_line[j]**

这道题官方说是动归，但个人觉得有点像，但应该不是，题目说的比较清楚，杨辉三角就是这样一行行算的

```python
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        
        for i in range(numRows):
            
            line = [1 for _ in range(i + 1)]
            for j in range(1, len(line) - 1):
                line[j] = res[-1][j - 1] + res[-1][j]
                
            res.append(line)
            
        return res
```

--End--


