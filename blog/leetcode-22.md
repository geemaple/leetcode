---
layout: post
index: 22
title: "LeetCode-22.括号生成(Generate Parentheses)"
categories: Leetcode
tags: Leetcode String Backtracking
excerpt: "里程碑的21天"
---

* content
{:toc}

## 22. 括号生成

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例：

```
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/generate-parentheses/](https://leetcode-cn.com/problems/generate-parentheses/)

Link：[https://leetcode.com/problems/generate-parentheses/](https://leetcode.com/problems/generate-parentheses/)

## DFS

O(2^N)

题目要求，求出所有的组合，典型的DFS问题。

首先，从空字符开始

第二层，从''开始，由于只能添加左括号(⬅️)，右侧用X来表示没有有效路径

第三层，从'('开始, 由于右括号可以参与，左右括号(⬅️➡️)都可以。

第四层，从'(('开始，同上一步。 从'()'开始, 由于匹配规则，只能添加左括号(⬅️), 右侧用X来表示没有有效路径

第五层，从'((('开始左括号用光了，只能添加右括号(➡️), 其他分支参考前面 

...

![图片说明](./images/leetcode-sketch-algorithm-22.jpg)

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        res = []
        self.helper(0, 0, n, [], res)
        return res
        
    def helper(self, left: int, right:int, n: int, ans: List, res: List):
        
        if len(ans) == 2 * n:
            res.append(''.join(ans))
            return
        
        if left < n:
            ans.append('(')
            self.helper(left + 1, right, n , ans, res)
            ans.pop()
            
        if right < left:
            ans.append(')')
            self.helper(left, right + 1, n , ans, res)
            ans.pop()
```

如果使用字符串，代码还能再短点

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        res = []
        self.helper(0, 0, n, '', res)
        return res
        
        
    def helper(self, left: int, right:int, n: int, ans: str, res: List):
        
        if len(ans) == 2 * n:
            res.append(ans)
            return
        
        if left < n:
            self.helper(left + 1, right, n , ans + '(', res)
            
        if right < left:
            self.helper(left, right + 1, n , ans + ')', res)
```

> 因为是一颗递归树，也可以尝试用BFS搜索来试试。

--End--


