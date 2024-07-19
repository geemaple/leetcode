---
layout: post
index: 31
title: "LeetCode-31.下一个排列(Next Permutation)"
categories: Leetcode
tags: Leetcode Array
excerpt: "迟到的kickoff"
---

* content
{:toc}

## 31. 下一个排列

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。

```
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/next-permutation/](https://leetcode-cn.com/problems/next-permutation/)

Link：[https://leetcode.com/problems/next-permutation/](https://leetcode.com/problems/next-permutation/)

## 暴力破解

O(n!)

每个字都认识，说的到底是啥玩意，字典序是？？？

这里主要用暴力破解的方式，来重新解释一下题意到底是啥，以题目举例

```
[1,2,3]它的全部递增排列是:
123 < 132 < 213 < 231 < 312 < 321
对于给定的123, 它的下一个更大的是132
对于给定的321，它就是最大的，所以输出普通排序结果123

[1,1,5]它的全部递增排列是:
115 < 151 < 511
对于给定的115，它的下一个更大的是151
```

## 观察总结

O(N)

> 题目给的例子过于简单，不利于总结

以**[1,5,8,4,7,6,5,3,1]**为例

首先, 如果是一个降序排列，这个就是最大的，没有下一个了，那么就reverse一下

```
[8,7,6,5,5,4,3,1,1]
```

如果有答案，那么从后往前，需要找到第一组相邻升序列, 如下

第一组升序列是**4和7**, 把后面大于4的任意数字和4替换, 就比当前数字大了

```
[1,5,8,4,7,6,5,3,1]
       ^   
```

按题目要求，应该找一个刚刚大一点的，所以把**4和5**替换

```
[1,5,8,4,7,6,5,3,1]
       ^     ^    
```

替换之后, 原来**4**的位置后面仍然是一个降序列, 把它反转，就变成最小的满足条件的数字了

```
[1,5,8,5,7,6,4,3,1]
       ^ 
         |--反转--| 

[1,5,8,5,1,3,4,6,7]
```

代码如下:

```python
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        start = len(nums) - 2
        while start >= 0:
            if nums[start] < nums[start + 1]:
                break
            start -= 1

        if start < 0:
            self.reverse(nums, 0, len(nums) - 1)
        else:
            bigger = 0
            for i in range(start + 1, len(nums)):
                if nums[start] >= nums[i]:
                    break
                    
                bigger = i

            nums[start], nums[bigger] = nums[bigger], nums[start]
            self.reverse(nums, start + 1, len(nums) - 1)
    
    def reverse(self, nums: List[int], start: int, end: int) -> None:
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
```

--End--


