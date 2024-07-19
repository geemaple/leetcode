---
layout: post
index: 77
title: "LeetCode-77.组合(Combinations)"
categories: Leetcode
tags: Leetcode Array Backtracking BitManipulation
excerpt: ""
---

* content
{:toc}

## 77. 组合

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

```
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/combinations](https://leetcode-cn.com/problems/combinations)

Link：[https://leetcode.com/problems/combinations](https://leetcode.com/problems/combinations)

## 回溯

O(N!/(N - K)!)

代码如下

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        res = []
        self.helper(n, k, 1, [], res)
        return res
        
    def helper(self, n: int, k: int, start: int, ans: List[int], res: List[List[int]]):
    
        if len(ans) == k:
            res.append(list(ans))
            return

        for i in range(start, n + 1):
            ans.append(i)
            self.helper(n, k, i + 1, ans, res)
            ans.pop()
```

利用递归的特殊性，回溯代码可以写成**ans + [i]**

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
    
        res = []
        self.helper(n, k, 1, [], res)
        return res
        
    def helper(self, n: int, k: int, start: int, ans: List[int], res: List[List[int]]):
    
        if len(ans) == k:
            res.append(list(ans))
            return

        for i in range(start, n + 1):
            self.helper(n, k, i + 1, ans + [i], res)
```

## One More Thing

### 如何入门？

刚入门新手，应该熟练掌握基础算法和数据结构，并锻炼代码实践能力，推荐按标签🏷️来各个击破

### 如何解题？

1. 先理解题意，确定使用什么算法。不要边写边思考，避免思路回滚。建议先将思路，甚至把代码在脑海里过一遍再写
2. 看重代码时间复杂度，而不是具体执行时间，有些题目测试数量比较少，可能出现复杂度低反而运行更多时间的情况
3. 简化代码，思考逻辑简洁的解法，避免繁琐的逻辑判断。参考别人同时间复杂度但是更简洁的代码
4. 把代码打印出来，或者在白板，word等软件中书写检验代码，锻炼肉眼debug的能力

--End--
