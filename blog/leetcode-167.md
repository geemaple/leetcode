---
layout: post
index: 167
title: "LeetCode-167.两数之和 II - 输入有序数组(Two Sum II - Input array is sorted)"
categories: Leetcode
tags: Leetcode Array TwoPointers BinarySearch
excerpt: ""
---

* content
{:toc}

若两个指针指向同一数组，遍历方向相同且不会相交，则也称为滑动窗口（两个指针包围的区域即为当前的窗口），经常用于区间搜索。

若两个指针指向同一数组，但是遍历方向相反，则可以用来进行搜索，待搜索的数组往往是排好序的。

167. 两数之和 II - 输入有序数组

给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted)

Link：[https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

## 双指针

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        
        while left < right:
            tmp = numbers[left] + numbers[right]
        
            if tmp == target:
                return [left + 1, right + 1]
            
            if tmp > target:
                right -= 1
            else:
                left += 1
                
        return []
```

## 二分搜索

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        
        for i in range(len(numbers)):
            num = numbers[i]
            
            left = i + 1
            right = len(numbers) - 1
            
            while left <= right:
                mid = left + (right - left) // 2
                print(numbers[mid], num)
                tmp = numbers[mid] + num
                if tmp == target:
                    return [i + 1, mid + 1]
                
                if tmp > target:
                    right = mid - 1
                else:
                    left = mid + 1
                    
        return []
```

--End--


