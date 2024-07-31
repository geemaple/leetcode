---
layout: post
index: 153
title: "LeetCode-153.寻找旋转排序数组中的最小值(Find Minimum in Rotated Sorted Array)"
categories: Leetcode
tags: Leetcode Array BinarySearch
excerpt: ""
---

* content
{:toc}

假设按照升序排序的数组在预先未知的某个点上进行了旋转。例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。

请找出其中最小的元素。

示例 1：

```
输入：nums = [3,4,5,1,2]
输出：1
```

示例 2：

```
输入：nums = [4,5,6,7,0,1,2]
输出：0
```

示例 3：

```
输入：nums = [1]
输出：1
```

提示：

```
1 <= nums.length <= 5000
-5000 <= nums[i] <= 5000
nums 中的所有整数都是 唯一 的
nums 原来是一个升序排序的数组，但在预先未知的某个点上进行了旋转
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array)

Link：[https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)


## 暴力破解

O(N)

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:

        res = nums[0]
        for num in nums:
            res = min(res, num)

        return res
```

## 二分法

O(LogN)

比较mid和最后一个节点, 如果mid > last说明是分成了两段的，且mid在左边

如果mid < last, 无论那种情况，右边都不用考虑了

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid

        return nums[left]
```

--End--