---
layout: post
index: 38
title: "LeetCode-38.外观数列(Count and Say)"
categories: Leetcode
tags: Leetcode String
excerpt: "This is water"
---

* content
{:toc}

## 38. 外观数列

给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

注意：整数序列中的每一项将表示为一个字符串。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1. 1
2. 11
3. 21
4. 1211
5. 111221

```
第一项, 是数字1
第二项, 描述1st, 有1个1, 写成11
第三项, 描述2nd, 有2个1, 写成21
第四项, 描述3rd, 有1个2 + 1个1, 写成1211
第五项, 描述4th, 有1个1 + 1个2 + 2个1, 写成111221
```

示例 1:

```
输入: 1
输出: "1"
解释：这是一个基本样例。
```

示例 2:

```
输入: 4
输出: "1211"
解释：当 n = 3 时，序列是 "21"，其中我们有 "2" 和 "1" 两组，"2" 可以读作 "12"，也就是出现频次 = 1 而 值 = 2；类似 "1" 可以读作 "11"。所以答案是 "12" 和 "11" 组合在一起，也就是 "1211"。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/count-and-say/](https://leetcode-cn.com/problems/count-and-say/)

Link：[https://leetcode.com/problems/count-and-say/](https://leetcode.com/problems/count-and-say/)

## 模拟法

第**N**个数是对第**N - 1**个数的外观描述。

代码如下:

```python
class Solution:
    def countAndSay(self, n: int) -> str:
        pre = '1'
        ans = pre
        for i in range(1, n):
            ans = ''
            count = 1
            char = pre[0]
            for c in pre[1:]:
                if char == c:
                    count += 1
                else:
                    ans += str(count) + char
                    char = c
                    count = 1
                    
            ans += str(count) + char
            pre = ans
            
        return ans
```

--End--


