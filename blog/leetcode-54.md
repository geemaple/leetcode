---
layout: post
index: 54
title: "LeetCode-54.螺旋矩阵(Spiral Matrix)"
categories: Leetcode
tags: Leetcode Array
excerpt: "一将功成万骨枯"
---

* content
{:toc}

## 54. 螺旋矩阵

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

```
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
```

示例 2:

```
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/spiral-matrix/](https://leetcode-cn.com/problems/spiral-matrix/)

Link：[https://leetcode.com/problems/spiral-matrix/](https://leetcode.com/problems/spiral-matrix/)

## 模拟法

O(M*N)

这道题，只要按照既定方向(上，右，下，左)取值即可

正常情况下, 每一圈, 需要有4个for循环，来遍历各个方向

如果采用方向数组 + 边界数组, 代码会缩短一些

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []
        
        # 方向数组
        x_directions = [0, 1, 0, -1]
        y_directions = [1, 0, -1, 0]
        shrink_bounds = [1, -1, -1, 1]
        
        # 上右下左
        bounds = [0, len(matrix[0]) - 1, len(matrix) - 1, 0]
        res = []
        
        i = j = 0
        res.append(matrix[i][j])
        
        while bounds[0] <= bounds[2] and bounds[3] <= bounds[1]:
    
            for k in range(4):
                while bounds[0] <= i + x_directions[k] <= bounds[2] and bounds[3] <= j + y_directions[k] <= bounds[1]:
                    i += x_directions[k]
                    j += y_directions[k]
                    res.append(matrix[i][j])
                
                bounds[k] += shrink_bounds[k]
            
        return res
```


--End--
