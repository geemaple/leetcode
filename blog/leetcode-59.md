---
layout: post
index: 59
title: "LeetCode-59. Spiral Matrix II"
categories: Leetcode
tags: Leetcode Array
excerpt: "Respect"
---

* content
{:toc}

![草稿说明](./images/leetcode-sketch-algorithm-59.png)

*三里屯Apple导购员和他的工作搭档, Respect!!!​*

## 59. 螺旋矩阵 II

给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

```
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```

## 回顾上一题

O(N^2)

之前的解法是，先把第一个填进结果。这次，我们直接遍历，但是把最后一个要记得放入数组

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []
        
        n = len(matrix)
        m = len(matrix[0])
        
        x_directions = [0, 1, 0, -1]
        y_directions = [1, 0, -1, 0]
            
        bounds = [0, m - 1, n - 1, 0]
        shrink_bounds = [1, -1, -1, 1]
            
        res = []
        x = y = 0
            
        while bounds[0] <= bounds[2] and bounds[3] <= bounds[1]:
            for k in range(4):
                while bounds[0] <= x + x_directions[k] <= bounds[2] and bounds[3] <= y + y_directions[k] <= bounds[1]:
                    res.append(matrix[x][y])
                    x += x_directions[k]
                    y += y_directions[k]

                bounds[k] += shrink_bounds[k]
        
        res.append(matrix[x][y])
        
        return res
```

## 模拟法

O(N^2)

```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0 for j in range(n)] for i in range(n)]
            
        x_directions = [0, 1, 0, -1]
        y_directions = [1, 0, -1, 0]
            
        bounds = [0, n - 1, n - 1, 0]
        shrink_bounds = [1, -1, -1, 1]
            
        x = y = 0
        count = 1
            
        while bounds[0] <= bounds[2] and bounds[3] <= bounds[1]:
            for k in range(4):
                while bounds[0] <= x + x_directions[k] <= bounds[2] and bounds[3] <= y + y_directions[k] <= bounds[1]:
                    res[x][y] = count
                    x += x_directions[k]
                    y += y_directions[k]
                    count += 1
                    
                bounds[k] += shrink_bounds[k]
        
        res[x][y] = count
        
        return res
```

--End--

来源：力扣（LeetCode）

链接：https://leetcode-cn.com/problems/spiral-matrix-ii/

Link：https://leetcode.com/problems/spiral-matrix-ii/
