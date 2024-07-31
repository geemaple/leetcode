---
layout: post
index: 63
title: "LeetCode-63.不同路径 II(Unique Paths II)"
categories: Leetcode
tags: Leetcode Array DP
excerpt: "Easy"
---

* content
{:toc}

## 63. 不同路径 II

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

![图片说明](./images/leetcode-algorithm-62.png)

网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

```
输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
```

来源：力扣（LeetCode）

链接：https://leetcode-cn.com/problems/unique-paths-ii/

Link：https://leetcode.com/problems/unique-paths-ii/

## 动态规划

O(MN)

### 思考步骤

最后一步，也就是终点，只能够从它的上边 or 左边到达

```
dp[x][y] = dp[x - 1][y] + dp[x][y - 1]
```

### 计算方向

从左上到右下

### 边界条件

```
dp[0][0] = 1
top第一排:

dp[0][y] = dp[0][y-1]

left第一列
dp[x][0] = dp[x-1][0]
```

### Follow Up

如果遇到障碍物，那么无法通行，记作为0，表示无法走通

代码如下:

```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        
        if len(obstacleGrid) == 0 or len(obstacleGrid[0]) == 0:
            return 0
        
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        
        dp = [[0 for j in range(n)] for i in range(m)]
        
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    continue
                
                if i == 0 and j == 0:
                    dp[i][j] = 1
                    
                elif i == 0:
                    dp[i][j] = dp[i][j - 1]
                    
                elif j == 0:
                    dp[i][j] = dp[i - 1][j]
                    
                else:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
                    
        return dp[-1][-1]
```

--End--