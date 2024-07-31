---
layout: post
index: 35
title: "LeetCode-35.搜索插入位置(Search Insert Position)"
categories: Leetcode
tags: Leetcode Array BinarySearch
excerpt: "信仰"
---

* content
{:toc}

## 35. 搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

```
输入: [1,3,5,6], 5
输出: 2
```

示例 2:

```
输入: [1,3,5,6], 2
输出: 1
```

示例 3:

```
输入: [1,3,5,6], 7
输出: 4
```

示例 4:

```
输入: [1,3,5,6], 0
输出: 0
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/search-insert-position/](https://leetcode-cn.com/problems/search-insert-position/)

Link：[https://leetcode.com/problems/search-insert-position/](https://leetcode.com/problems/search-insert-position/)

## 暴力破解

O(N)

从头到尾扫描一遍，就拿到答案了。

## 二分法

O(logN)

由于数组中的元素是唯一的，所以遇到相等的就可以返回了

**⚠️注意数组为空，或者数组元素都比target小的情况**

### 模版一(left + 1 < right)

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:

        if len(nums) == 0:
            return 0

        low = 0
        high = len(nums) - 1

        while (low + 1 < high):
            mid = low + (high - low) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                high = mid
            else:
                low = mid

        if nums[low] >= target:
            return low
        elif nums[high] >= target:
            return high
        else:
            return high + 1

```

### 模版二(left < right)

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        
        if len(nums) == 0:
            return 0
        
        low = 0
        high = len(nums) - 1
        
        while low < high:
            mid = low + (high - low) // 2
            
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                high = mid
            else:
                low = mid + 1
                
        if nums[low] >= target:
            return low
        else:
            return low + 1
```

### 模版三(left <= right)

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
                
        low = 0
        high = len(nums) - 1
        
        while low <= high:
            mid = low + (high - low) // 2
            
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                high = mid - 1
            else:
                low = mid + 1
                
        return low
```

--End--


