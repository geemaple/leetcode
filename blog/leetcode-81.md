---
layout: post
index: 81
title: "LeetCode-81.搜索旋转排序数组 II(Search in Rotated Sorted Array II)"
categories: Leetcode
tags: Leetcode Array BinarySearch
excerpt: "穷则思变"
---

* content
{:toc}

## 81. 搜索旋转排序数组 II

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

```
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
```

示例 2:

```
输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
```

进阶:

```
这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii)

Link：[https://leetcode.com/problems/search-in-rotated-sorted-array-ii/](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)


## 二分查找

### 无重复

O(logN)

对于33题，是没有重复元素的，可以用二分查找

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

# 如果中间在a处：mid >= nums[0]

--------｜----------｜---------
      nums[0]      mid

nums[left] <= target < mid #丢弃a的右边

# 如果中间在b处: mid < nums[0]

--------｜----------｜---------
       mid        nums[0]

mid < target <= nums[right] #丢弃b的左边
```

旋转排序数组特例:

```
# 正常排序数组同样满足上面条件a

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

代码如下:

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
                
            if nums[mid] >= nums[left]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return -1
```

### 有重复

O(N)

若nums[mid] == nums[left]会造成无法判断a/b的情况, 需要特殊处理

```
# 情况a                 
|              
|           
|         X
|      X
|   X        X  X  X  X  X  X
|
-----------------------------------

# 情况b
|              
|           
|                        X
|                     X
|   X  X  X  X  X  X        X
|
-----------------------------------
```

代码如下

```python
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        
        left = 0
        right = len(nums) - 1
        
        while left <= right:
    
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return True
                
            if nums[mid] > nums[left]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            elif nums[mid] < nums[left]:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                left += 1

        return False
```

### One More Thing

这里使用的是**Left**做为两种情况的参考坐标，当然也可以使用**Right**做为参考坐标

--End--
