---
layout: post
index: 107
title: "LeetCode-107.二叉树的层序遍历 II(Binary Tree Level Order Traversal II)"
categories: Leetcode
tags: Leetcode Tree BFS
excerpt: "知乎帮拼多多砍了一刀"
---

* content
{:toc}

## 107. 二叉树的层序遍历 II

给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：

```
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层序遍历为：

[
  [15,7],
  [9,20],
  [3]
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii)

Link：[https://leetcode.com/problems/binary-tree-level-order-traversal-ii/](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)


## 宽度优先搜索

按照层级遍历，最后把结果反过来就行了

O(N)

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
            
        res = []
        queue = deque([root])
        
        while len(queue) > 0:
            size = len(queue)
            level = []
            for i in range(size):
                node = queue.popleft()
                level.append(node.val)
                if node.left is not None:
                    queue.append(node.left)
                    
                if node.right is not None:
                    queue.append(node.right)
        
            res.append(level)
        
        return res[::-1]
```

## 深度优先搜索

深度优先搜索，可以记录当前层级，DFS其实不推荐的，因为毕竟能用BFS的就不用DFS。**DFS有递归溢出的风险, 非递归又不是特别好写**

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:

        res = []
        self.helper(root, 0, res)
        return res[::-1]
        
        
    def helper(self, node: TreeNode, level:int, res: List[List[int]]):
        
        if node is None:
            return
        
        if level == len(res):
            res.append([])
            
        res[level].append(node.val)
        
        self.helper(node.left, level + 1, res)
        self.helper(node.right, level + 1, res)
```

--End--


