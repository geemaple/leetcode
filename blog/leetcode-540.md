---
layout: post
index: 540
title: "LeetCode-540.有序数组中的单一元素(Single Element in a Sorted Array)"
categories: Leetcode
tags: Leetcode BinarySearch
excerpt: ""
---

* content
{:toc}

## 540. 有序数组中的单一元素

给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。

示例 1:

```
输入: [1,1,2,3,3,4,4,8,8]
输出: 2
```

示例 2:

```
输入: [3,3,7,7,10,11,11]
输出: 10
```

注意: 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/single-element-in-a-sorted-array](https://leetcode-cn.com/problems/single-element-in-a-sorted-array)

Link：[https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)


## 暴力破解

O(N)

```python
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        res = 0
        
        for num in nums:
            res ^= num
            
        return res
```

## 二分法

O(logN)

注意再出现独立数字之前**奇偶位置**和之后**奇偶位置**的变化

正常情况下，基数=偶数的值。但是有一个不成对出现，会导致后面的都向左偏移，很像First Bad Version

```python
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        
        left = 0
        right = len(nums) - 1
        
        while left < right:
            
            mid = left + (right - left) // 2
            
            # neighbor = mid - 1 if (mid % 2 == 1) else mid + 1
            neighbor = mid ^ 1
            
            if nums[mid] == nums[neighbor]:
                left = mid + 1
            else:
                right = mid
            
        return nums[left]
```

二分一切， 搜索控件可以是m = [0, len(nums)//2]。这样偶数数位=2m, 基数位=2m + 1

```python
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        
        left = 0
        right = len(nums) // 2
        
        while left < right:
            
            mid = left + (right - left) // 2
            
            if nums[2 * mid] == nums[2 * mid + 1]:
                left = mid + 1
            else:
                right = mid
            
        return nums[left * 2]
```

--End--