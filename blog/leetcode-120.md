---
layout: post
index: 120
title: "LeetCode-120.三角形最小路径和(Triangle)"
categories: Leetcode
tags: Leetcode Array DP
excerpt: "若不在低谷看到机会，可能就错过了"
---

* content
{:toc}

## 120. 三角形最小路径和

给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

示例 1：

```
输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
```

示例 2：

```
输入：triangle = [[-10]]
输出：-10
```

提示：

```
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
```

进阶：

你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/triangle/](https://leetcode-cn.com/problems/triangle/)

Link：[https://leetcode.com/problems/triangle/](https://leetcode.com/problems/triangle/)


## 动态规划

还是老样子，遇到三角形，先把它们左对齐

```python
2
3 4
6 5 7    
4 1 8 3  dp = [4, 1, 3, 8]
```

### 状态定义

定义dp[i]为到第N层第i个节点的最小路径和

### 状态转移

dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j]

### 初始化

dp = 最后一层

### 计算方向

从下到上

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        
        dp = list(triangle[-1])
        
        for i in reversed(range(len(triangle) - 1)):
            for j in range(len(triangle[i])):
                
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j]
                
        return dp[0]
```

当然了，如果可以更改triangle, 根本不用额外空间

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        
        dp = triangle[-1]
        
        for i in reversed(range(len(triangle) - 1)):
            for j in range(len(triangle[i])):
            
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j]
                
        return dp[0]
```

--End--


