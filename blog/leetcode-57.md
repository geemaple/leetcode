---
layout: post
index: 57
title: "LeetCode-57.插入区间(Insert Interval)"
categories: Leetcode
tags: Leetcode Array Sort
excerpt: "阴晴圆缺"
---

* content
{:toc}

## 57. 插入区间

给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1：

```
输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
```

示例 2：

```
输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/insert-interval/](https://leetcode-cn.com/problems/insert-interval/)

Link：[https://leetcode.com/problems/insert-interval/](https://leetcode.com/problems/insert-interval/)

## 排序

O(N*logN)

可以将newInterval插入到合适的位置，然后就变成了上一道题。

```python
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        intervals.append(newInterval)
        intervals.sort()

        res = []
        for i in range(len(intervals)):
        
            if len(res) == 0 or intervals[i][0] > res[-1][1]:
                res.append(intervals[i])
            else:
                res[-1][1] = max(res[-1][1], intervals[i][1])
                
        return res
                
```

## 左中右

O(N)

```
           [start ～ end]

 left.end < start    end < right.start
  左边无法合并部分       右边无法合并部分
```

先找出左边部分和右边部分，剩下的是可以合并的

```python
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        left = []
        right = []
        
        start = newInterval[0]
        end = newInterval[1]
        
        for i in range(len(intervals)):
        
            if intervals[i][1] < start:
                left.append(intervals[i])
                
            elif intervals[i][0] > end:
                right.append(intervals[i])
            
            else:
                start = min(start, intervals[i][0])
                end = max(end, intervals[i][1])
                
        return left + [[start, end]] + right
                
```

--End--