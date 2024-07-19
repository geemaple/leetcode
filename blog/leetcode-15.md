---
layout: post
index: 15
title: "LeetCode-15.三数之和(3Sum)"
categories: Leetcode
tags: Leetcode Array TwoPointers
excerpt: "三刀流"
---

* content
{:toc}

## 15. 三数之和

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例：

```
给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/3sum/](https://leetcode-cn.com/problems/3sum/)

Link：[https://leetcode.com/problems/3sum/](https://leetcode.com/problems/3sum/)

## 双指针

O(N^2)

之前的[Two Sum](http://geemaple.github.io/2020/07/06/leetcode-1/), 是有哈希和双指针两种解法的。

但是，对于本题，不能包含重复答案。对于这样的限制。**排序更容易去重复, 需选择合适的代表**, 所以采用双指针的方案

题目要求**a + b + c = k**, 只要遍历一遍数组，赋值给a，剩下的就变成了2数之和问题。即**b + c = k - a(k = 0)**

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        nums.sort()

        for i in range(len(nums) - 2):
            
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            a = nums[i]
            left = i + 1
            right = len(nums) - 1
            
            while left < right: # two sum

                if nums[left] + nums[right] == -a:
                    res.append([a, nums[left], nums[right]])
                    
                    while (left < right and nums[left] == nums[left + 1]):
                        left += 1
                          
                    while (left < right and nums[right] == nums[right - 1]):
                        right -= 1

                    left += 1
                    right -= 1
                elif nums[left] + nums[right] > -a:
                    right -= 1
                else:
                    left += 1
                    
        return res
```

--End--


