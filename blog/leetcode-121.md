---
layout: post
index: 121
title: "LeetCode-121.买卖股票的最佳时机(Best Time to Buy and Sell Stock)"
categories: Leetcode
tags: Leetcode Array DP
excerpt: "赚钱是一种能力"
---

* content
{:toc}

## 前言

买卖股票是一系列问题，从简单到困难都有。

## 121. 买卖股票的最佳时机

给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

示例 1：

```
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
```

示例 2：

```
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
```

提示：

```
1 <= prices.length <= 105
0 <= prices[i] <= 104
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock)

Link：[https://leetcode.com/problems/best-time-to-buy-and-sell-stock/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

## 暴力破解

O(N^2)

会超时的代码，题目要求，最多只能买一次，卖一次。

所以就是找到最大的**减去**前面最小的就可以了

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        profit = 0
        for i in range(len(prices)):
            for j in range(i, len(prices)):
                if prices[j] - prices[i] > profit:
                    profit = prices[j] - prices[i]
                    
        return profit
```

## 单调栈

O(N), 一个数字，两次操作，进栈一次，出栈一次，所以是2N

> 单调栈能够保存元素入栈的顺序，因为我们只需要后面的最高的，减去前面最小的就可以

单调栈是栈里面只保存递增的价格，当遇到小的价格，就要把之前的都pop掉，pop的时机判断下最大收益

为了保证能够清空栈内数据，最后放一个哨兵-1

代码如下:

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        profit = 0
        stack = []
        
        sentry_prices = prices + [-1]
        
        for price in sentry_prices:
            
            while len(stack) > 0 and price < stack[-1]:
                profit = max(profit, stack[-1] - stack[0])
                stack.pop()
                
            stack.append(price)
                
        return profit
```

## 动态规划

O(N)

### 状态定义

定义dp[i]是第i天获得的最大收益

### 状态转移

```python
# 第i天不操作, dp[i - 1]
# 第i天卖掉, prices[i] - lowest
dp[i] = max(dp[i - 1], prices[i] - lowest)
```

### 初始化

第一天最大收益dp[0] = 0

### 计算方向

从左到右

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        dp = [0 for i in range(len(prices))]
        low = prices[0]        
        
        for i in range(1, len(prices)):
            
            dp[i] = max(dp[i - 1], prices[i] - low)
            low = min(low, prices[i])
    
        return dp[-1]
```

压缩空间代码如下:

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        profit = 0
        low = float('inf')
        
        for price in prices:
            low = min(low, price)
            profit = max(profit, price - low)
            
        return profit
```

## One More Thing

```
7 - 7 = 0
1 - 7 = -6
5 - 1 = 4
3 - 5 = -2
6 - 3 = 3
4 - 6 = 2
```

如果把[7,1,5,3,6,4]变成相邻两天的差价[0, -6, 4, -2, 3, -2], 

就变成了求连续最大子数组问题, 参考LeetCode-53

--End--


