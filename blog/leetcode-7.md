---
layout: post
index: 7
title: "LeetCode-7.整数反转(Reverse Integer)"
categories: Leetcode
tags: Leetcode Math
excerpt: "边界与范围"
---

* content
{:toc}

# 7. 整数反转

给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

```
输入: 123
输出: 321
```

示例 2:

```
输入: -123
输出: -321
```

示例 3:

```
输入: 120
输出: 21
```

注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  23^1 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/reverse-integer/](https://leetcode-cn.com/problems/reverse-integer/)

Link：[https://leetcode.com/problems/reverse-integer/](https://leetcode.com/problems/reverse-integer/)

## 模拟法

O(N)

将数字%10, 可以拿到最后一位数字。将数字/10, 可以去掉最后一位

新的数字, 只要把原来*10, 在加上新拿到的最后一位即可

语言差异：

```
# python
- 2 % 10 = 8

# cpp
- 2 % 10 = -2
```

### 没有32位限制

对于能够存储32位以上的环境，只要在最后判断结果是不是在范围中，即可

```python
class Solution:
    def reverse(self, x: int) -> int:
 
        max_integer = 2 ** 31 - 1
        min_integer = - 2 ** 31

        sign = 1 if x >= 0 else -1
        x = abs(x)
        reverse = 0
        
        while x > 0:
            reverse = reverse * 10 + x % 10
            x = x // 10
            
        res = sign * reverse
        return res if res >= min_integer and res <= max_integer else 0
```

### 有32位限制

> 由于python没有32位限制, 以下是cpp的代码

对于可能溢出的数字, 只要将新的数字做逆运算. 和原来的不相等, 就溢出了

可是下面代码, 平台新的编译器, 溢出会报错了😂

```cpp
class Solution {
public:
    int reverse(int x) {
        
        int res = 0;
        while(x != 0)
        {
            int pop = x % 10;
            x = x / 10;

            int candidate = res * 10 + pop;

            if ((candidate - pop) / 10 != res) // 溢出判断
            {
                return 0;
            }

            res = candidate;            
        }

        return res;
    }
};
```

将数的范围看成一条线上的点，那么溢出的边界在于左右两端，排除掉，即可

```cpp
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) return 0; // 右端，超出安全边界
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8)) return 0; // 左端，超出安全边界
            res = res * 10 + pop;
        }
        
        return res;
    }
};
```

--End--


