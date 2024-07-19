---
layout: post
index: 13
title: "LeetCode-13.罗马数字转整数(Roman to Integer)"
categories: Leetcode
tags: Leetcode String Math
excerpt: "犹豫就会败北"
---

* content
{:toc}

## 13. 罗马数字转整数

罗马数字由以下7种不同字符表示： I， V， X， L，C，D 和 M。

```
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

例如， 

罗马II表示数字2 ，即为两个并列的I。

XII表示数字12 ，即为 X + II 。 

XXVII表示27, 即为 XX + V + II 。

**通常，罗马数字中大的数字在小的数字的左边。但也存在例外:**

例如 4不写做IIII，而是IV。数字 1 在数字 5 的左边，罗马数字IV = 5 - 1 得到的数值 4。

同样地，数字 9 表示为 IX。

**这个特殊的规则只适用于以下六种情况:**

```
I 放在 V (5) 和 X (10) 的左边，可表示 4 和 9。

X 放在 L (50) 和 C (100) 的左边，可表示 40 和 90。 

C 放在 D (500) 和 M (1000) 的左边，可表示 400 和 900。
```

给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

```
输入: "III"
输出: 3
```

示例 2:

```
输入: "IV"
输出: 4
```

示例 3:

```
输入: "IX"
输出: 9
```

示例 4:

```
输入: "LVIII"
输出: 58
解释: L = 50, V = 5, III = 3.
```

示例 5:

```
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/roman-to-integer/](https://leetcode-cn.com/problems/roman-to-integer/)

Link：[https://leetcode.com/problems/roman-to-integer/](https://leetcode.com/problems/roman-to-integer/)

### 模拟法
O(1), 因为罗马字母排列组合大概10中左右, 输入参数范围很小(1, 3999), O(N) = O(1)

罗马数字的特点是结果 = 各个字母代表的数字之和

无需多解释，直接看代码

```python
class Solution:
    def romanToInt(self, s: str) -> int:
        
        romans = ["M" , "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        res = 0

        for i in range(len(romans)):
            while s.startswith(romans[i]):
                res += values[i]
                s = s[len(romans[i]): len(s)]

        return res
```

罗马数字都是从大到小，如果有从小到大的逆序，需特殊处理一下

```python
class Solution:
    def romanToInt(self, s: str) -> int:

    roman = {'M': 1000,'D': 500 ,'C': 100,'L': 50,'X': 10,'V': 5,'I': 1}
    res = 0
    for i in range(0, len(s) - 1):
        if roman[s[i]] < roman[s[i+1]]:
            res -= roman[s[i]]
        else:
            res += roman[s[i]]

    return res + roman[s[-1]]
```

--End--


