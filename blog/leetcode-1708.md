---
layout: post
index: 1708
title: "LeetCode-1708.长度为K的最大子数组(Largest Subarray Length K)"
categories: Leetcode
tags: Leetcode Array Greedy
excerpt: "青山相待，白云相爱"
---

* content
{:toc}

## 1708. 长度为K的最大子数组

数组A大于数组B, 也就是从第一个不相等的位置i起(A[i] != B[i]), A[i]大于B[i] 

例如，以下数组(从下标0开始)

For example, consider 0-indexing:

[1,3,2,4] > [1,2,2,4], 在下标1, 3 > 2.
[1,4,4,4] < [2,1,1,1], 在下标0, 1 < 2.

子数组是Array[i:j]连续的元素

给一个不重复的数组，返回最大的长度为k的子数组

示例 1：

```
输入: nums = [1,4,5,2,3], k = 3
输出: [5,2,3]
解释: 长度为3的子数组有: [1,4,5], [4,5,2], and [5,2,3]。 其中[5,2,3]是最大的.
```

示例 2:

```
输入: nums = [1,4,5,2,3], k = 4
输出: [4,5,2,3]
解释: 长度为4的子数组有: [1,4,5,2], and [4,5,2,3]。其中[4,5,2,3]是最大的.
```


示例 3:

```
输入: nums = [1,4,5,2,3], k = 1
输出: [5]
```

提示：

```
1 <= k <= nums.length <= 105
1 <= nums[i] <= 109
所有元素都是独一无二的
```
 

Follow up: 如果有重复元素, 何解？

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/largest-subarray-length-k/](https://leetcode-cn.com/problems/largest-subarray-length-k/)

Link：[https://leetcode.com/problems/largest-subarray-length-k/](https://leetcode.com/problems/largest-subarray-length-k/)


## 暴力破解

会超时

```python
class Solution:
    def largestSubarray(self, nums: List[int], k: int) -> List[int]:
        
        res = nums[:k]
        for i in range(1, len(nums) - k + 1):
            tmp = nums[i: i + k]
            if self.larger(tmp, res):
                res = tmp
                
        return res
        
        
    def larger(self, a: List[int], b: List[int]) -> bool:
        
        for i in range(len(a)):
            if a[i] == b[i]:
                continue
                
            elif a[i] > b[i]:
                return True
            else:
                return False
            
        return False
```

## 贪心

O(N)

既然没有重复元素，那么每个子数组的**头元素**都不一样, 只要判断头元素就可以了

由于取子数组也比较耗时，只保存头元素下标 + 长度就可以确定结果了

```python
class Solution:
    def largestSubarray(self, nums: List[int], k: int) -> List[int]:
        i = 0
        for j in range(1, len(nums) - k + 1):
            if nums[j] > nums[i]:
                i = j
                
        return nums[i : i + k]
```

## One More Thing

有重复的情况，由于无法测试代码，以简单可行为主

O(N^2)

使用一个Count值，记录重复个数，把重复掠过

```python
class Solution:
    def largestSubarray(self, nums: List[int], k: int) -> List[int]:
        
        i = 0
        for j in range(1, len(nums) - k + 1):
            count = 0
            while count < k and nums[j + count] == nums[i + count]:
                count += 1

            if nums[j + count] > nums[i + count]:
                i = j
                
        return nums[i : i + k]
```

--End--


