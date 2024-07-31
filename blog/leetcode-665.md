---
layout: post
index: 665
title: "LeetCode-665.非递减数列(Non-decreasing Array)"
categories: Leetcode
tags: Leetcode Array
excerpt: ""
---

* content
{:toc}

## 665. 非递减数列

给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。

示例 1:

```
输入: nums = [4,2,3]
输出: true
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
```

示例 2:

```
输入: nums = [4,2,1]
输出: false
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
```

说明：

```
1 <= n <= 10 ^ 4
- 10 ^ 5 <= nums[i] <= 10 ^ 5
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/non-decreasing-array/](https://leetcode-cn.com/problems/non-decreasing-array/)

Link：[https://leetcode.com/problems/non-decreasing-array/](https://leetcode.com/problems/non-decreasing-array/)

## 贪心

O(N)

题目要求a1 <= a2 <= a3 <= ... <= aN

那么如果遇到a(i - 1) > a(i)的情况，改变次数就增加一次

```python

 0        i
 1 1 3 4 [2] 5 6  # a[i - 2] > a[i],  所以a[i] = 4
          4

 1 1 2 [4] 2 3 4  # a[i - 2] <= a[i], 所以a[i - 1] = 2
        2
```

两种可能，一种该左边的值(变小)，一种改右边的值(变大)

最优策略是，改左边的值，不然a(i)增大可能会影响之后的结果

一种情况例外，就是a(i - 2) > a(i), 那就说明a(i)确实太小了，需要增大

```python
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        
        count = 0
        i = 1
        while i < len(nums) and count <= 1:
            if nums[i - 1] > nums[i]:
                count += 1
                
                if i - 2 >= 0 and nums[i - 2] > nums[i]:
                    nums[i] = nums[i - 1]
                else:
                    nums[i - 1] = nums[i]
                
            i += 1
                
        return count <= 1
```

--End--


