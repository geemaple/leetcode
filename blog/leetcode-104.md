---
layout: post
index: 104
title: "LeetCode-104.二叉树的最大深度(Maximum Depth of Binary Tree)"
categories: Leetcode
tags: Leetcode Tree DFS Recursion
excerpt: "一山不容二虎"
---

* content
{:toc}

> 递归其实挺难的，最开始自己很难想到如何直接写，得用一个helper函数才能写下去

## 104. 二叉树的最大深度

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：

```
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/maximum-depth-of-binary-tree](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree)

Link：[https://leetcode.com/problems/maximum-depth-of-binary-tree/](https://leetcode.com/problems/maximum-depth-of-binary-tree/)


## 递归-分治

O(N)

跟节点有两个小弟，询问两个小弟哪边深度大一些，再把最大值加一返回即可

递归的出口是遇到空节点，返回其深度0

```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
            
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
```

## 广度优先搜索

O(N)

我们使用层级遍历，每当遍历新的层级，结果加一

```python
from collections import deque
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        
        if root is None:
            return 0
        
        level = 0
        queue = deque([root])
        while len(queue) > 0:
            size = len(queue)
            for i in range(size):
                node = queue.popleft()
                
                if node.left is not None:
                    queue.append(node.left)
                    
                if node.right is not None:
                    queue.append(node.right)
                    
            level += 1
            
        return level
```

--End--


