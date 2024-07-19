---
layout: post
index: 435
title: "LeetCode-435.无重叠区间(Non-overlapping Intervals)"
categories: Leetcode
tags: Leetcode Greedy
excerpt: ""
---

* content
{:toc}

## 435. 无重叠区间

给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

```
可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
```

示例 1:

```
输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
```

示例 2:

```
输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
```

示例 3:

```
输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/non-overlapping-intervals/](https://leetcode-cn.com/problems/non-overlapping-intervals/)

Link：[https://leetcode.com/problems/non-overlapping-intervals/](https://leetcode.com/problems/non-overlapping-intervals/)


## 贪心

O(N*logN)

区间的结尾越小，给其他区间留出的空间就越大

区间结尾递增排序，顺序遍历，这样可以优先保留结尾小的区间。

```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0:
            return 0
        
        intervals.sort(key=lambda x : x[1])
        res = 0
        pre_end = intervals[0][1]
        
        for i in range(1, len(intervals)):
            if pre_end > intervals[i][0]:
                res += 1
            else:
                pre_end = intervals[i][1]
            
        return res
```

或者初始值负无穷

```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0:
            return 0
        
        intervals.sort(key=lambda x : x[1])
        res = 0
        pre_end = float('-inf')
        
        for i in range(len(intervals)):
            if pre_end > intervals[i][0]:
                res += 1
            else:
                pre_end = intervals[i][1]
            
        return res
```

反逻辑，最多能放多少个不重叠的区间, 结果 = 总量 - 最多能放下的

```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0:
            return 0
        
        intervals.sort(key=lambda x : x[1])
        put = 1
        pre_end = intervals[0][1]
        
        for i in range(1, len(intervals)):
            if intervals[i][0] >= pre_end:
                put += 1
                pre_end = intervals[i][1]
            
        return len(intervals) - put
```

--End--


