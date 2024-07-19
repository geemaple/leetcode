---
layout: post
index: 33
title: "LeetCode-33.搜索旋转排序数组(Search in Rotated Sorted Array)"
categories: Leetcode
tags: Leetcode Array BinarySearch
excerpt: "即兴发挥才是自己的"
---

* content
{:toc}

## 33. 搜索旋转排序数组

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

```
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
```

示例 2:

```
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/search-in-rotated-sorted-array/](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

Link：[https://leetcode.com/problems/search-in-rotated-sorted-array/](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## 暴力破解

O(N)

从头到尾扫描一遍，就拿到答案了。

## 二分法

O(logN)

二分法的精髓是，用常数O(1)时间，把问题的规模缩小一半。

旋转排序数组如下：

```
|        |   X  
|        |X
|      X |
|   X    |
|        |            |      X
|        a            |   X
|                     |X
|                   X |
|                X    |
|                     b
-----------------------------------
```

### 如果中间在a处：mid >= nums[0]

```
--------｜----------｜---------
      nums[0]      mid
```

**target > mid** or **target < nums[0]**, 丢弃a的左边

**nums[0] <= target < mid**, 丢弃a的右边

### 如果中间在b处: mid < nums[0]

```
--------｜----------｜---------
       mid        nums[0]
```

**target < mid** or **target >= nums[0]**, 丢掉b的右边

**mid < target <= nums[0]**, 丢弃b的左边

### 排序数组特例

```
|                           X
|                        X
|                     X
|                  X
|               X
|            X
|         X
|      X
|   X
|
-----------------------------------
```

正常排序数组同样满足上面条件a

丢掉一半后，是一个规模更小的子问题，其中nums[0] 可以等于 nums[left]

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        if len(nums) == 0:
            return -1
        
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if nums[mid] == target:
                return mid
            
            if nums[mid] >= nums[left]:
                if target > nums[mid] or target < nums[left]:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if target < nums[mid] or target >= nums[left]:
                    right = mid - 1
                else:
                    left = mid + 1
                    
        return -1
        
```
--End--


