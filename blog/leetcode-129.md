---
layout: post
index: 129
title: "LeetCode-129.求根节点到叶节点数字之和(Sum Root to Leaf Numbers)"
categories: Leetcode
tags: Leetcode Tree DFS
excerpt: "世界的凛冬"
---

* content
{:toc}

## 129. 求根节点到叶节点数字之和

给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。

示例 1：

![图片说明](./images/leetcode-algorithm-129-1.png) 

```
输入：root = [1,2,3]
输出：25
解释：
从根到叶子节点路径 1->2 代表数字 12
从根到叶子节点路径 1->3 代表数字 13
因此，数字总和 = 12 + 13 = 25
```

示例 2：

![图片说明](./images/leetcode-algorithm-129-2.png) 

```
输入：root = [4,9,0,5,1]
输出：1026
解释：
从根到叶子节点路径 4->9->5 代表数字 495
从根到叶子节点路径 4->9->1 代表数字 491
从根到叶子节点路径 4->0 代表数字 40
因此，数字总和 = 495 + 491 + 40 = 1026
```

提示：

```
树中节点的数目在范围 [1, 1000] 内
0 <= Node.val <= 9
树的深度不超过 10
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/)

Link：[https://leetcode.com/problems/sum-root-to-leaf-numbers/](https://leetcode.com/problems/sum-root-to-leaf-numbers/)

## 深度优先搜索

O(N)

从根节点出发，找到所有叶子路径的数字​

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        
        if root is None:
            return 0

        res = []
        self.helper(root, 0, res)
        return sum(res)
        
    def helper(self, node: TreeNode, candidate: int, res: list[int]):
        candidate = candidate * 10 + node.val
        if node.left is None and node.right is None:
            res.append(candidate)
            return
        
        if node.left is not None:
            self.helper(node.left, candidate, res)

        if node.right is not None:
            self.helper(node.right, candidate, res)
```

## 递归

O(N)

递归三要素：

1. 递归的定义，当前节点的所有路径和 = 左右子节点的结果相加
2. 递归的拆解，叶子节点+普通节点如何处理
3. 递归的出口，return尽早返回

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        return self.helper(root, 0)
    
    def helper(self, node: TreeNode, total: int) -> int:
        if node is None:
            return 0
        
        total = total * 10 + node.val
        if node.left is None and node.right is None:
            return total
        
        return self.helper(node.left, total) + self.helper(node.right, total)
```

--End--