---
layout: post
index: 695
title: "LeetCode-695.岛屿的最大面积(Max Area of Island)"
categories: Leetcode
tags: Leetcode Array DFS
excerpt: ""
---

* content
{:toc}

## 695. 岛屿的最大面积

给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

示例 1:

```
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
```

示例 2:

```
[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。
```


来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/max-area-of-island/](https://leetcode-cn.com/problems/max-area-of-island/)

Link：[https://leetcode.com/problems/max-area-of-island/](https://leetcode.com/problems/max-area-of-island/)

## 宽度优先搜索

O(MN)

从一个点出发，进行宽度优先搜索，访问过的用0来标记, 注意宽度优先搜索使用**队列**，记得去重复

```python
from collections import deque
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        res = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    area = self.helper(grid, i, j)
                    res = max(res, area)
                    
        return res
        
        
    def helper(self, grid: List[List[int]], i: int, j: int) -> int:
        
        x_vector = [-1, 0, 1, 0]
        y_vector  = [0, 1, 0, -1]
        
        area = 0
        queue = deque([(i,j)])

        while len(queue) > 0:
            
            x, y = queue.popleft()
            area += 1

            for i in range(4):
                neighbor_x = x + x_vector[i]
                neighbor_y = y + y_vector[i]
                if 0 <= neighbor_x < len(grid) and 0 <= neighbor_y < len(grid[0]) and grid[neighbor_x][neighbor_y] == 1:
                    grid[neighbor_x][neighbor_y] = 0
                    queue.append((neighbor_x, neighbor_y))
            
        return area
```

## 深度优先搜索

O(MN)

从一个点出发，进行深度优先搜索，访问过的用0来标记, 注意宽度优先搜索使用**栈**，记得去重复

当然和可以用递归，递归优点通常是代码容易实现，方便回溯。缺点就是容易栈溢出。

⚠️注意，方向数组也可以用一维数组表示

```python
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        res = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    area = self.helper(grid, i, j)
                    res = max(res, area)
                    
        return res
        
        
    def helper(self, grid: List[List[int]], i: int, j: int) -> int:
        
        vector = [-1, 0, 1, 0, -1]
        
        area = 0
        stack = [(i,j)]

        while len(stack) > 0:
            
            x, y = stack.pop()
            area += 1

            for k in range(4):
                neighbor_x = x + vector[k]
                neighbor_y = y + vector[k + 1]
                if 0 <= neighbor_x < len(grid) and 0 <= neighbor_y < len(grid[0]) and grid[neighbor_x][neighbor_y] == 1:
                    grid[neighbor_x][neighbor_y] = 0
                    stack.append((neighbor_x, neighbor_y))
            
        return area
```

--End--


