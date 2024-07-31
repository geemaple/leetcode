---
layout: post
index: 4
title: "LeetCode-4.寻找两个正序数组的中位数(Median of Two Sorted Arrays)"
categories: Leetcode
tags: Leetcode Array BinarySearch Divide&Conquer
excerpt: "我变秃了也变强了"
---

* content
{:toc}

⚠️前方，高能预警

整体难度: Easy难度通过率%50, Medium难度通过率%30, Hard难度通过率%10

这是第一道Hard的题目, 时间复杂度有要求，对于这样的时间复杂度 

第一，思路不好想

第二，两个数组，细节处理比较多

## 4. 寻找两个正序数组的中位数

给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

```
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
```

示例 2:

```
nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/median-of-two-sorted-arrays/](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

Link：[https://leetcode.com/problems/median-of-two-sorted-arrays/](https://leetcode.com/problems/median-of-two-sorted-arrays/)

### 暴力破解

O(M+N)

如果```M + N```是奇数, 只要数到中间那个，返回即可, ```index = (m + n) / 2```

如果```M + N```是偶数, 需要返回中间两个数的平均值, ```index1 = (m + n) / 2 - 1, index2 = (m + n) / 2```

### 分治法

O(log(M+N))

假设```M + N```长度无穷大，也就是说给两个数组，分别后面加上无穷多个inf, 即```val = arr[i] if i < len(arr) else float('inf')```

那么我们要做的是，找到**第k大**的数

示例 1:

```
nums1 = [1, 3, inf, ...]
nums2 = [2, inf, ...]
找到第2大的数, (m + n) / 2
```

示例 2:

```
nums1 = [1, 2, inf, ...]
nums2 = [3, 4, inf, ...]

找到第2大的数, (m + n) / 2
找到第3大的数, (m + n) / 2 + 1
```

逆向思路，log时间复杂度的精髓是，用O(1)的时间, 把问题缩小一般， 即```T(N) = T(N/2) + O(1)```, 如果每次我们能砍掉k/2的问题，那么有完美达到题目的要求

#### 思路

用nums1, nums2各出```k/2个```数，组成最终的长度为k的数组。

如果```nums1[k/2 - 1] < nums2[k/2 - 1]```, 那么```nums1[k/2 - 1]```不可能成为第k大的数, 同样的(k/2 - 1)左边的数也不可能是。可以排除

如果，有任意数组用完了，那么第k个数，就在另一个数组中。

**注意，k = 1时候的边界判断**

```python
from typing import List
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        m = len(nums1)
        n = len(nums2)
        
        k = (m + n + 1) // 2
        val = self.findKthNumber(nums1, nums2, k)
        if (m + n) % 2 == 0:
            val += self.findKthNumber(nums1, nums2, k + 1)
            return val / 2
        else:
            return val
        
    def findKthNumber(self, nums1: List[int], nums2: List[int], k: int) -> float:
        
        if len(nums1) == 0:
            return nums2[k - 1]
            
        if len(nums2) == 0:
            return nums1[k - 1]
            
        if k == 1:
            return min(nums1[0], nums2[0])
            
        mid = k // 2
        val1 = nums1[mid - 1] if mid <= len(nums1) else float('inf')
        val2 = nums2[mid - 1] if mid <= len(nums2) else float('inf')
        
        if val1 <= val2:
            return self.findKthNumber(nums1[mid:], nums2, k - mid)
        else:
            return self.findKthNumber(nums1, nums2[mid:], k - mid)
