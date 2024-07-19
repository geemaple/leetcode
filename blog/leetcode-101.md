---
layout: post
index: 101
title: "LeetCode-101.对称二叉树(Symmetric Tree)"
categories: Leetcode
tags: Leetcode Tree DFS BFS
excerpt: "巅峰之上"
---

* content
{:toc}

## 101. 对称二叉树

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

```
    1
   / \
  2   2
   \   \
   3    3
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/symmetric-tree](https://leetcode-cn.com/problems/symmetric-tree)

Link：[https://leetcode.com/problems/symmetric-tree/](https://leetcode.com/problems/symmetric-tree/)

## 递归

O(N)

```python
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        
        return self.helper(root.left, root.right)
         
    def helper(self, left: TreeNode, right: TreeNode) -> bool:
        
        if left is None and right is None:
            return True
        
        if left is None or right is None:
            return False
        
        if left.val != right.val:
            return False
        
        if not self.helper(left.left, right.right):
            return False
        
        if not self.helper(left.right, right.left):
            return False
        
        return True
```

简洁版本

```python
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        
        return self.helper(root.left, root.right)
        
    def helper(self, left: TreeNode, right: TreeNode) -> bool:
        
        if left is not None and right is not None:
            return left.val == right.val and self.helper(left.left, right.right) and self.helper(left.right, right.left)
        
        return left is right
```

非递归版本

```python
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        
        stack = []
        stack.append(root.left)
        stack.append(root.right)
        
        while len(stack) > 0:
            left = stack.pop()
            right = stack.pop()
            
            if left is None and right is None:
                continue
                
            if left is None or right is None or left.val != right.val:
                return False
            
            stack.append(left.left)
            stack.append(right.right)
            stack.append(left.right)
            stack.append(right.left)
            
        return True
```

## 广度优先搜索

O(N)

一层层遍历，判断每一层是否是个回文

```python
from collections import deque
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        queue = deque()
        queue.append(root)
        
        while len(queue) > 0:
            size = len(queue)
            for i in range(size):
                node = queue.popleft()
                if node is not None:
                    queue.append(node.left)
                    queue.append(node.right)
                    
            if not self.levelIsSymmetric(queue):
                return False
            
        return True
                    
            
    def levelIsSymmetric(self, queue:deque) -> bool:
        left = 0
        right = len(queue) - 1
        
        while left <= right:
            if queue[left] is not None and queue[right] is not None:
                if queue[left].val != queue[right].val:
                    return False
            else:
                if not queue[left] is queue[right]:
                    return False
            
            left += 1
            right -= 1
            
        return True
```

--End--


