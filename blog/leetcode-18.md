---
layout: post
index: 18
title: "LeetCode-18.四数之和(4Sum)"
categories: Leetcode
tags: Leetcode Array HashTable TwoPointers
excerpt: "K-Sum终结者"
---

* content
{:toc}

## 18. 四数之和

给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

> 答案中不可以包含重复的四元组。

示例：

```
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/4sum/](https://leetcode-cn.com/problems/4sum/)

Link：[https://leetcode.com/problems/4sum/](https://leetcode.com/problems/4sum/)

## 双指针

O(N^3)

之前的[3Sum](http://geemaple.github.io/2020/07/22/leetcode-15/), 利用的是2数之和。

这道题，我们用的是三数之和。同样不能包含重复答案。**排序更容易去重复, 需选择合适的代表**, 所以采用双指针的方案

题目要求**a + b + c + d = t**, 只要遍历一遍数组，赋值给a，剩下的就变成了3数之和问题。即**b + c + d = t - a**

```python

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums.sort()

        for i in range(len(nums) - 3):
            
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            a = nums[i]
            
            for j in range(i + 1, len(nums) - 2): # 3sum
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                b = nums[j]
                left = j + 1
                right = len(nums) - 1
                
                while left < right: # two sum

                    if a + b + nums[left] + nums[right] == target:
                        res.append([a, b, nums[left], nums[right]])
                        
                        while (left < right and nums[left] == nums[left + 1]):
                            left += 1
                            
                        while (left < right and nums[right] == nums[right - 1]):
                            right -= 1

                        left += 1
                        right -= 1
                    elif a + b + nums[left] + nums[right] > target:
                        right -= 1
                    else:
                        left += 1
                    
        return res

```

## K-Sum解法

O(N^(k-1))

你可能已经注意到了，4数解法依赖3数之和, 3数之和依赖2数之和。 符合一个递推的过程

令**k = 4**, 就符合当前问题的答案

```python

from typing import List
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        k = 4
        res = []
        nums.sort()

        if k > len(nums) or target < nums[0] * k or target > nums[-1] * k:
            return []

        self.kSum(nums, target, k, 0, [], res)
        return res

    def kSum(self, nums: List[int], target: int, k: int, start: int, ans: List[int], res: List[List]):
    
        if k == 2:
            self.twoSum(nums, target, k, start, ans, res)
            return

        for i in range(start, len(nums) - k + 1):
            if i > start and nums[i] == nums[i - 1]:
                continue
            
            ans.append(nums[i])
            self.kSum(nums, target, k - 1, i + 1, ans, res)
            ans.pop()

    def twoSum(self, nums: List[int], target: int, k: int, start: int, ans: List[int], res: List[List]):
        left = start
        right = len(nums) - 1

        while left < right:
            total = sum(ans) + nums[left] + nums[right]

            if total == target:
                ans.append(nums[left])
                ans.append(nums[right])
                res.append(ans.copy())
                ans.pop()
                ans.pop()

                while (left < right and nums[left] == nums[left + 1]):
                    left += 1
                while (left < right and nums[right] == nums[right - 1]):
                    right -= 1

                left += 1
                right -= 1
            elif total > target:
                right -= 1
            else:
                left += 1
```

--End--


