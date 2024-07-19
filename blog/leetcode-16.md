---
layout: post
index: 16
title: "LeetCode-16.最接近的三数之和(3Sum Closest)"
categories: Leetcode
tags: Leetcode Array TwoPointers
excerpt: "栀子花套房"
---

* content
{:toc}

## 16. 最接近的三数之和

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

示例：

```
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
```

提示：

```
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/3sum-closest/](https://leetcode-cn.com/problems/3sum-closest/)

Link：[https://leetcode.com/problems/3sum-closest/](https://leetcode.com/problems/3sum-closest/)

## 双指针

O(N^2)

与前的[3Sum](http://geemaple.github.io/2020/07/22/leetcode-15/)非常相似。本题是找出最接近的

双指针在移动过程中，也是有判断目标值接近程度的:

如果**left + right > target**, 那么只有**right--**, 才能更接近目标

如果**left + right < target**, 那么只有**left++**, 才能更接近目标

只要遍历一遍数组，赋值给a, 剩下的两数之和用双指针, 打擂台, 记录**a + b + c = k, k与目标最接近**的答案

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        res = float('inf')
        nums.sort()

        for i in range(len(nums) - 2):            
            a = nums[i]
            left = i + 1
            right = len(nums) - 1
            
            while left < right:
                threeSum = a + nums[left] + nums[right]
                if abs(threeSum - target) < abs(res - target): #打擂台
                    res = threeSum
                    
                if threeSum == target:
                    break
                elif threeSum > target:
                    right -= 1
                else:
                    left += 1
                    
        return res

```

> 只有确定指针移动方向，才能在该方向去重复

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        closest = float('inf')
        nums.sort()

        for i in range(len(nums) - 2):
            
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            a = nums[i]
            left = i + 1
            right = len(nums) - 1
            
            while left < right:

                threeSum = a + nums[left] + nums[right]
                
                if abs(threeSum - target) < abs(closest - target):
                    closest = threeSum
                    
                if threeSum == target:
                    break
                elif threeSum > target:
                    while (left < right and nums[right] == nums[right - 1]): #去重复
                      right -= 1
                    right -= 1
                else:
                    while (left < right and nums[left] == nums[left + 1]): #去重复
                      left += 1
                    left += 1
                    
        return closest
```

--End--


