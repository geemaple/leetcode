---
layout: post
index: 1710
title: "LeetCode-1710.卡车上的最大单元数(Maximum Units on a Truck)"
categories: Leetcode
tags: Leetcode Greedy Sort
excerpt: "当下是最好的礼物"
---

* content
{:toc}

## 前言

Yesterday is history. Tomorrow is a mystery.
昨天已成为历史.明日却依然是谜.

Today is a gift of God.
今天是上帝的礼物.

Which is why we call it present!
那就是它为什么被称作"当下"的原因.

## 1710. 卡车上的最大单元数

你是一个卡车装载工，有一批箱子用二维数组 boxTypes 表示，其中 boxTypes[i] = [numberOfBoxes, numberOfUnitsPerBox] ：

numberOfBoxes 是类型 i 的箱子的个数。

numberOfUnitsPerBox 是类型 i 的箱子可以装载的单元数量。

整数 truckSize 表示卡车上可以装载箱子的最大数量 。只要箱子数量不超过truckSize，你就可以选择任意箱子装到卡车上。

求出卡车能够装载**单元**的**最大**总数。

示例 1：

```
输入：boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
输出：8
解释：箱子的情况如下：
- 1 个第一类的箱子，里面含 3 个单元。
- 2 个第二类的箱子，每个里面含 2 个单元。
- 3 个第三类的箱子，每个里面含 1 个单元。
可以选择第一类和第二类的所有箱子，以及第三类的一个箱子。
单元总数 = (1 * 3) + (2 * 2) + (1 * 1) = 8
```

示例 2：

```
输入：boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
输出：91
```

提示：

```
1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 106
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/maximum-units-on-a-truck](https://leetcode-cn.com/problems/maximum-units-on-a-truck)

Link：[https://leetcode.com/problems/maximum-units-on-a-truck/](https://leetcode.com/problems/maximum-units-on-a-truck/)


## 贪心

首先按照一个箱子📦最多单元，倒序排列。然后往车上能装多少装多少

```python
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        
        res = 0
        loaded = 0
        boxTypes.sort(key = lambda box : box[1], reverse=True)
        
        for box in boxTypes:
     
            if loaded + box[0] <= truckSize:
                res += box[0] * box[1]
                loaded += box[0]
            else:
                res += (truckSize - loaded) * box[1]
                break
                
        return res
```

--End--


