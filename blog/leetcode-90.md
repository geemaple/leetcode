---
layout: post
index: 90
title: "LeetCode-90.子集 II(Subsets II)"
categories: Leetcode
tags: Leetcode Array Backtracking
excerpt: "苏州也许是个不错的地方"
---

* content
{:toc}

## 90. 子集 II

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

```
输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/subsets-ii/](https://leetcode-cn.com/problems/subsets-ii/)

Link：[https://leetcode.com/problems/subsets-ii/](https://leetcode.com/problems/subsets-ii/)


## 回溯法

O(2^N)

首先要排序，这样便于去掉重复，其次去重复的逻辑是，相同的数字，只有仅相邻的前一个在结果中，才把当前的放入结果

```
[2, 2', 2'']
```

有效结果一定是[2], [2, 2'], [2, 2', 2'']

代码如下

```python
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        self.helper(sorted(nums), 0, [], res)
        return res
        
        
    def helper(self, nums: List[int], start: int, ans:List[int], res: List[int]):
        
        res.append(ans.copy())
        
        for i in range(start, len(nums)):
            if i > start and nums[i] == nums[i - 1]:
                continue
            
            ans.append(nums[i])
            self.helper(nums, i + 1, ans, res)
            ans.pop()
```

## 迭代法

递归有个明显的缺点就是栈溢出，那么这时候，递归是一个不错的选择

如果没有重复数字[1,2,3], 执行的逻辑是从[]开始，每次拷贝之前的结果，再在拷贝的结果上分别加上当前的元素

```python
[]

[] [1] # 拷贝[], 分别将1加入到拷贝的结果里

[] [1] [2] [1, 2]  # 拷贝[] [1]， 分别将2加入到拷贝的结果里

[] [1] [2] [1, 2] [3] [1, 3] [2, 3] [1, 2, 3]
```

但如果又重复，例如[1,2,2']，同样2'只能紧跟着2出现，不能单独出现。

正常情况下，前面的每一个都一个拷贝，加上新的元素

但是，如果遇到相等的，

```python
[]

[] [1]
        
[] [1] [2] [1, 2] # 在计算下一层时, 如果遇到相等的，把上一层last_size作为起点
        ^
     last_size

[] [1] [2] [1, 2] 

       [2, 2'] [1, 2, 2'']
```

代码如下:

```python
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        nums.sort()
        
        last_size = 0
        start = 0
        for i in range(len(nums)):
            start = last_size if i > 0 and nums[i] == nums[i - 1] else 0
            last_size = len(res)
            
            for j in range(start, len(res)):
                tmp = res[j].copy()
                tmp.append(nums[i])
                res.append(tmp)
                
        return res
```

另一种：

```python
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        nums.sort()
        
        for i in range(len(nums)):
            if i == 0 or nums[i] != nums[i - 1]:
                length = len(res)
            
            for j in range(len(res) - length, len(res)):
                tmp = res[j].copy()
                tmp.append(nums[i])
                res.append(tmp)
                
        return res    
```

--End--
