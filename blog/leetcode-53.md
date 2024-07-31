---
layout: post
index: 53
title: "LeetCode-53.最大子序和(Maximum Subarray)"
categories: Leetcode
tags: Leetcode Array DP Divide&Conquer
excerpt: "和平，土地，面包"
---

* content
{:toc}

## 53. 最大子序和

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

```
输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```

进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/maximum-subarray](https://leetcode-cn.com/problems/maximum-subarray)

Link：[https://leetcode.com/problems/maximum-subarray](https://leetcode.com/problems/maximum-subarray)

## 暴力破解

O(N^3)

子数组数量级是O(N^2)个, 每一个分别求和O(N), 从这些找到满足条件的即可

### 子数组

子数组**a[i : j)**, (j > i)

```
i = 0, j = 1, 2, 3, ... n             (n - 1）
i = 1, j =    2, 3, ... n             (n - 2)
i = 2, j =       3, ... n             (n - 3)
...                                       ...
i = n-1, j = n                              1
```

## 前缀和

O(N)

```
sumTo[i]代表前i个元素的总和, 其中sumTo[0] = 0

sumTo[i] = sumTo[0] + sumTo[1] + ... + sumTo[i - 1]

a[i : j) = sumTo[j] - sumTo[i]
```

如果当前和 - **前面计算过**最小的那个, 也可以得出答案

可以尝试画一条前缀和的函数曲线

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        largest = float('-inf')
        smallest = 0
        sumTo = 0

        for num in nums:
            sumTo += num
            largest = max(largest, sumTo - smallest)
            smallest = min(smallest, sumTo)

        return largest
```

## 动态规划

O(N)

### 定义

定义dp = **截止到第i个元素(且包含第i个)**的最长子数组

### 递推公式

```python
dp[i] = max(nums[i], nums[i] + dp[i - 1])
               ^             ^
             新起点      新元素与前面拼接上
```

### 边界条件

dp[0] = nums[0]

### 计算方向

i从小到大

### 动归代码

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [float('-inf') for i in range(len(nums))]
        dp[0] = nums[0]
        
        for i in range(1, len(nums)):
            dp[i] = max(nums[i], nums[i] + dp[i - 1])
        
        return max(dp)
```

### 空间压缩

O(1)空间复杂度

计算会发现，dp只有最后一个元素用得上，那么前面的就都可以不用了

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        largest = sumTo = nums[0]
        for i in range(1, len(nums)):
            sumTo = max(nums[i], nums[i] + sumTo)
            if sumTo > largest:
                largest = sumTo
        
        return largest
```

### One More Thing

空间压缩中的上述代码, 演变如下:

新的代码有个更直观的解释，依次加入新的元素，如果出现负数，那么就抛弃之前的和

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        largest = sumTo = nums[0]
        for i in range(1, len(nums)):
            # sumTo = max(nums[i] + 0, nums[i] + sumTo)
            if sumTo < 0:
                sumTo = 0
            sumTo += nums[i]

            if sumTo > largest:
                largest = sumTo
        
        return largest

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        largest = float('-inf')
        sumTo = 0
        # for循环从下标0开始
        for i in range(len(nums)):
            if sumTo < 0:
                sumTo = 0

            sumTo += nums[i]
            if sumTo > largest:
                largest = sumTo
            
        return largest

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        largest = float('-inf')
        sumTo = 0
        
        for i in range(len(nums)):
            sumTo += nums[i]
            if sumTo > largest:
                largest = sumTo

            # 第一次sum肯定不小于0, 可以挪到末尾
            if sumTo < 0:
                sumTo = 0
            
        return largest
```

## 分治法

O(N)

分治法把数组nums，分成两半:

1. 如果答案在左边**or**右边，继续分割即可
2. 如果答案横跨左右两边，那要算出左边的连接部分 + 分割点 + 右边的连接部分

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        return self.divideAndConquer(nums, 0, len(nums) - 1)

    def divideAndConquer(self, nums: List[int], left: int, right: int) -> None:

        if left > right:
            return float('-inf')

        mid = left + (right - left) // 2
        left_max = self.divideAndConquer(nums, left, mid - 1)
        right_max = self.divideAndConquer(nums, mid + 1, right)

        total = 0
        connect_left_max = 0
        for i in range(left, mid)[::-1]:  # 从mid - 1到left
            total += nums[i]
            connect_left_max = max(total, connect_left_max)

        total = 0
        connect_right_max = 0
        for i in range(mid + 1, right + 1): #从mid + 1到right
            total += nums[i]
            connect_right_max = max(total, connect_right_max)

        # 返回[左边, 右边, 左边+mid+右边]最大的那个
        return max([left_max, right_max, connect_left_max + nums[mid] + connect_right_max])
```

--End--
