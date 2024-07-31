---
layout: post
index: 74
title: "LeetCode-74.搜索二维矩阵(Search a 2D Matrix)"
categories: Leetcode
tags: Leetcode Array BinarySearch
excerpt: ""
---

* content
{:toc}

## 74. 搜索二维矩阵

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
 

示例 1：

![图片说明](./images/leetcode-algorithm-74-1.jpg)

```
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
输出：true
```

示例 2：

![图片说明](./images/leetcode-algorithm-74-2.jpg)

```
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
输出：false
```

示例 3：

```
输入：matrix = [], target = 0
输出：false
```
 
提示：

```
m == matrix.length
n == matrix[i].length
0 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/search-a-2d-matrix](https://leetcode-cn.com/problems/search-a-2d-matrix)

Link：[https://leetcode.com/problems/search-a-2d-matrix](https://leetcode.com/problems/search-a-2d-matrix)


## 暴力破解

O(M*N)

每个都遍历一遍，比较

## 行列排除

O(M + N)

取右上角, 和目标值做对比，能够排除一行或者一列

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
            
        m = len(matrix)
        n = len(matrix[0])
            
        i = 0
        j = n - 1
        
        while i < m and j >= 0:
            if matrix[i][j] == target:
                return True
                
            if matrix[i][j] > target:
                j -= 1
            else:
                i += 1
                
        return False
```

## 二分法

O(logK), K = M * N

把二维数组看作是一维的，然后二分

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
           
        m = len(matrix)
        n = len(matrix[0])
           
        left = 0
        right = m * n - 1
        
        while left < right:
            mid = left + (right - left) // 2
            
            if matrix[mid // n][mid % n] == target:
                return True
            
            if matrix[mid // n][mid % n] > target:
                right = mid
            else:
                left = mid + 1
                
        return matrix[left // n][left % n] == target
```

--End--