---
layout: post
index: 45
title: "LeetCode-45.跳跃游戏 II(Jump Game II)"
categories: Leetcode
tags: Leetcode Array Greedy
excerpt: "风之旅人"
---

* content
{:toc}

## 45. 跳跃游戏 II

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

```
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```

说明:

> 假设你总是可以到达数组的最后一个位置。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/jump-game-ii/](https://leetcode-cn.com/problems/jump-game-ii/)

Link：[https://leetcode.com/problems/jump-game-ii/](https://leetcode.com/problems/jump-game-ii/)

## 动态规划

O(N^2), 超时**Time Limit Exceeded**

定义dp[i], 代表跳到第i个石头所需要的次数

dp[0] = 0

dp[i] = dp[from] + 1, 其中from只能跳到i的石头

```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        
        dp = [float('inf') for i in range(len(nums))]
        dp[0] = 0
        
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[j] >= i - j and dp[i] > dp[j] + 1: # 能跳到i
                    dp[i] = dp[j] + 1
        
        return dp[-1]
```

## 贪心

O(N)

如果能跳到i, 那么一定能够跳跃到i之前的地方

以[2,3,1,1,4]为例;

```
    2    3    1    1    4     
    0         ^
   起始       最远
          check-point

    2    3    1    1    4     
         1              ^
                       最远
                    check-point

    2    3    1    1    4     
              2    ^
```

1. 起始点**i = 0, nums[i] = 2**, 最远能跳到**index = 2**, 记作**0 -> 2**
2. 那么(0, 2]范围内是一定可以到达的，那么看看，这些位置最远能跳到什么位置
3. 跳跃到记录的最远位置, 切换起始点与范围数值, 重复步骤1,2

```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        
        jumps = 0
        check_point = 0
        cur_furthest = 0

        for i in range(len(nums) - 1):
            cur_furthest = max(cur_furthest, i + nums[i])
            if (i == check_point):
                jumps += 1
                check_point = cur_furthest
        
        return jumps
```


--End--