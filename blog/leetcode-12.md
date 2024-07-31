---
layout: post
index: 12
title: "LeetCode-12.整数转罗马数字(Integer to Roman)"
categories: Leetcode
tags: Leetcode String Math
excerpt: "自由之翼"
---

* content
{:toc}

## 12. 整数转罗马数字

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

给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

```
输入: 3
输出: "III"
```

示例 2:

```
输入: 4
输出: "IV"
```

示例 3:

```
输入: 9
输出: "IX"
```

示例 4:

```
输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
```

示例 5:

```
输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/integer-to-roman/](https://leetcode-cn.com/problems/integer-to-roman/)

Link：[https://leetcode.com/problems/integer-to-roman/](https://leetcode.com/problems/integer-to-roman/)

### 模拟法
O(1), 因为罗马字母排列组合大概10中左右, 输入参数范围很小(1, 3999), O(N) = O(1)

罗马数字的特点是结果 = 各个字母代表的数字之和

无需多解释，直接看代码

```python
class Solution:
    def intToRoman(self, num: int) -> str:
        
        romans = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        res = ''

        for i in range(len(romans)):
            while (num - values[i] >= 0):
                res += romans[i]
                num -= values[i]

        return res
```

--End--


