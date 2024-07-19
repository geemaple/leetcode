---
layout: post
index: 29
title: "LeetCode-29.两数相除(Divide Two Integers)"
categories: Leetcode
tags: Leetcode Math BinarySearch
excerpt: "两数相除，却不让用乘除法"
---

* content
{:toc}

## 29. Divide Two Integers

给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

示例 1:

```
输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
```

示例 2:

```
输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2
```

提示：

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。**本题中，如果除法结果溢出，则返回 231 − 1。**

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/divide-two-integers/](https://leetcode-cn.com/problems/divide-two-integers/)

Link：[https://leetcode.com/problems/divide-two-integers/](https://leetcode.com/problems/divide-two-integers/)

## 暴力破解

题目限制，就只能用加减法，加上二进制操作了。暴力破解是每次减去divisor， 减了多少次， 结果就是多少。

难点在于，符号，边界条件判断，负数最大值转成正数就越界了。

不出意外的，暴力破解会超时

```python
MAX_INT = 2147483647
MIN_INT = -2147483648

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:

        if dividend == MIN_INT and divisor == -1:
            return MAX_INT

        res = 0
        minus = (dividend > 0) ^ (divisor > 0)

        dividend = abs(dividend)
        divisor = abs(divisor)
        
        while dividend >= divisor:
            res += 1
            dividend -= divisor

        return -res if minus > 0 else res
```

## 二分法

每次减去一个divisor太慢了，我们可以尝试，减去(2, 4, 8, 16 ...)倍的divisor

python代码如下:

```python
MAX_INT = 2147483647
MIN_INT = -2147483648

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:

        if dividend == MIN_INT and divisor == -1:
            return MAX_INT

        res = 0
        minus = (dividend > 0) ^ (divisor > 0)

        dividend = abs(dividend)
        divisor = abs(divisor)
        
        while dividend >= divisor:
            tmp = divisor
            scale = 1
            while (dividend >= (tmp << 1)):
                tmp = tmp << 1
                scale = scale << 1
                
            res += scale
            dividend -= tmp

        return -res if minus > 0 else res
```

C++代码如下:

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        bool minus = ((dividend > 0) ^ (divisor > 0));
        
        long long number = labs(dividend);
        long long div = labs(divisor);

        long long res = 0;
        
        while (number >= div) {
            long long tmp = div;
            long long mul = 1;
            while(number >= (tmp << 1)) {
                mul <<= 1;
                tmp <<= 1;
            }
            
            res += mul;
            number -= tmp;
        }
        
        return (int)(minus ? -res: res);
    }
};
```

--End--


