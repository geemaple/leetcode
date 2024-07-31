---
layout: post
index: 110
title: "LeetCode-110.平衡二叉树(Balanced Binary Tree)"
categories: Leetcode
tags: Leetcode Tree DFS Recursion
excerpt: "愿你能有选择"
---

* content
{:toc}

## 110. 平衡二叉树

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

示例 1：

![图片说明](./images/leetcode-algorithm-110-1.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：true
```

示例 2：

![图片说明](./images/leetcode-algorithm-110-2.jpg)

```
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
```

示例 3：

```
输入：root = []
输出：true
```

提示：

```
树中的节点数在范围 [0, 5000] 内
-104 <= Node.val <= 104
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/balanced-binary-tree/](https://leetcode-cn.com/problems/balanced-binary-tree/)

Link：[https://leetcode.com/problems/balanced-binary-tree/](https://leetcode.com/problems/balanced-binary-tree/)

## 递归

O(N)

应该先判断左右子树是否是平衡的，然后还要记录左右子树的高度，这样才能判断当前节点是否平衡

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        
        return self.helper(root)[0]
        
    def helper(self, node:TreeNode) -> Tuple[bool, int]:
        
        if node is None:
            return (True, 0)
        
        left_balanced, left_height = self.helper(node.left)
        right_balanced, right_height = self.helper(node.right)
        height = max(left_height, right_height) + 1
        
        if left_balanced and right_balanced and abs(left_height - right_height) < 2:
            return (True, height)
        else:
            return (False, height)
```

另一种, 使用负数-1代表不平衡, 整数代表平衡

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        
        return self.helper(root) != -1
        
    def helper(self, node:TreeNode) -> int:
        
        if node is None:
            return 0
        
        left_height = self.helper(node.left)
        right_height = self.helper(node.right)
        
        if left_height != -1 and right_height != -1 and abs(left_height - right_height) < 2:
            return max(left_height, right_height) + 1
        else:
            return -1
```

--End--


