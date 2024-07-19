---
layout: post
index: 605
title: "LeetCode-605.种花问题(Candy)"
categories: Leetcode
tags: Leetcode Array Greedy
excerpt: ""
---

* content
{:toc}

贪心算法采用贪心的策略，保证每次操作都是**局部最优的**, 从而是最后得到的结果是**全局最优的**

## 605. 种花问题

假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

示例 1:

```
输入: flowerbed = [1,0,0,0,1], n = 1
输出: True
```

示例 2:

```
输入: flowerbed = [1,0,0,0,1], n = 2
输出: False
```

注意:
```
数组内已种好的花不会违反种植规则。
输入的数组长度范围为 [1, 20000]。
n 是非负整数，且不会超过输入数组的大小。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/can-place-flowers/](https://leetcode-cn.com/problems/can-place-flowers/)

Link：[https://leetcode.com/problems/can-place-flowers/](https://leetcode.com/problems/can-place-flowers/)

## 贪心

O(N)

如果一个位置左右都没有花，那么可以先种下

前端，认为左边没有花

后端，认为右边没有花

```python
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        res = 0
        index = 0
        
        while index < len(flowerbed) and res < n:
            
            if flowerbed[index] == 0:
                left = flowerbed[index - 1] if index - 1 >= 0 else 0
                right = flowerbed[index + 1] if index + 1 < len(flowerbed) else 0
                if left == 0 and right == 0:
                    res += 1
                    index += 2
                    continue
            
            index += 1
                
        return res >= n
        
```

## 数学

计数有多少个空白出N

```python
X O O O O O O O O X
|<-------N------->|

# 1 - 2不能种
# 3 - 4能种一个
# 5 - 6能中两个
# ...
```
res = (N - 1) // 2

```
O O O O O O O O O X

X O O O O O O O O O
```

两端比较特殊, res = N // 2

初始化plot = 1, 处理左端的情况

```python
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        res = 0
        plot = 1
        for i in range(len(flowerbed)):
            if flowerbed[i] == 0:
                plot += 1
            else:
                res += (plot - 1) // 2
                plot = 0
                    
        if plot > 0:
            res += plot // 2

        return res >= n
```

--End--


