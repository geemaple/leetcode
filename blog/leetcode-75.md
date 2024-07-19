---
layout: post
index: 75
title: "LeetCode-75.颜色分类(Sort Colors)"
categories: Leetcode
tags: Leetcode Array TwoPointers Sort
excerpt: ""
---

* content
{:toc}

## 75. 颜色分类

给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:

不能使用代码库中的排序函数来解决这道题。

示例:

```
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
```

进阶：

```
一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/sort-colors](https://leetcode-cn.com/problems/sort-colors)

Link：[https://leetcode.com/problems/sort-colors](https://leetcode.com/problems/sort-colors)

## 简单计数

O(N)

把[0,1,2]数量分别记下来，最后填充起来

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count_zero = count_one = count_two = 0
        
        for num in nums:
            if num == 0:
                count_zero += 1
            elif num == 1:
                count_one += 1
            else:
                count_two += 1
            
        for i in range(count_zero):
            nums[i] = 0
            
        for i in range(count_zero, count_zero + count_one):
            nums[i] = 1
            
        for i in range(count_zero + count_one, count_zero + count_one + count_two):
            nums[i] = 2
```

## 计数排序

O(N)

也叫Counting-Sort

```
 000000...  1111111...  2222222
   m           n           k
   m         m + n     k + m + n
  sum1        sum2        sum3
如果是0, 放在下标(sum1 - 1)的位置, sum1计数减一
如果是1, 放在下标(sum2 - 1)的位置, sum2计数减一
如果是2, 放在下标(sum3 - 1)的位置, sum3计数减一
```
代码如下:

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count_table = [0 for i in range(3)]
        
        # 计数
        for num in nums:
            count_table[num] += 1
        
        #  计算sum1 ... sumN
        for i in range(1, len(count_table)):
            count_table[i] += count_table[i - 1]
            
        # 按下标放置数字
        for num in nums.copy():
            index = count_table[num] - 1
            nums[index] = num
            count_table[num] -= 1
```

## 双指针

O(N)

用i作为0的右边界, 不包含i, i作为0的候选替换元素

用j作为2的左边界, 不包含j, j作为2的候选替换元素

下标k用来扫描数组, k <= j时 结束

```
[0,0,1,1,2,2]
     i j
k -------->
```

代码如下：

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        i = k = 0
        j = len(nums) - 1
        
        while k <= j:
            if nums[k] == 0:
                nums[i], nums[k] = nums[k], nums[i]
                i += 1
                k += 1
            elif nums[k] == 2:
                nums[j], nums[k] = nums[k], nums[j]
                j -= 1
            else:
                k += 1
        
```

## 刷油漆

O(N)

```
[2,0,2,1,1,0]

 2 2 2 2 2 2 首先都刷成2
 
 1 1 1 1     <2的部分刷成1

 0 0         =0的部分刷成0

```

代码如下:

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        i = j = 0
        for k in range(len(nums)):
            value = nums[k]
            
            nums[k] = 2
            
            if value < 2:
                nums[i] = 1
                i += 1
                
            if value == 0:
                nums[j] = 0
                j += 1
```

--End--