---
layout: post
index: 48
title: "LeetCode-48.旋转图像(Rotate Image)"
categories: Leetcode
tags: Leetcode Array
excerpt: "ZIV Hong"
---

* content
{:toc}

## 48. 旋转图像

给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在**原地**旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

![图片说明](./images/leetcode-algorithm-48-1.jpg)

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

示例 2:

![图片说明](./images/leetcode-algorithm-48-2.jpg)

```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

示例 3:

```
Input: matrix = [[1]]
Output: [[1]]
```

示例 4:

```
Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/rotate-image/](https://leetcode-cn.com/problems/rotate-image/)

Link：[https://leetcode.com/problems/rotate-image/](https://leetcode.com/problems/rotate-image/)

## 模拟法

O(N^2)

首先垂直旋转:

```
[1, 2, 3]      [7, 8, 9]

[4, 5, 6]  =>  [4, 5, 6]

[7, 8, 9]      [1, 2, 3]
``` 

然后从**左上**到**右下**对角线互换:

```
\
[7, 8, 9]       [7, 4, 1]
   \
[4, 5, 6]  =>   [8, 5, 2]
      \
[1, 2, 3]       [9, 6, 3]
         \
```

代码如下:

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        count = len(matrix)
        top = 0
        bottom = count - 1
        
        while top < bottom: # 垂直翻转
            matrix[top], matrix[bottom] = matrix[bottom], matrix[top]
            top += 1
            bottom -= 1
            
        for i in range(count): # 对角线翻转
            for j in range(i + 1, count):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
            
```

--End--