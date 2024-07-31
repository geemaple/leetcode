---
layout: post
index: 8
title: "LeetCode-8.字符串转换整数(atoi)(String to Integer)(atoi)"
categories: Leetcode
tags: Leetcode Math String
excerpt: "哪有什么岁月静好"
---

* content
{:toc}

## 8. 字符串转换整数 (atoi)

实现c语言中的atoi函数，使其能将字符串转换成整数

该函数首先丢弃开头无用的空格' '，加上一个**可选的**符号位'+'或者'-'，再加上尽可能多的数字(0-9)，形成一个有符号整数。

如果，连续数字后面有无意义字符，应该被函数忽略，对转换没有影响，参考示例3

如果，第一个非空字符，不是有效的数字， 返回0，参考示例4

在任何情况下，若函数不能进行有效的转换时，返回0。

提示：

假设我们的环境只能存储32位大小的有符号整数，那么其数值范围为 [−2^31,  2^31 − 1]。如果数值超过这个范围，请返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。
 

示例1:

```
输入: "42"
输出: 42
```

示例2:

```
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
```

示例3:

```
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
```

示例4:

```
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
```

示例 5:

```
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−2^31) 。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/string-to-integer-atoi/](https://leetcode-cn.com/problems/string-to-integer-atoi/)

Link：[https://leetcode.com/problems/string-to-integer-atoi/](https://leetcode.com/problems/string-to-integer-atoi/)


## 模拟法

O(N)

这道题，具体思路如下，只是corner case比较多，容易写错。

1. 去掉前置的空格
2. 获取符号
3. 获取数字，判断是否越界

### 没有32位限制

对于能够存储32位以上的环境，只要在最后判断结果是不是在范围中，即可

```python
class Solution:
    def myAtoi(self, str: str) -> int:
        int_max = 2 ** 31 - 1
        int_min = -2 ** 31

        sign = 1
        res = 0
        i = 0

        while i < len(str):
            # 去掉空格
            if str[i] == ' ':
                i += 1
                continue
            # 获取符号位
            if str[i] == '+' or str[i] == '-':
                sign = -1 if str[i] == '-' else 1
                i += 1
            # 获取数字
            while i < len(str) and str[i].isdigit():
                digit = int(str[i])  * sign
                res = res * 10 + digit

                # 越界判断
                if res >= int_max:
                    return int_max
                if res <= int_min:
                    return int_min
                i += 1
            
            break

        return res
```

### 有32位限制

参考上一题的越界判断

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        
        for (int i = 0; i < str.size(); i++) {
            // 去掉前置的空格
            if (str[i] == ' ') {
                continue;
            }
            // 获取符号
            if (str[i] == '+' || str[i] == '-') {
                sign = str[i] == '-' ? -1 : 1;
                i++;
            }
            // 获取数字，判断是否越界
            while (str[i] >= '0' && str[i] <= '9') {
                int digit = (str[i] - '0') * sign;
                // 越界判断
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) return INT_MAX;
                if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) return INT_MIN;
                    
                res = res * 10 + digit;
                i++;
            }
            
            break;
        }
        
        return res;
    }
};
```

--End--


