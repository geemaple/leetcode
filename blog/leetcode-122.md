---
layout: post
index: 122
title: "LeetCode-122.买卖股票的最佳时机 II(Best Time to Buy and Sell Stock II)"
categories: Leetcode
tags: Leetcode Array Greedy
excerpt: "贪婪与恐慌"
---

* content
{:toc}

## 122. 买卖股票的最佳时机 II

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

```
输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
```

示例 2:

```
输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
```

示例 3:

```
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```

提示：

```
1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii)

Link：[https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

## 贪心

O(N)

股票系列的题目标都是利润最大化，这一系列的题还是挺复杂的，因为交易可以做各种限制，比如不能同一天交易，最多能交易K次等等

```
x                             x
  x                         x   x
    x       x             x       x
      x   x   x         x
        x       x     x
                  x x  
        |-a-|       |----b----|
```

对于这个入门的题目，没有任何限制，在每个上升区间都可以获得利润

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        profit = 0
        
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]
        
        return profit
        
```

也可以只在最低点+最高点做买卖行动

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        profit = buy = sell = 0
        i = 0
        
        while i < len(prices) - 1:
            
            while i + 1 < len(prices) and prices[i + 1] <= prices[i]: # down
                i += 1
            buy = prices[i]
                
            while i + 1 < len(prices) and prices[i + 1] > prices[i]: # up
                i += 1
            sell = prices[i]
            
            profit += sell - buy
        
        return profit
```

--End--