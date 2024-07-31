---
layout: post
index: 112
title: "LeetCode-112.路径总和(Path Sum)"
categories: Leetcode
tags: Leetcode Tree DFS
excerpt: "一切都是最好的安排"
---

* content
{:toc}

## 112. 路径总和

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例1: 

![图片说明](./images/leetcode-algorithm-112-1.jpg)

```
输入: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
```

示例2: 

![图片说明](./images/leetcode-algorithm-112-2.jpg)

```
输入: root = [1,2,3], targetSum = 5
输出: false
```

示例3: 

```
输入: root = [1,2], targetSum = 0
输出: false
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/path-sum/](https://leetcode-cn.com/problems/path-sum/)

Link：[https://leetcode.com/problems/path-sum/](https://leetcode.com/problems/path-sum/)

## 深度优先搜索

O(N)

把左右分之的判断之后，如果没有答案，才能返回错误的结果，这样不会遗漏答案

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        
        if root is None:
            return False
        
        return self.helper(root, 0, targetSum)
        
    def helper(self, node: TreeNode, ans: int, target: int) -> bool:
        
        if node.left is None and node.right is None:
            return ans + node.val == target
        
        if node.left is not None and self.helper(node.left, ans + node.val, target):
            return True
        
        if node.right is not None and self.helper(node.right, ans + node.val, target):
            return True
        
        return False
```

去掉Helper函数的递归，一开始可能不太容易直接写出这个，可以先用上面的尝试，慢慢的过度到下面

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        
        if root is None:
            return False
        
        if root.left is None and root.right is None:
            return targetSum == root.val
        
        if self.hasPathSum(root.left, targetSum - root.val):
            return True
        
        if self.hasPathSum(root.right, targetSum - root.val):
            return True
        
        return False
```

简洁代码

```python
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        
        if root is None:
            return False
        
        if root.left is None and root.right is None:
            return sum == root.val
            
        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)
```

--End--


