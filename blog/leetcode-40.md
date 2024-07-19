---
layout: post
index: 40
title: "LeetCode-40.组合总和 II(Combination Sum II)"
categories: Leetcode
tags: Leetcode Array Backtracking
excerpt: "剪枝优化"
---

* content
{:toc}

> 深度优先搜索复杂度很高的，剪枝是比较有效的优化策略

## 40. 组合总和 II

给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 

示例 1:

```
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```

示例 2:

```
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/combination-sum-ii/](https://leetcode-cn.com/problems/combination-sum-ii/)

Link：[https://leetcode.com/problems/combination-sum-ii/](https://leetcode.com/problems/combination-sum-ii/)

## DFS

> 与上一道题相比，本题的关键点在于去重复, 而且每个元素只能用一次

### 如何选代表去重复

以[10,1,2,7,6,1,5]为例, 排序编号后:

```
[1, 1', 2, 5, 6, 7, 10]
```

选代表:

```
[1, 7] 与 [1‘ 7] 选用[1, 7]作为代表

[1，2, 5] 与 [1', 2, 5] 选用[1，2, 5]作为代表​

[1, 1', 6] 与 [1', 1, 6] 选用[1, 1', 6]作为代表​

```

特点是:

对于编号重复数字，选的代表具有以下两个特征:

1. 编号一定是递增出现的, 不能跳过出现
2. 如果前一个编号没有出现，那么后续的也没有必要出现

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:        
        res = []
        candidates.sort()
        self.helper(candidates, target, 0, [], res)
        return res
        
    def helper(self, candidates: List[int], target: int, start: int , ans: List[int] , res : List[List[int]]) -> None:
        
        total = sum(ans)
        if total > target:
            return 
        
        if total == target:
            res.append(ans.copy())
            return
        
        for i in range(start, len(candidates)):
            # i == start表示允许相同数字递增出现，c[i] != [i - 1]允许不同数字出现
            if i == start or candidates[i] != candidates[i - 1]: 
                ans.append(candidates[i])
                self.helper(candidates, target, i + 1, ans, res) # (i + 1)数字不能重复使用
                ans.pop()
```

--End--


