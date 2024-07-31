---
layout: post
index: 542
title: "LeetCode-542.01 矩阵(01 Matrix)"
categories: Leetcode
tags: Leetcode DFS BFS
excerpt: "不依赖工资生存挑战"
---

* content
{:toc}

## 前言

其实这道题是没有动归标签的，但是有人想出来了，佩服佩服

也是首次遇到多计算方向的动归

## 542. 01 矩阵

给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1：

```
输入：
[[0,0,0],
 [0,1,0],
 [0,0,0]]

输出：
[[0,0,0],
 [0,1,0],
 [0,0,0]]
```

示例 2：

```
输入：
[[0,0,0],
 [0,1,0],
 [1,1,1]]

输出：
[[0,0,0],
 [0,1,0],
 [1,2,1]]
```

提示：

```
给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/01-matrix/](https://leetcode-cn.com/problems/01-matrix/)

Link：[https://leetcode.com/problems/01-matrix/](https://leetcode.com/problems/01-matrix/)

## 宽度优先搜索

O(MN * MN)

### 暴力版本

求距离，从非0开始，一圈圈搜索直到找到最近的0

```python
from collections import deque
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        
        res = [[0 for j in range(len(matrix[i]))] for i in range(len(matrix))]
        
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 1:            
                    res[i][j] = self.nearestZero(matrix, i, j)
                
        return res
            
            
    def nearestZero(self, matrix: List[List[int]], i: int, j: int) -> int:
            
        # directions_x = [-1, 0, 1, 0]
        # directions_y = [0, 1, 0, -1]
        directions = [-1, 0, 1, 0, -1]
            
        queue = deque([(i, j)])
        visited = set([(i, j)])
        distance = 0
        
        while len(queue) > 0:
            
            count = len(queue)
            for _ in range(count):
                x, y = queue.popleft()
                
                if matrix[x][y] == 0:
                    return distance
                
                for i in range(4):
                    tx = x + directions[i]
                    ty = y + directions[i + 1]
                    if 0 <= tx < len(matrix) and 0 <= ty < len(matrix[0]) and (tx, ty) not in visited:
                        visited.add((tx, ty))
                        queue.append((tx, ty))
                        
            distance += 1
```

### 优化版本

默认0的距离为0，1的距离无穷大

将所有的0加入队列，向四周广度遍历，如果更近则更新距离，继续搜索，反之，说明有更近的0，就不用探索了

```python
from collections import deque
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        
        res = [[0 for j in range(len(matrix[i]))] for i in range(len(matrix))]
        queue = deque()
        
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                
                if matrix[i][j] == 0:
                    queue.append((i, j))
                else:
                    res[i][j] = float('inf')
                    
        # directions_x = [-1, 0, 1, 0]
        # directions_y = [0, 1, 0, -1]
        directions = [-1, 0, 1, 0, -1]         
        
        while len(queue) > 0:
            x, y = queue.popleft()
            
            for i in range(4):
                tx = x + directions[i]
                ty = y + directions[i + 1]
                
                if 0 <= tx < len(matrix) and 0 <= ty < len(matrix[0]) and res[tx][ty] > res[x][y] + 1:
                    queue.append((tx, ty))
                    res[tx][ty] = res[x][y] + 1
                    
        return res
```

## 动态规划

O(N^2)

### 状态定义

dp[i][j] 即是当前点到0的最小距离

### 状态转移

#### 左上到右下

```python
# 如果上边更小
dp[i][j] = dp[i - 1][j] + 1

# 如果左边更小
dp[i][j] = dp[i][j - 1] + 1
```

#### 右下到左上

```python
# 如果下边更小
dp[i][j] = dp[i + 1][j] + 1

# 如果右边更小
dp[i][j] = dp[i][j + 1] + 1
```

### 初始化

0的点的距离为0

### 计算方向

先左上到右下，再反过来，右下到左上

```python
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        
        dp = [[float('inf') for j in range(len(matrix[i]))] for i in range(len(matrix))]
        
        # 左上到右下
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                
                if matrix[i][j] == 0:
                    dp[i][j] = 0
                    continue
                    
                if i > 0:
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1)
                    
                if j > 0:
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1)
                    
        # 右下到左上   
        for i in reversed(range(len(matrix))):
            for j in reversed(range(len(matrix[i]))):
                
                if matrix[i][j] == 0:
                    dp[i][j] = 0
                    continue
                    
                if i + 1 < len(matrix):
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1)
                    
                if j + 1 < len(matrix[i]):
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1)
                
        return dp
```

--End--