---
layout: post
index: 73
title: "LeetCode-73.矩阵置零(Set Matrix Zeroes)"
categories: Leetcode
tags: Leetcode Array
excerpt: "教父"
---

* content
{:toc}

这题咋一看，还挺简单的，但是写起来，确实配得上Medium难度，尤其要求O(1)额外空间复杂度

## 73. 矩阵置零

给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

![图片说明](./images/leetcode-algorithm-73-1.jpg)

```
输入: 
[[1,1,1],[1,0,1],[1,1,1]]

输出: 
[[1,0,1],[0,0,0],[1,0,1]]
```

示例 2:

![图片说明](./images/leetcode-algorithm-73-2.jpg)

```
输入: 
[[0,1,2,0],[3,4,5,2],[1,3,1,5]]

输出: 
[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

进阶:

```
一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/set-matrix-zeroes](https://leetcode-cn.com/problems/set-matrix-zeroes)

Link：[https://leetcode.com/problems/set-matrix-zeroes/](https://leetcode.com/problems/set-matrix-zeroes/)

## 行列重置

O(M*N)

### 哈希

空间O(M + N)

```python
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = set()
        cols = set()
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)
                    
        for row in rows:
            for j in range(len(matrix[0])):
                matrix[row][j] = 0
                
        for col in cols:
            for i in range(len(matrix)):
                matrix[i][col] = 0
```

### 第一行列征用

空间O(1)

和上面一样, 我们用第一行+第一列置为零, 来记录rows+cols

第一行列, 需要额外的first_row+first_col来记录列,

先处理剩余部分, 再处理第一行列

```
左上角 ##################### cols
    #
    #
    #        剩余部分
    #
    #
 rows
```

```python
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
    
        first_row = first_col = False
        
        # 用第一行，第一列记录rows+cols
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    if i == 0:
                        first_row = True
                    if j == 0:
                        first_col = True
                        
                    matrix[0][j] = 0
                    matrix[i][0] = 0
          
        # 除了第一行列外
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        # 第一行    
        if first_row:
            for j in range(len(matrix[0])):
                matrix[0][j] = 0
            
        # 第一列
        if first_col:
            for i in range(len(matrix)):
                matrix[i][0] = 0
```

--End--