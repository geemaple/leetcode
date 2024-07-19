---
layout: post
index: 342
title: "LeetCode-342.4的幂(Power of Four)"
categories: Leetcode
tags: Leetcode BitManipulation
excerpt: ""
---

* content
{:toc}

## 342. 4的幂

给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x

示例 1：

```
输入：n = 16
输出：true
```

示例 2：

```
输入：n = 5
输出：false
```

示例 3：

```
输入：n = 1
输出：true
```

提示：

```
-231 <= n <= 231 - 1
```

进阶：

你能不使用循环或者递归来完成本题吗？

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/power-of-four](https://leetcode-cn.com/problems/power-of-four)

Link：[https://leetcode.com/problems/power-of-four/](https://leetcode.com/problems/power-of-four/)



## 除法

O(1)

不断除以4，判断能不能整除

```python
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        
        tmp = n
        while tmp > 1:
            if tmp % 4 == 0:
                tmp = tmp // 4
            else:
                return False
            
        return tmp == 1
```

## 二进制

O(1)

如果一个数是2的n次方，那么只有一个bit位是1, 其他都是0。用n & (n - 1)可以打掉这个1

如果一个数是4的n次方, 那么这个1必须在奇数位置才行

```python
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        mask = 0b01010101010101010101010101010101 # 0x55555555
        return (n > 0) and (n & (n - 1)) == 0 and (n & mask)
```

--End--


