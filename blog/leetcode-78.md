---
layout: post
index: 78
title: "LeetCode-78.子集(Subsets)"
categories: Leetcode
tags: Leetcode Array Backtracking BitManipulation
excerpt: "创世纪"
---

* content
{:toc}

## 78. 子集

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

```
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/subsets](https://leetcode-cn.com/problems/subsets)

Link：[https://leetcode.com/problems/subsets](https://leetcode.com/problems/subsets)

## 回溯

O(N * 2^N)

代码如下

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        self.helper(nums, 0, [], res)
        return res

    def helper(self, nums: List[int], start: int, ans: List[int], res: List[List[int]]):
        res.append(list(ans))

        for i in range(start, len(nums)):
            ans.append(nums[i])
            self.helper(nums, i + 1, ans, res)
            ans.pop()
```

利用递归的特殊性，回溯代码可以写成**ans + [nums[i]]**

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        self.helper(nums, 0, [], res)
        return res
        
    def helper(self, nums: List[int], start: int, ans: List[int], res: List[List[int]]):
        res.append(list(ans))
        
        for i in range(start, len(nums)):
            self.helper(nums, i + 1, ans + [nums[i]], res)
```

## 拷贝添加

O(N * 2^N)

从[]开始，每次拷贝所有元素，并且在拷贝元素上加数字

```
开始   [[]]
  1   [[], [1]]
  2   [[], [1], [2], [1, 2]]
  3   [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]] 
```

代码如下

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        
        for num in nums:
            tmp = [ans + [num] for ans in res]
            res += tmp
    
        return res
```

## 比特位

O(N * 2^N)

一共有2^N个结果

```
1每2个元素出现1次
2每4个元素出现2次
3每8个元素出现4次

[], [], [], [], [], [], [], []

[], [1], [], [1], [], [1], [], [1]

[], [1], [2], [1, 2], [], [1], [2], [1, 2]

[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
```

代码如下:

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        size = len(nums)
        num_subset = 2 ** size
        results = [[] for _ in range(num_subset)]

        for i in range(size):
            for j in range(num_subset):
                if ((j >> i) & 1):
                    results[j].append(nums[i])

        return results
```

--End--
