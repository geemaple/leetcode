---
layout: post
index: 1736
title: "LeetCode-1736.替换隐藏数字得到的最晚时间(Latest Time by Replacing Hidden Digits)"
categories: Leetcode
tags: Leetcode String Greedy
excerpt: "默默扎根坚持"
---

* content
{:toc}

## 前言

最近换工作还挺辛苦的，适应期有好多事情需要投入，但想着刷题不能放弃，打算采取1EDP的策略

就是每天刷一道Easy的题 + 如果还有时间学习DP，这样既能保持每天刷题的节奏。

还能够，花时间去学一学动态规划，毕竟动归挺难的，需要长期点滴积累

## 1736. 替换隐藏数字得到的最晚时间

给你一个字符串 time ，格式为 hh:mm（小时 + 分钟），其中某几位数字被隐藏（用"问号"表示）。

有效的时间为 00:00 到 23:59 之间的所有时间，包括 00:00 和 23:59 。

替换 time 中隐藏的数字，返回你可以得到的最晚有效时间。

示例 1：

```
输入：time = "2?:?0"
输出："23:50"
解释：以数字 '2' 开头的最晚一小时是 23 ，以 '0' 结尾的最晚一分钟是 50 。
```

示例 2：

```
输入：time = "0?:3?"
输出："09:39"
```

示例 3：

```
输入：time = "1?:22"
输出："19:22"
```

提示：

```
time 的格式为 hh:mm
题目数据保证你可以由输入的字符串生成有效的时间
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits](https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits)

Link：[https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/](https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/)


## 四规则

这道题看着不难，但是有一些Corner Cases，需要注意一下

```python
class Solution:
    def maximumTime(self, time: str) -> str:
        
        digits = [t for t in time]

        if digits[0] == '?':
            digits[0] = '2' if digits[1] == '?' or int(digits[1]) < 4 else '1' 
        
        if digits[1] == '?':
            digits[1] = '3' if digits[0] == '2' else '9' 
        
        digits[3] = '5' if digits[3] == '?' else digits[3]
        digits[4] = '9' if digits[4] == '?' else digits[4]
        
        return ''.join(digits)
```

或者

```python
class Solution:
    def maximumTime(self, time: str) -> str:
        
        times = [t for t in time]

        if times[0] == '?':
            times[0] = '2' if times[1] in '?0123' else '1' 
        
        if times[1] == '?':
            times[1] = '3' if times[0] == '2' else '9' 
        
        times[3] = '5' if times[3] == '?' else times[3]
        times[4] = '9' if times[4] == '?' else times[4]
        
        return ''.join(times)
```

--End--


