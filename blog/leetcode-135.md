---
layout: post
index: 135
title: "LeetCode-135.分发糖果(Candy)"
categories: Leetcode
tags: Leetcode Greedy
excerpt: ""
---

* content
{:toc}

贪心算法采用贪心的策略，保证每次操作都是**局部最优的**, 从而是最后得到的结果是**全局最优的**

贪心很难证明是对的，所以除了经典的贪心算法外，面试一般都不会考察

## 135. 分发糖果

老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

```
输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
```

示例 2:

```
输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/candy](https://leetcode-cn.com/problems/candy)

Link：[https://leetcode.com/problems/candy/](https://leetcode.com/problems/candy/)

## 贪心

O(N)

所有孩子初始化为1

先从左到右遍历一遍，如果右边的评分比左边高，这右边的糖果应该等于左边糖果+1

再从右到左遍历一遍，如果左边的评分比右边高，这左边的糖果应该等于右边糖果+1(上面的反逻辑), 第二遍扫描的时候应该取最大值，也就是说不能破坏第一次扫描的结果

```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        res = [1 for i in range(len(ratings))]
        
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                res[i] = res[i - 1] + 1
                
        for j in range(0, len(ratings) - 1)[::-1]:
            if ratings[j] > ratings[j + 1]:
                res[j] = max(res[j], res[j + 1] + 1)
        
        return sum(res)
```

## 空间O(1)

空间要求，一般都是非常有挑战的

对于上升区间

```python
             x
           x x
         x x x
       x x x x

up   = 0 1 2 3
peak = 0 1 2 3
down = 0 0 0 0

res +=   1 2 3
         + + +
         1 1 1
```

对于下降区间, 下降区间最后一个一定是**一个饼干**

```python
             #
             #         o
             x       o o
           x x     o o o
         x x x   o o o o
       x x x x o o o o o
               |<-逆序->|

up   = 0 1 2 3 0 0 0 0 0
peak = 0 1 2 3 3 3 3 3 3
down = 0 0 0 0 1 2 3 4 5

res +=  ...    1 2 3 4 5
                     + + 
                     1 1
                     # #                          
```

代码如下:

```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        if len(ratings) == 0:
            return 0
        
        res = 1
        up = down = peak = 0
        
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                up += 1
                peak = up
                down = 0
                res += 1 + up
                
            elif ratings[i] == ratings[i - 1]:
                up = down = peak = 0
                res += 1
        
            else:
                up = 0
                down += 1
                res += 1 + down + (-1 if peak >= down else 0)

        return res
```

对于下降区间可以用个等差数列求和, res += N * (1 + N) / 2 

```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        if len(ratings) == 0:
            return 0
        
        res = peak = 1
        down = 0
        
        for i in range(1, len(ratings)):
            if ratings[i] >= ratings[i - 1]:
                if (down) > 0:
                    res += down * (down + 1) // 2
                    res += 0 if down < peak else down - peak + 1
                    down = 0
                    peak = 1
                    
                peak = 1 if ratings[i] == ratings[i - 1] else peak + 1
                res += peak
        
            else:
                down += 1
                
        if down > 0:
            res += down * (down + 1) // 2
            res += 0 if down < peak else down - peak + 1

        return res
```

--End--


