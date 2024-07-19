---
layout: post
index: 34
title: "LeetCode-34.在排序数组中查找元素的第一个和最后一个位置(Find First and Last Position of Element in Sorted Array)"
categories: Leetcode
tags: Leetcode Array BinarySearch
excerpt: "One Piece"
---

* content
{:toc}

## 34. 在排序数组中查找元素的第一个和最后一个位置

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

```
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
```

示例 2:

```
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

Link：[https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

## 暴力破解

O(N)

从头到尾扫描一遍，就拿到答案了。

## 二分法

O(logN)

两遍二分查找，先找头，后找尾

### 模版一(left + 1 < right)

优点: 不用担心死循环

结尾时left + 1 = right，要单独判断两个边界, 注意越界判断

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        if len(nums) == 0:
            return [-1, -1]

        first = -1
        left = 0
        right = len(nums) - 1
        while left + 1 < right:
            mid = left + (right - left) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid
        
        if nums[left] == target:
            first = left
        elif nums[right] == target:
            first = right
            
        last = -1
        right = len(nums) - 1
        while left + 1 < right:
            mid = left + (right - left) // 2
            if nums[mid] <= target:
                left = mid
            else:
                right = mid
        
        if nums[right] == target:
            last = right
        elif nums[left] == target:
            last = left
            
        return [first, last]
```

### 模版二(left < right)

⚠️注意```mid = (left + right) / 2```的结果偏左. 例如(0 + 1) / 2 = 0

需要用```left = mid + 1```代偿

结尾时left = right, 需要判断是否满足条件, 注意越界判断

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        if len(nums) == 0:
            return [-1, -1]
            
        first = -1
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        
        if nums[left] == target:
            first = left
            
        last = -1
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid

            if nums[mid] == target:
                last = mid
        
        if nums[left] == target:
            last = left
            
        return [first, last]
```

⚠️注意```mid = (left + right) / 2 + 1```的结果偏右. 例如(0 + 1) / 2 + 1 = 1

需要用```right = mid - 1```代偿

结尾时left = right, 需要判断是否满足条件, 注意越界判断

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        if len(nums) == 0:
            return [-1, -1]
            
        first = -1
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        
        if nums[left] == target:
            first = left
            
        last = -1
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2 + 1
            
            if nums[mid] <= target:
                left = mid
            else:
                right = mid - 1
        
        if nums[left] == target:
            last = left
            
        return [first, last]
```

### 模版三(left <= right)

优点: 结束后不用再单独判断

⚠️同样注意```mid = (left + right) / 2```的结果偏左. 例如(0 + 1) / 2 = 0

需要用```left = mid + 1```和```right = mid - 1```代偿

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        first = -1
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] >= target:
                right = mid - 1
            else:
                left = mid + 1
            
            if nums[mid] == target:
                first = mid
            
        last = -1
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        
            if nums[mid] == target:
                last = mid

        return [first, last]
```

## 分治法

O(logN)

```
... O O O | O O O O X X X X X X X X O O O | O O O O ...
          |                               |
          a                               b

... O O O X X | X X X X X X
              |
              c

X X X X | X X X X O O O ... 
        |
        d
```

如果超出范围，迅速返回[-1, -1], 比如a的左边，b的右边

如果全是target, 迅速返回[low, high], 比如c的右边, d的左边

只有在区间内，才需要继续计算左右两部分，但也会很快满足上溯条件，迅速返回结果。

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        def search(low, high):
            if nums[low] == target == nums[high]:
                return [low, high]
            
            if nums[low] <= target <= nums[high]:
                mid = low + (high - low) // 2
                
                left = search(low, mid)
                right = search(mid+1, high)
                
                if left[0] == -1: 
                    return right
                elif right[0] == -1:
                    return left
                else:
                    return [left[0], right[1]]
            else:
                return [-1, -1]
        
        return search(0, len(nums)-1) if len(nums) > 0 else [-1, -1]
```

--End--


