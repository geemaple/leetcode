---
layout: post
index: 64
title: "LeetCode-64.最小路径和(Minimum Path Sum)"
categories: Leetcode
tags: Leetcode Array DP
excerpt: "996ICU"
---

* content
{:toc}

## 64. 最小路径和

给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

```
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
```

来源：力扣（LeetCode）

链接：https://leetcode-cn.com/problems/minimum-path-sum/

Link：https://leetcode.com/problems/minimum-path-sum/

## 动态规划

O(MN)

### 思考步骤

遇上一题类似，最后一个只能从左边 or 上边到达

```
dp[x][y] = MIN(dp[x][y - 1], dp[x - 1][y]) + grid[x][y]
```

### 计算方向

从左上到右下

### 边界条件

```
dp[0][0] = grid[0][0]

top第一排:
dp[0][y] = dp[0][y-1] + grid[0][y]

left第一列
dp[x][0] = dp[x-1][0] + grid[x][0]
```

代码如下:

```python
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0
        
        m = len(grid)
        n = len(grid[0])
        
        dp = [[float('inf') for j in range(n)] for i in range(m)]
        
        for i in range(m):
            for j in range(n):
                
                if i == 0 and j == 0:
                    dp[i][j] = grid[i][j]
                    
                elif i == 0:
                    dp[i][j] = dp[i][j - 1] + grid[i][j]
                    
                elif j == 0:
                    dp[i][j] = dp[i - 1][j] + grid[i][j]
                
                else:
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]
                    
        return dp[-1][-1]
```

--End--