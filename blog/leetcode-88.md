---
layout: post
index: 88
title: "LeetCode-88.合并两个有序数组(Merge Sorted Array)"
categories: Leetcode
tags: Leetcode Array TwoPointers
excerpt: "我的战役"
---

* content
{:toc}

## 88. 合并两个有序数组

给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

说明：

```
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
```

示例：

```
输入：
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出：[1,2,2,3,5,6]
```
 
提示：

```
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/merge-sorted-array](https://leetcode-cn.com/problems/merge-sorted-array)

Link：[https://leetcode.com/problems/merge-sorted-array/](https://leetcode.com/problems/merge-sorted-array/)

## 暴力破解

O(M)

正着排序会造成数组移动，那倒着来就可以了，依次把较大的放在后面

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        cur = len(nums1) - 1
        i = m - 1
        j = n - 1
        
        while i >= 0 or j >= 0:
            val1 = nums1[i] if i >= 0 else float('-inf')
            val2 = nums2[j] if j >= 0 else float('-inf')
            
            if val1 >= val2:
                nums1[cur] = val1
                i -= 1
            else:
                nums1[cur] = val2
                j -= 1

            cur -= 1
```

再简化

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        cur = m + n - 1
        i = m - 1
        j = n - 1
        
        while j >= 0:

            if i >= 0 and nums1[i] >= nums2[j]:
                nums1[cur] = nums1[i]
                i -= 1
            else:
                nums1[cur] = nums2[j]
                j -= 1

            cur -= 1
```

## One More Thing

> C++中，i++ 和 ++i 都是将i加1, 但是i++返回值为i，而++i返回值为i+1。如果只是希望增加i的值，而不需要返回值，则推荐使用++i，其运行速度会略快一些。因为i++的旧值要保存以备接下来用到。不过现代编译器应该是可以优化的

--End--
