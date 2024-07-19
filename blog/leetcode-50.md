---
layout: post
index: 50
title: "LeetCode-50.求X的N次方(Pow(x, n))"
categories: Leetcode
tags: Leetcode Math BinarySearch
excerpt: "苹果新品发布会"
---

* content
{:toc}

## 50. Pow(x, n)

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

```
输入: 2.00000, 10
输出: 1024.00000
```

示例 2:

```
输入: 2.10000, 3
输出: 9.26100
```

示例 3:

```
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
```

说明:

```
-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/powx-n/](https://leetcode-cn.com/problems/powx-n/)

Link：[https://leetcode.com/problems/powx-n/](https://leetcode.com/problems/powx-n/)

## 暴力破解

O(N)

for循环一个个乘

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:

        if x == 0:
            return 0

        if n < 0:
            n = -n
            x = 1 / x

        res = 1
        for i in range(n):
            res *= x

        return res
```

## 二分法

O(logN)

### 分治法

以**2^10**为例:

```
2^10 = 2^5 * 2^5

2^5 = 2^2 * 2^2 * 2

2^2 = 2 * 2
```

代码如下:

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        
        if x == 0:
            return 0

        if n < 0:
            n = -n
            x = 1 / x
            
        return self.helper(x, n)

    def helper(self, x: float, n: int) -> float:
        
        if n == 0:
            return 1.0
        
        half = self.helper(x, n // 2)
        if n & 1 == 1: # 奇数
            return half * half * x
        else:
            return half * half
```

### 二进制

以**2^10**为例:

```
# 10的二进制是0b1010

1        0        1        0    # 10的二进制表示
4th      3rd      2nd      1st  # 递归方向⬅️, 每次去掉末尾的一位

2^8      2^4      2^2      2^1  # tmp在参与计算时的值

把二进制奇数部分相加2^8 + 2^2 = 2^10
```

代码如下:

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:

        if x == 0:
            return 0
        
        if n < 0:
            n = -n
            x = 1 / x
        
        res = 1
        tmp = x
        
        while n > 0:
            if n & 1 == 1:
                res = res * tmp
                
            tmp = tmp * tmp
            n = n // 2
            
        return res
```

### 倍增思想

以**2^10**为例, 倍增的思想疯狂试探

```
# 第一次试探
2^1, 2^2, 2^4, 2^8, 2^16, 最后一个超了, 算到了2^8次方
                       
# 第二次试探
2^1, 2^2, 2^4, 最后一个超了，刚好算到2^2次方
```

代码如下

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:

        if x == 0:
            return 0
        
        exp = abs(n)
        res = 1

        while exp > 0:
            mark = 1
            tmp = x
            while (mark << 1) < exp:
                tmp = tmp * tmp
                mark = (mark << 1)
                
            exp -= mark
            res *= tmp

        return res if (n > 0) else 1 / res
```

--End--