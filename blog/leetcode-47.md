---
layout: post
index: 47
title: "LeetCode-47.全排列 II(Permutations II)"
categories: Leetcode
tags: Leetcode Backtracking
excerpt: "吉祥物Dash"
---

* content
{:toc}

## 47. 全排列 II

给定一个**可包含重复**数字的序列，返回所有不重复的全排列。

示例:

```
输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/permutations-ii/](https://leetcode-cn.com/problems/permutations-ii/)

Link：[https://leetcode.com/problems/permutations-ii/](https://leetcode.com/problems/permutations-ii/)

## 46. Permutations答案更新

上一题没有重复的数字，可以用数字来做唯一标识，为了兼容可能重复情况，改进使用数组下标i

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        visited = set()
        self.helper(nums, [], visited, res)
        return res
        
    def helper(self, nums: List[int], ans: List[int], visited: set, res:List[int]) -> None:
        
        if len(ans) == len(nums):
            res.append(ans.copy())
            return
        
        for i in range(len(nums)):
            if i in visited:
                continue
              
            visited.add(i)
            ans.append(nums[i])
            
            self.helper(nums, ans, visited, res)
            
            ans.pop()
            visited.remove(i)
```

## DFS

O(N!)

1. 为了去重复，先把数组排序[1, 1', 2]
2. 选代表，比如[1, 1', 2]和[1', 1, 2]选第一个顺眼的作为代表，那么条件就是，如果数字相同，上一个在答案中才继续添加

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        visited = set()
        self.helper(sorted(nums), [], visited, res) # 排序
        return res
        
    def helper(self, nums: List[int], ans: List[int], visited: set, res:List[int]) -> None:
        
        if len(ans) == len(nums):
            res.append(ans.copy())
            return
        
        for i in range(len(nums)):
            if i in visited:
                continue
                
            if (i > 0 and nums[i] == nums[i - 1] and i - 1 not in visited):
                continue
              
            visited.add(i)
            ans.append(nums[i])
            
            self.helper(nums, ans, visited, res)
            
            ans.pop()
            visited.remove(i)
```

--End--