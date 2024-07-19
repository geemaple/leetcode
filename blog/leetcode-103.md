---
layout: post
index: 103
title: "LeetCode-103.二叉树的锯齿形层次遍历(Binary Tree Zigzag Level Order Traversal)"
categories: Leetcode
tags: Leetcode Stack Tree BFS
excerpt: "仰望星空"
---

* content
{:toc}

## 103. 二叉树的锯齿形层次遍历

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：

```
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

Link：[https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

## 广度优先搜索

O(N)

```python
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        
        if root is None:
            return []
        
        res = []
        queue = deque([root])
        reverse = False
        
        while len(queue) > 0:
            size = len(queue)
            level = []
            
            for i in range(size):
                node = queue.popleft()
                
                if node.left is not None:
                    queue.append(node.left)
                    
                if node.right is not None:
                    queue.append(node.right)
                    
                level.append(node.val)
                
            if reverse:
                res.append(reversed(level))
            else:
                res.append(level)
                
            reverse = not reverse
            
        return res
```

省去了反转的过程

```python
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        
        if root is None:
            return []
        
        res = []
        queue = deque([root])
        reverse = False
        
        while len(queue) > 0:
            size = len(queue)
            level = [0 for i in range(size)]
            
            for i in range(size):
                node = queue.popleft()
                
                if node.left is not None:
                    queue.append(node.left)
                    
                if node.right is not None:
                    queue.append(node.right)
                 
                index = size - i - 1 if reverse else i
                level[index] = node.val
                

            res.append(level)
            reverse = not reverse
            
        return res
```

## 深度优先搜索

O(N)

```python
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        self.helper(root, res, 0)
        return res
        
        
    def helper(self, node: TreeNode, res: List[List[int]], depth: int):
        
        if node is None:
            return
        
        if len(res) <= depth:
            res.append([])
            
        level = res[depth]
        if depth % 2 == 0:
            level.append(node.val)
        else:
            level.insert(0, node.val)
            
        self.helper(node.left, res, depth + 1)
        self.helper(node.right, res, depth + 1)
```

--End--


