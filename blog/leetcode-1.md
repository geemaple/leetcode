---
layout: post
index: 1
title: "LeetCode-1.两数之和(Two Sum)"
categories: Leetcode
tags: Leetcode Array HashTable
excerpt: "起航，Great Voyage"
---

* content
{:toc}

相信每个想刷leetcode的人，第一次打开网站，就从这道题开始的。

一起起航吧，Great Voyage.

## 1. 两数之和：

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

例如:
```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/two-sum/](https://leetcode-cn.com/problems/two-sum/)

Link：[https://leetcode.com/problems/two-sum/](https://leetcode.com/problems/two-sum/)

### 哈希

O(N)

遍历数组

如果在字典找到数字，则输出[字典下标，当前下标]

找不到答案，把当前的值放入字典(val -> index)

因为题目说**有且只有一组答案**，所以不用判断数组为空，返回值不存在的情况

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = dict()
        for i in range(len(nums)):
            val = target - nums[i]
            if val in map:
                return [map[val], i]
            else:
                map[nums[i]] = i
```

### 双指针

O(N*logN)

如果题目要求返回两个具体数字，可以先排序，然后使用双指针(start, end)

```res = nums[start] + nums[end]```

如果**res < target**, 则说明**nums[start] + 最大的数**都小于target, start的值太小了，应该start++

如果**res > target**, 则说明**nums[end] + 最小的数**都大于target, end的值太大了，应该end--

如果**res = target**, 则输出答案

```python
class Solution(object):
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        start = 0
        end = len(nums) - 1
        
        nums.sort()
        
        while(start < end):
            res = nums[start] + nums[end]
            if res == target:
                return (nums[start], nums[end])
            elif res < target:
                start += 1
            else:
                end -= 1

```

--End--


