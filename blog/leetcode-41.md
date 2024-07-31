---
layout: post
index: 41
title: "LeetCode-41.缺失的第一个正数(First Missing Positive)"
categories: Leetcode
tags: Leetcode Array
excerpt: "索姆河战役"
---

* content
{:toc}

> 该题还是挺难的，我们从第一个答案开始，一步一步过渡到最终答案

## 41. First Missing Positive

给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

示例 1:

```
输入: [1,2,0]
输出: 3
```

示例 2:

```
输入: [3,4,-1,1]
输出: 2
```

示例 3:

```
输入: [7,8,9,11,12]
输出: 1
```
 
提示：

```
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/first-missing-positive/](https://leetcode-cn.com/problems/first-missing-positive/)

Link：[https://leetcode.com/problems/first-missing-positive/](https://leetcode.com/problems/first-missing-positive/)

## 哈希(字典/集合)

空间复杂度O(N)

1. 统计一下数组元素是否出现
2. 按自然数查找缺失的数字

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        
        n = len(nums)
        seen = set()
        
        for num in nums:
            if num not in seen:
                seen.add(num)
            
        for i in range(1, n + 1):
            if i not in seen:
                return i
            
        return n + 1
```

## 哈希(数组)

空间复杂度O(N)

思路与上一个相同, 只是使用数组作为集合, 哈希函数为**index = num - 1**

1. 统计一下数组元素(**1 <= num <= n**)是否出现
2. 按自然数查找缺失的数字

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        
        n = len(nums)
        seen = [False for i in range(n)]
        
        for num in nums:
            if 1 <= num <= n:
                seen[num - 1] = True
                
        for i in range(1, n + 1):
            if not seen[i - 1]:
                return i
            
        return n + 1
```

## 数组

空间复杂度O(N)

1. 第i个位置存储num, 且**i = num - 1**
2. 自然顺序，遍历数组遇到不相等的，就是答案。如果都不相等, 答案**n + 1**

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        
        n = len(nums)
        seen = [False for i in range(n)]
        
        for num in nums:
            if 1 <= num <= n:
                seen[num - 1] = num
                
        for i in range(1, n + 1):
            if i != seen[i - 1]:
                return i
            
        return n + 1
```

## 解题

空间复杂度O(1), 利用原有数组，没有使用额外空间

1. 如果**1 <= num <= n**, 把目标数字**num**移动到对应的下标下
2. 自然顺序，遍历数组遇到不相等的，就是答案。如果都不相等, 答案**n + 1**

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        
        n = len(nums)
        
        i = 0
        while i < n:
            j = nums[i] - 1
            
            if 0 <= j < n and nums[i] != nums[j]:
                nums[i], nums[j] = nums[j], nums[i]
            else:
                i += 1
                
        for i in range(1, n + 1):
            if i != nums[i - 1]:
                return i
            
        return n + 1
```

--End--