```

使用起始坐标，这样变量多了些，但是不用在每次拷贝数组

```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        count = len(nums1) + len(nums2)
        if (count % 2 == 1):
            return self.find_kth_num(nums1, 0, nums2, 0, (count + 1) // 2)
        else:
            mid = count // 2
            return (self.find_kth_num(nums1, 0, nums2, 0, mid) + self.find_kth_num(nums1, 0, nums2, 0, mid + 1)) / 2.0
        
        
    def find_kth_num(self, nums1, start1, nums2, start2, k):
        if start1 >= len(nums1):
            return nums2[start2 + k - 1]
        
        if start2 >= len(nums2):
            return nums1[start1 + k - 1]
        
        if k == 1:
            return min(nums1[start1], nums2[start2])
        
        half = k // 2
        left_half = nums1[start1 + half - 1] if start1 + half - 1 < len(nums1) else float('inf')
        right_half = nums2[start2 + half - 1] if start2 + half - 1 < len(nums2) else float('inf')
        
        if left_half <= right_half:
            return self.find_kth_num(nums1, start1 + half, nums2, start2, k - half)
        else:
            return self.find_kth_num(nums1, start1, nums2, start2 + half, k - half)
```

### 二分法

> 这是一个经典的，想不到用二分能解决的问题

O(Log(min(m, n))

中位数, 使其左边 vs. 右边的元素个数相等，左边都 <= 中位数，右边 >= 中位数

#### 整体思路

假设小的数组nums1，大一点的数组num2, 也就是len(nums1) < len(nums2)

把两个数组想象成两个长条蛋糕，如下

```
aaaaaaaaaaaaaaaaaaaaa
bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
```

如果，随便切一刀蛋糕A

```
aaaaaaaaaaaaaaaa | aaaaa 
bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
```

那么一定可以找到，蛋糕B上的一个切割处，使得左右两边蛋糕大小是几乎相等的

```
aaaaaaaaaaaaaaaa | aaaaa  
        bbbbbbbb | bbbbbbbbbbbbbbbbbbbbbbbbbbbb
           左边  vs. 右边
```

#### 具体分析

我们仔细看切口(A1 <= A2, B1 <= B2)，这是已知条件

**情况1:** 如果A1 <= B2 && B1 <= A2, 也就是左边的数都比右边小 , 那么中位数候选人就只能是MAX(A1, B1)和MIN(A2, B2), 奇数偶数先忽略

```
aaaaaaaaaaaaaaaA1 | A2aaaa  
        bbbbbbbB1 | B2bbbbbbbbbbbbbbbbbbbbbbbbbbb
           左边  vs. 右边
```

**情况2:** 如果 A1 > B2, 那说明, 蛋糕A切口应该向左移动(➡️右边就肯定不对了)，这样A1会变小，相应的蛋糕B切口向右移动，B2会变大

```
             <----
aaaaaaaaaaaaaaaA1 | A2aaaa  
        bbbbbbbB1 | B2bbbbbbbbbbbbbbbbbbbbbbbbbbb
                   ---->
```

情况3: 如果 B1 > A2, 那说明, 蛋糕A切口应该向右移动(⬅️左边就肯定不对了)，这样A2会变大，相应的蛋糕B切口应该向左移动，B1会变小

```
                   ---->
aaaaaaaaaaaaaaaA1 | A2aaaa  
        bbbbbbbB1 | B2bbbbbbbbbbbbbbbbbbbbbbbbbbb
             <----
```

#### 实现细节

**N个数，有N+1个切割方法:**

0个数只有一种切法: 左右都是空 ```' | '```

1个数有两种切法: 左边为空，或者右边为空```' |1| '``` , 以此类推

```
       ｜0 ｜ 1 ｜ 2 ｜ 3 ｜ 4 ｜ 5 ｜
切割点: 0   1    2   3    4    5    6
```

先不考虑数组越界的情况，假设蛋糕A切割点为i,

那么切口左侧的数为nums[i - 1], 右侧数为nums[i]

**同时，左侧个数=i，右侧个数 = m - i**

对于蛋糕B切割点**j， i + j = (m + n)/ 2, 所以j = (m + n) / 2 - i**

结论是，我们只要在小的蛋糕 上找到一个合适的切割点(二分排除一半)，题目就完成了

```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
            
        m = len(nums1)
        n = len(nums2)
        
        start = 0
        end = m
        
        while (start <= end):
            mid = start + (end - start) // 2
            leftNums1 = nums1[mid - 1] if mid >= 1 else float('-inf')
            rightNums1 = nums1[mid] if mid < len(nums1) else float('inf')
            
            anchor = (m + n) // 2 - mid
            leftNums2 = nums2[anchor - 1] if anchor >= 1 else float('-inf')
            rightNums2 = nums2[anchor] if anchor < len(nums2) else float('inf')

            if leftNums1 <= rightNums2 and leftNums2 <= rightNums1:
                if (m + n) % 2 == 1:
                    return min(rightNums1, rightNums2)
                else:
                    return (max(leftNums1, leftNums2) + min(rightNums1, rightNums2)) / 2.0
            
            if leftNums1 > rightNums2:
                end = mid - 1
            
            if leftNums2 > rightNums1:
                start = mid + 1
```

--End--


