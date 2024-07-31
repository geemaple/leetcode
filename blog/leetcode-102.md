---
layout: post
index: 102
title: "LeetCode-102.二叉树的层序遍历(Binary Tree Level Order Traversal)"
categories: Leetcode
tags: Leetcode Tree BFS
excerpt: ""
---

* content
{:toc}

## 102. 二叉树的层序遍历

给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

示例：
```

二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/classic/problems/binary-tree-level-order-traversal](https://leetcode-cn.com/classic/problems/binary-tree-level-order-traversal)

Link：[https://leetcode.com/classic/problems/binary-tree-level-order-traversal](https://leetcode.com/classic/problems/binary-tree-level-order-traversal)

## 广度优先搜索

O(N)

在广度优先搜索的基础上，需要记录下当前层级有多少个节点，然后把节点值放入到结果中

```python
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
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
            
        return res
```

## 深度优先搜索

O(N)

需要多传递一个参数，及深度，来记录访问到那一层，才能将对应的节点值添加到对应层级结果中

```python
 class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        self.helper(root, 0, res)
        return res
    
    def helper(self, root: TreeNode, height: int, res: List[List[int]]):
        
        if root is None:
            return
        
        if (len(res) == height):
            res.append([])
            
        res[height].append(root.val)
        
        self.helper(root.left, height + 1, res)
        self.helper(root.right, height + 1, res)
```

--End--


