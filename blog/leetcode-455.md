---
layout: post
index: 455
title: "LeetCode-455.分发饼干(Assign Cookies)"
categories: Leetcode
tags: Leetcode Greedy
excerpt: ""
---

* content
{:toc}

贪心算法采用贪心的策略，保证每次操作都是**局部最优的**, 从而是最后得到的结果是**全局最优的**

贪心很难证明是对的，所以除了经典的贪心算法外，面试一般都不会考察

## 455. 分发饼干

假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

 
示例 1:

```
输入: g = [1,2,3], s = [1,1]
输出: 1
解释: 
你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
所以你应该输出1。
```

示例 2:

```
输入: g = [1,2], s = [1,2,3]
输出: 2
解释: 
你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
你拥有的饼干数量和尺寸都足以让所有孩子满足。
所以你应该输出2.
```

提示：

```
1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/assign-cookies](https://leetcode-cn.com/problems/assign-cookies)

Link：[https://leetcode.com/problems/assign-cookies/](https://leetcode.com/problems/assign-cookies/)

## 贪心

O(N)

现将两个数组排序，那size最小的饼干优先考虑饥饿度最小的孩子, 这样才能使得剩下的饼干满足更多的人

```python
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()

        res = 0
        j = 0
        for i in range(len(s)):
            if j < len(g) and s[i] >= g[j]:
                res += 1
                j += 1

        return res
```

上面代码中的j与res完全相等, 可以省略

```python
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()

        res = 0
        for i in range(len(s)):
            if res < len(g) and s[i] >= g[res]:
                res += 1

        return res
```

反过来比较

```python
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()

        child = 0
        cookie = 0
        
        while child < len(g) and cookie < len(s):
            if s[cookie] >= g[child]:
                child += 1
                
            cookie += 1
    
        return child
```

--End--


