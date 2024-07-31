---
layout: post
index: 1716
title: "LeetCode-1716.计算力扣银行的钱(Calculate Money in Leetcode Bank)"
categories: Leetcode
tags: Leetcode Math Greedy
excerpt: "新年快乐"
---

* content
{:toc}

## 前言

比特都4万了，这个世界还能再疯狂点不

## 1716. 计算力扣银行的钱

Hercy 想要为买人生第一辆车存钱。他每天都往银行里存钱。

最开始，他在周一的时候存入 1 块钱。从周二到周日，他每天都比前一天多存入 1 块钱。在接下来每一个周一，他都会比 前一个周一 多存入 1 块钱。

给你 n ，请你返回在第 n 天结束的时候他在银行总共存了多少块钱。

 
示例 1：

```
输入：n = 4
输出：10
解释：第 4 天后，总额为 1 + 2 + 3 + 4 = 10 。
```

示例 2：

```
输入：n = 10
输出：37
解释：第 10 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37 。注意到第二个星期一，Hercy 存入 2 块钱。
```

示例 3：

```
输入：n = 20
输出：96
解释：第 20 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96 。
```

提示：

```
1 <= n <= 1000
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/calculate-money-in-leetcode-bank](https://leetcode-cn.com/problems/calculate-money-in-leetcode-bank)

Link：[https://leetcode.com/problems/calculate-money-in-leetcode-bank/](https://leetcode.com/problems/calculate-money-in-leetcode-bank/)


## 周计算

一周一周算，使用等差数列求和公式

```python
class Solution:
    def totalMoney(self, n: int) -> int:
        
        week = n // 7
        day = n % 7 
        res = 0
        
        # 计算整周
        for nth in range(week):
            res += (nth + 1 + nth + 7) * 7 // 2
        
        # 计算剩余天数
        res += (week + 1 + week + day) * day // 2
        
        return res
```

## 数学

```python
 1,  2,  3,  4,  5,  6,  7,     # 28 + 7 * 0
 2,  3,  4,  5,  6,  7,  8,     # 28 + 7 * 1
 3,  4,  5,  6,  7,  8,  9,     # 28 + 7 * 2
 4,  5,  6,  7,  8,  9, 10,     # 28 + 7 * 3
```

也就是, 28 * 整周数 + 7 * (0 + 1 + 2 + 3 ... k)

```python
class Solution:
    def totalMoney(self, n: int) -> int:
        
        week = n // 7
        day = n % 7 
        res = 0
        
        res += 28 * week + 7 * (week - 1) * week // 2
        res += (week + 1 + week + day) * day // 2
        
        return res
```

--End--


