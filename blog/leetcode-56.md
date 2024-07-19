---
layout: post
index: 56
title: "LeetCode-56.合并区间(Merge Intervals)"
categories: Leetcode
tags: Leetcode Array Sort
excerpt: "等待____"
---

* content
{:toc}

选择一条足够长的雪道，这样雪球才能滚动到足够大。

种一棵树最好的时间是十年前，而后是现在

直到有足够的原始积累，复利才会有可观的收益。

## 56. 合并区间

给出一个区间的集合，请合并所有重叠的区间。

示例 1:

```
输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

示例 2:

```
输入: intervals = [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/merge-intervals/](https://leetcode-cn.com/problems/merge-intervals/)

Link：[https://leetcode.com/problems/merge-intervals/](https://leetcode.com/problems/merge-intervals/)

## 排序

O(N)

按每组第一个元素排序

```
  |-----|
  1     3

     |-------|
     2       6
                   |-----|
                   8     10
                                    |------|
                                    15     18
```

1. 如果**next.start > previous.end**的话，那么两个区间一定不相交
2. 相反如果相交, 那么就合并, 取两个区间的end的最大值

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        intervals.sort()
        res = []
        
        for i in range(len(intervals)):
            # 如果为空 或者 next.start > previous.end
            if len(res) == 0 or intervals[i][0] > res[-1][1]:
                res.append(intervals[i])
            else:
                res[-1][1] = max(res[-1][1], intervals[i][1])
            
        return res
```

--End--