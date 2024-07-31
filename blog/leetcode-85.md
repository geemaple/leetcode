---
layout: post
index: 85
title: "LeetCode-85.最大矩形(Maximal Rectangle)"
categories: Leetcode
tags: Leetcode Array HashTable DP Stack
excerpt: "难上加难"
---

* content
{:toc}

## 85. 最大矩形

给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

![图片说明](./images/leetcode-algorithm-85.jpg) 

示例 1：

```
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。
```

示例 2：

```
输入：matrix = []
输出：0
```

示例 3：

```
输入：matrix = [["0"]]
输出：0
```

示例 4：

```
输入：matrix = [["1"]]
输出：1
```

示例 5：

```
输入：matrix = [["0","0"]]
输出：0
```

提示：

```
rows == matrix.length
cols == matrix.length
0 <= row, cols <= 200
matrix[i][j] 为 '0' 或 '1'
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/maximal-rectangle/](https://leetcode-cn.com/problems/maximal-rectangle/)

Link：[https://leetcode.com/problems/maximal-rectangle/](https://leetcode.com/problems/maximal-rectangle/)

## 动态规划 + 栈

O(M * N)

上一题, 有了一种计算最大长方形的办法, 那么一行行扫描, 从当前一行往上记录1的个数, 计算每个直方图中的最大矩形面积

```
# 第一排
|    1    0    1    0    0
--------------------------------
    [1,   0,   1,   0,   0]

# 第二排
|    1    0    1    0    0
|    1    0    1    1    1
--------------------------------
    [2,   0,   2,   1,   1]

# 第三排
|    1    0    1    0    0
|    1    0    1    1    1
|    1    1    1    1    1
--------------------------------
    [3,   1,   3,   2,   2]

# 第四排
|    1    0    1    0    0
|    1    0    1    1    1
|    1    1    1    1    1
|    1    0    0    1    0
--------------------------------
    [4,   0,   0,   3,   0]
```


### 递推公式

```
if matrix[row][j] == '1':
  dp[j] = matrix[row][j] + dp[j]
else:
  dp[j] = 0
```

### 计算方向

由上到下

### 边界条件

无

```python
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        
        row = len(matrix)
        col = len(matrix[0])
        
        res = 0
        dp = [0 for i in range(col)]
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == '1':
                    dp[j] += 1
                else:
                    dp[j] = 0
                    
            res = max(res, self.calculateArea(dp))
            
        return res
                    
                    
    def calculateArea(self, nums: List[int]) -> int:
        heights = nums + [-1]
        stack = []
        res = 0
        
        for i in range(len(heights)):
            while stack and heights[stack[-1]] > heights[i]:
                index = stack.pop()
                left = stack[-1] if stack else -1
                area = (i - left - 1) * heights[index]
                res = max(res, area)
        
            stack.append(i)
        
        return res
```

## 动态规划 + 三个数组

考虑切割的话, n个数有n + 1个分割点, 逐行扫描, 找到(右边界 - 左边界) * (高)，就可以计算面积

```
    |  1  |  0  |  1  |  0  |  0  |
    |  1  |  0  |  1  |  1  |  1  |
    |  1  |  1  |  1  |  1  |  1  |
    |  1  |  0  |  0  |  1  |  0  |
    ^     ^     ^     ^     ^     ^
    0th   1th   2th   3th   4th   5th

    其中, M * N = 4 * 5
```

### 状态定义

边界用切割点来表示, 从第ith高度出发，能够组成的最大面积

### 计算公式

以下dp更新都是考虑到上一行, 上一行作为等号的右值dp[j], 当前行作为等号的左值dp[j]

左边界, 计算时考虑上一行

```
left_bound = 0

如果matrix[i][j] == 1, left[j] = max(left[j], left_bound)

相反，左边界向右移动, left_bound = j + 1, 高度0的左边界重置为0
```

右边界，计算时考虑上一行

```
right_bound = N

如果matrix[i][j] == 1, right[j] = min(right[j], right_bound)

相反，有边界向左移动, right_bound = j, 高度0的右边界重置为N
```

高度，计算时考虑上一行

```
如果matrix[i][j] == 1, height[j] += 1

相反 height[j] = 0
```

### 初始化

left, height数组初始化为0

right数组初始化为N

### 边界条件

当元素为0时, left, height重置为0

当元素为0时, right重置为N

### 计算方向

逐行扫描

代码如下:

```python
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        
        m = len(matrix)
        n = len(matrix[0])
        
        height = [0 for i in range(n)]
        left = [0 for i in range(n)]
        right = [n for i in range(n)]
        
        res = 0
        
        for i in range(m):
            # 高度
            for j in range(n):
                if matrix[i][j] == '1':
                    height[j] += 1
                else:
                    height[j] = 0
                
            # 左边界
            left_boundry = 0
            for j in range(n):
                if matrix[i][j] == '1':
                    left[j] = max(left[j], left_boundry)
                else:
                    # left[j] = 0
                    left_boundry = j + 1
                    
            # 右边界
            right_boundry = n
            for j in range(n)[::-1]:
                if matrix[i][j] == '1':
                    right[j] = min(right[j], right_boundry)
                else:
                    # right[j] = n
                    right_boundry = j
                    
            # 面积
            for j in range(n):
                res = max(res, (right[j] - left[j]) * height[j])
                
        return res
```

--End--
