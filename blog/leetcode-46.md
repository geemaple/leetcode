---
layout: post
index: 46
title: "LeetCode-46.全排列(Permutations)"
categories: Leetcode
tags: Leetcode Backtracking
excerpt: "Flutter"
---

* content
{:toc}

## 46. 全排列

给定一个**没有重复**数字的序列，返回其所有可能的全排列。

示例:

```
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/permutations/](https://leetcode-cn.com/problems/permutations/)

Link：[https://leetcode.com/problems/permutations/](https://leetcode.com/problems/permutations/)

## DFS

O(N!)

排列组合, DFS必背程序之一

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
            if nums[i] in visited:
                continue
                
            ans.append(nums[i])
            visited.add(nums[i])
            
            self.helper(nums, ans, visited, res)
            
            ans.pop()
            visited.remove(nums[i])
```

## 为啥学算法?

1. 面试需要：这点很实际，也许算法并不能帮你拿到Offer，但是若算法题做不出来，极有可能错失良机
2. 技能迁移：我认为程序开发主要依赖语言+算法+平台Framework+协议. 入行新的领域，可能要学新的语言，新的平台框架，新的协议。但是算法是可以迁移的。
3. 内功修炼：操作系统，计算机网络，编译原理，开源框架，处处存在算法。修好算法，可以事半功倍。
4. 屠龙神技："面试造火箭，工作拧螺丝"。也许世界上龙很少出现，但是一旦出现，唯有身怀神技的猎手才有机会

--End--