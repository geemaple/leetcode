---
layout: post
index: 62
title: "LeetCode-62.不同路径(Unique Paths)"
categories: Leetcode
tags: Leetcode Array DP
excerpt: "高中数学"
---

* content
{:toc}

## 62. 不同路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

![图片说明](./images/leetcode-algorithm-62.png)

例如，上图是一个7 x 3 的网格。有多少可能的路径？

示例 1:

```
输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
```

示例 2:

```
输入: m = 7, n = 3
输出: 28
```

提示：

1 <= m, n <= 100
题目数据保证答案小于等于 2 * 10 ^ 9

来源：力扣（LeetCode）

链接：https://leetcode-cn.com/problems/unique-paths/

Link：https://leetcode.com/problems/unique-paths/

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

代码如下:

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        dp = [[0 for j in range(n)] for i in range(m)]
        
        for i in range(m):
            for j in range(n):
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

## 数学之美

O(K)

从左上走到右下，一共需要:

向右移动**m - 1**次

向下移动**n - 1**次

高中数学, N选K问题

```
  K
C
  N

k = min(m - 1, n - 1)
N = (m - 1) + (n - 1)

答案 = N选K问题, Combination(N, k) = n! / (k!(n - k)!)
```

⚠️注意可能计算中丢失精度问题

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        n = m - 1 + n - 1
        k = m - 1
        
        top = 1
        bottom = 1
        for i in range(k):
            top *= (n - i)
            bottom *= (i + 1)
            
        return top // bottom
```

--End--