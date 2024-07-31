---
layout: post
index: 114
title: "LeetCode-114.二叉树展开为链表(Flatten Binary Tree to Linked List)"
categories: Leetcode
tags: Leetcode Tree DFS
excerpt: "飘向北方"
---

* content
{:toc}

## 114. 二叉树展开为链表

给定一个二叉树，原地将它展开为一个单链表。

返回的链表应该复用原来的TreeNode, TreeNode的右指针指向下一个节点，左指针为**Null**

链表的顺序，应该和树的**前序遍历**结果一致

示例1: 

![图片说明](./images/leetcode-algorithm-114.jpg)

```
输入: root = [1,2,5,3,4,null,6]
输出: [1,null,2,null,3,null,4,null,5,null,6]
```

示例2:

```
输入: root = []
输出: []
```

示例3:

```
输入: root = [0]
输出: [0]
```

树的节点范围在[0, 2000]之间, -100 <= Node.val <= 100

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list)

Link：[https://leetcode.com/problems/flatten-binary-tree-to-linked-list/](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

## 深度优先搜索

O(N)

### 递归(前序遍历)

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def __init__(self):
        self.pre = None

    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        if root is None:
            return

        if self.pre is not None:
            self.pre.right = root

        left = root.left
        right = root.right

        self.pre = root
        root.left = None
        
        self.flatten(left)
        self.flatten(right)
```

### 递归(反前序遍历)

O(N)

正常的前序遍历是, **根-左-右**, 反前序是**右-左-根**

这个反逻辑，不是很直观，可以拿例子，自己画一下

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def __init__(self):
        self.next = None

    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None:
             return None
        
        self.flatten(root.right)
        self.flatten(root.left)
        
        root.left = None
        root.right = self.next
        self.next = root
```

### 非递归

O(N)

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None:
             return None
            
        stack = [root]
        pre = None
        
        while len(stack) > 0:
            node = stack.pop()
            
            if pre is not None:
                pre.right = node
                pre.left = None
                
            pre = node
            
            if node.right is not None:
                stack.append(node.right)
                
            if node.left is not None:
                stack.append(node.left)
```

## One More Thing

> 能够只用O(1)的空间复杂度来完成么？

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        
        cur = root
        
        while cur is not None:
            
            if cur.left is not None:
                
                # 找到右子树的前继节点，pre.right指向右子树
                pre = cur.left
                while pre.right is not None:
                    pre = pre.right
                
                pre.right = cur.right
                
                # 把左子树移动到右子树的位置(右子树已经被左子树的一个节点指向了)
                cur.right = cur.left
                cur.left = None
        
            cur = cur.right  
```

算法图示, right子树下移, pre指向right, 当前节点两个指针左旋

```python

   '1' <-cur                 '1'                None  - 1
   / \                       / \                        / 
  2   5          =>         2   5 <-right    =>       '2'  <-cur
 / \   \                   / \   \                    / \
3   4   6                 3   4   6                  3   4 
                              ^                           \ 
                             pre                           5 <-right
                                                            \
                                                             6     


    1                      1                         1               
     \                      \                         \ 
     '2'  <- cur            '2'  <-cur        None  - '2'  <-cur
     / \                    / \                       /
    3   4        =>        3   4  <-right   =>       3  
         \                 ^    \                     \
          5               pre    5                     4  <-right
           \                      \                     \
            6                      6                     5
                                                          \
                                                           6
```

--End--


