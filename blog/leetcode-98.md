---
layout: post
index: 98
title: "LeetCode-98.验证二叉搜索树(Validate Binary Search Tree)"
categories: Leetcode
tags: Leetcode String DP
excerpt: "候鸟"
---

* content
{:toc}

## 98. 验证二叉搜索树

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。

节点的右子树只包含大于当前节点的数。

所有左子树和右子树自身必须也是二叉搜索树。

示例 1:

```
输入:
    2
   / \
  1   3
输出: true
```

示例 2:

```
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/validate-binary-search-tree](https://leetcode-cn.com/problems/validate-binary-search-tree)

Link：[https://leetcode.com/problems/validate-binary-search-tree/](https://leetcode.com/problems/validate-binary-search-tree/)


## DFS

根据BST的中序遍历是一个递增序列

无论是前序，中序，后序。都是深度优先搜索

```python
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:

        self.val = float('-inf')
        return self.helper(root)
        
    def helper(self, node: TreeNode):
        
        if node is None:
            return True

        if not self.helper(node.left):
            return False
         
        if self.val < node.val:
            self.val = node.val
        else:
            return False

        if not self.helper(node.right):
            return False
        
        return True
```


## 递归 + 边界验证

由于BST固有的属性，左边都比当前节点值小，右边都比当前节点值大

```python
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.helper(root, float('-inf'), float('inf'))
        
    def helper(self, node: TreeNode, minVal: float, maxVal: float):
        
        if node is None:
            return True
        
        if node.val <= minVal or node.val >= maxVal:
            return False
        
        if not self.helper(node.left, minVal, node.val):
            return False
        
        if not self.helper(node.right, node.val, maxVal):
            return False
        
        return True
```

其他语言兼容

```python
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.helper(root, None, None)
        
    def helper(self, node: TreeNode, minVal: float, maxVal: float):
        
        if node is None:
            return True
        
        if (minVal is not None and  node.val <= minVal) or (maxVal is not None and node.val >= maxVal):
            return False
        
        if not self.helper(node.left, minVal, node.val):
            return False
        
        if not self.helper(node.right, node.val, maxVal):
            return False
        
        return True
```

--End--
