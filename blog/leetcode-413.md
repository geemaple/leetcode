---
layout: post
index: 413
title: "LeetCode-413.等差数列划分(Arithmetic Slices)"
categories: Leetcode
tags: Leetcode Math DP
excerpt: "明天会更好"
---

* content
{:toc}

## 413. 等差数列划分

如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，以下数列为等差数列:

```
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
```

以下数列不是等差数列。

```
1, 1, 2, 5, 7
```

数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。

如果满足以下条件，则称子数组(P, Q)为等差数组：

元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。

函数要返回数组 A 中所有为等差数组的子数组个数。

示例:

```
A = [1, 2, 3, 4]

返回: 3, A 中有三个子等差数组: [1, 2, 3], [2, 3, 4] 以及自身 [1, 2, 3, 4]。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/arithmetic-slices](https://leetcode-cn.com/problems/arithmetic-slices)

Link：[https://leetcode.com/problems/arithmetic-slices/](https://leetcode.com/problems/arithmetic-slices/)


## 暴力破解

O(N^2)

```
###############        #
^             ^
i           j - 1      j
```

假设1，2元素都是等差数列，但是不计入答案中。

在第二个For循环中，2个元素A[i : j - 1]已经是等差数列, 那么A[i : j]只要判断新加入进来的元素j, 满足A[j] - A[j - 1]等于原来等差数列的差值

```python
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        count = 0
        
        for i in range(len(A)):
            for j in range(i + 2, len(A)):
                if A[j] - A[j - 1] != A[i + 1] - A[i]:
                    break
                
                count += 1
                
        return count
```

## 动态规划

O(N)

```
################    #
       i-2   i-1    i
```

### 状态定义

定义dp[i]是**包含**A[i]的, 也就是以A[i]为结尾的等差数列的个数

### 转移方程

如果原来有k条, 那么如果能把新的数字填上，那么就是新的k条

同时，A[i - 2], A[i - 1], A[i]是一条新的等差数列

```python
if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
    dp[i] = dp[i - 1] + 1
```

### 初始化

```python
dp[0] = 0
dp[1] = 0
```

### 计算方向

从左到右

```python
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        dp = [0 for i in range(len(A))]
        
        for i in range(2, len(A)):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                dp[i] = dp[i - 1] + 1
                
        return sum(dp)
```

### 空间压缩

递推公式的动态规划，通常都是可以压缩空间的，因为沿着一个计算方向，之前的变量可能就用不到了

从该题计算方向来看，用不了那么多变量，只要两个就够了

```python
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        cur = 0
        count = 0
        
        for i in range(2, len(A)):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                cur += 1
                count += cur
            else:
                cur = 0
                
        return count
```

--End--


