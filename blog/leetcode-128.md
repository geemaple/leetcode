---
layout: post
index: 128
title: "LeetCode-128.最长连续序列(Longest Consecutive Sequence)"
categories: Leetcode
tags: Leetcode Array DisjointSet
excerpt: "威尔士小矿工\"耶稣比利\""
---

* content
{:toc}

## 前言

引用个中文社区的段子，为苦哈哈刷题增加点乐趣

> 我啪的一下一个sort(),很快嗷，然后一个遍历，直接通过，按传统编程，点到即止，我已经赢了。这时候他一个时间复杂度为 O(n)打过来，我大意了，没有闪，我说小力扣你不讲武德，来偷袭我这22岁的老同志，这好吗，这不好。我劝，这位小力扣耗子为汁，好好反思，不要再犯这样的错误

## 128. 最长连续序列

给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？

示例 1：

```
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
```

示例 2：

```
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
解释：最长数字连续序列是 [0 ～ 8]。它的长度为 9。
```

提示：

```
0 <= nums.length <= 104
-109 <= nums[i] <= 109
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/longest-consecutive-sequence](https://leetcode-cn.com/problems/longest-consecutive-sequence)

Link：[https://leetcode.com/problems/longest-consecutive-sequence/](https://leetcode.com/problems/longest-consecutive-sequence/)


## 排序

O(N * logN)

排序之后，重复的数字会挨在一起，需要特殊处理。缺点是一旦排序，最优也到不了O(N)

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        if len(nums) == 0:
            return 0
        
        nums.sort()
        longest = 1
        current = 1
        
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                continue
                
            if nums[i] == nums[i - 1] + 1:
                current += 1
            else:
                longest = max(longest, current)
                current = 1
                
        return max(longest, current)
```

## 暴力破解

O(N^2)

```python
start, start + 1, start + 2, ... end
  ||
  num
```

数字num，就看以start=num开始, 每次+1直到end不满足为止。注意边界

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        longest = 0
        num_set = set(nums)

        for start in nums:
            end = start
            while end in num_set:
                end += 1

            longest = max(longest, end - start)

        return longest
```

## 哈希

### 寻找起点

O(N)

在暴力破解中，每一个都作为起点单独计算，如果num - 1在哈希中，那它一定在上一个序列中，可以跳过

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        num_set = set(nums)
        longest = 0
        
        for num in num_set:
            if num - 1 in num_set:
                continue
                
            next_num = num + 1
            while next_num in num_set:
                next_num += 1
                
            longest = max(longest, next_num - num)
            
        return longest
```

### 两端拓展

一个数字向两边寻找，如果访问过，就将记录移除

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        longest = 0
        record = set(nums)
        
        for num in nums:
            if num not in record:
                continue
                
            left = num - 1
            while left in record:
                record.remove(left)
                left -= 1
                
            right = num + 1
            while right in record:
                record.remove(right)
                right += 1
                
            longest = max(longest, right - left - 1)
            
        return longest
```

### 连续边界更新

另一种思路，始终更新连续区间的左右两个边界, 例如4插入的时候:

```python
[2, 3]  4  [5, 6, 7]

# left(连续个数) = 2, right(连续个数) = 3
# record[4] = left + right + 1

'对于新的区间[2 ~ 7]更新2｜7的数值'
# record[4 - 2] = record[4]
# record[4 + 3] = record[4]
```

代码如下:

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        record = {}
        longest = 0
        
        for num in nums:
            if num in record:
                continue
                
            left = record[num - 1] if num - 1 in record else 0
            right = record[num + 1] if num + 1 in record else 0
            
            record[num] = right + left + 1
            longest = max(longest, record[num])
            
            record[num - left] = record[num]
            record[num + right] = record[num]
            
        return longest
```

## 并查集

O(N)

同样是O(N)的，哈希看起来就简单得多，但是用UnionFind数据结构的好处，是可以处理流式数据。

PS: 请自行搜索"并查集", 并查集要求完全无误默写，然鹅我已经忘记了。😭😭😭

```python
class UnionFind:
    def __init__(self, nums: list[int]):
        self.ancestor = {num : num for num in nums}
        self.count = {num : 1 for num in nums}
        self.longest = 1 if len(nums) > 0 else 0

    def find(self, node: int):
        path = []
        while node != self.ancestor[node]:
            path.append(node)
            node = self.ancestor[node]

        for sub in path:
            self.ancestor[sub] = node

        return node

    def union(self, a: int, b: int):
        root_a = self.find(a)
        root_b = self.find(b)

        if root_a != root_b:
            length = self.count[root_a] + self.count[root_b]
            self.ancestor[root_a] = root_b
            self.count[root_b] = length
            self.longest = max(self.longest, length)

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        union_find = UnionFind(nums)
        num_set = set(nums)
        longest = 0

        for num in nums:
            if num - 1 in num_set:
                union_find.union(num - 1, num)

            if num + 1 in num_set:
                union_find.union(num, num + 1)

        return union_find.longest
```

--End--