---
layout: post
index: 198
title: "LeetCode-198.打家劫舍(House Robber)"
categories: Leetcode
tags: Leetcode DP
excerpt: "To rob or not to rob"
---

* content
{:toc}

## 前言

听讲的时候感觉真牛叉，然鹅，已经完全不会了，尤其是抢还是不抢，不知道还如何处理合适

那就，先说一个我觉得是动归，但是有点笨的方法。

## 198. 打家劫舍

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

示例 1：

```
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
```

示例 2：

```
输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
```

提示：

```
0 <= nums.length <= 100
0 <= nums[i] <= 400
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/house-robber](https://leetcode-cn.com/problems/house-robber)

Link：[https://leetcode.com/problems/house-robber/](https://leetcode.com/problems/house-robber/)

## ~~动态规划0x0~~

O(N^2)

### 状态定义

定义dp[i]是抢[0-i]房子🏠所获的的最大收益和，由于是最大收益，可以向后递推.

而且我们假设，第i个房子一定抢，相邻的肯定不能抢了，那之前的打擂台求一个最大值

### 状态转移

```python
dp[i] = nums[i] + max(dp[0], dp[1], dp[2], ... dp[i - 2])
```

### 初始状态

dp[0] = nums[0]
dp[1] = nums[0]

### 计算方向

从左到右

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        
        if len(nums) == 0:
            return 0
        
        dp = [n for n in nums]
        
        for i in range(2, len(nums)):
            for j in range(i - 1):
                dp[i] = max(dp[i], dp[j] + nums[i])
           
        return max(dp)
```

## 动态规划

O(N)

### 状态定义

定义dp[i]是前i个房子🏠抢夺所获的的最大收益，由于是最大收益，可以向后递推

第i个房子可以选择抢，或者，不抢。但两种情况记得取个**最大值**

⚠️注意，前i个房子的，的最后一个房子下表示i - 1

### 状态转移

```python
# 不抢
dp[i] = dp[i - 1]

# 抢
dp[i] = nums[i - 1] + dp[i - 2]
```

### 初始状态

dp[0] = 0, 意为前0个房子收益为0
dp[1] = nums[0]

### 计算方向

从左到右

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        
        if len(nums) == 0:
            return 0
        
        dp = [0 for i in range(len(nums) + 1)]
        dp[1] = nums[0]
        
        for i in range(2, len(nums) + 1):
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2])
            
        return max(dp)
```

--End--
