---
layout: post
index: 1732
title: "LeetCode-1732.找到最高海拔(Find the Highest Altitude)"
categories: Leetcode
tags: Leetcode Array
excerpt: "等风来"
---

* content
{:toc}

## 前言

问世间是否此山最高, 或者另有高处比天高

认准几个领域，在该领域不断的前行，等待机遇的到来

专注是一种能力，尤其是在要过年的时候

闲着也是闲着，得学点东西，学东西得学点难的

## 1732. 找到最高海拔

有一个自行车骑行爱好者，打算沿着公路骑行。路上有N + 1个检查点，每个检查点有不同的海拔高度

该骑行爱好者的起始点海拔高度为0, 给一个长度为N的海拔差值数组gain。gain[i]的值是点 i 和点 i + 1 的海拔高度差值, 其中0 <= i < n, 请返回骑手经过的最高海拔高度。

示例 1：

```
输入：gain = [-5,1,5,0,-7]
输出：1
解释：海拔高度依次为 [0,-5,-4,1,1,-6] 。最高海拔为 1 。
```

示例 2：

```
输入：gain = [-4,-3,-2,-1,4,3,2]
输出：0
解释：海拔高度依次为 [0,-4,-7,-9,-10,-6,-3,-1] 。最高海拔为 0 。
```

提示：

```
n == gain.length
1 <= n <= 100
-100 <= gain[i] <= 100
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/find-the-highest-altitude](https://leetcode-cn.com/problems/find-the-highest-altitude)

Link：[https://leetcode.com/problems/find-the-highest-altitude/](https://leetcode.com/problems/find-the-highest-altitude/)


## 数组遍历

这道题其实是求前缀和，找出其中最大的那个

```python
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        
        high = 0
        pre = 0
        for i in range(len(gain)):
            pre += gain[i]
            high = max(high, pre)
            
        return high
```

--End--


