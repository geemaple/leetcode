---
layout: post
index: 106
title: "LeetCode-106.从中序与后序遍历序列构造二叉树(Construct Binary Tree from Inorder and Postorder Traversal)"
categories: Leetcode
tags: Leetcode Array Tree DFS
excerpt: "黑魔法"
---

* content
{:toc}

## 106. 从中序与后序遍历序列构造二叉树

根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

```
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

Link：[https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

## 递归

基本的思路是用postorder最后一个作为跟节点，然后根据inorder值的位置，来确定左子树+右子树

### 普通递归

```python
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if len(inorder) == 0 or len(postorder) == 0:
            return None

        val = postorder.pop()
        root = TreeNode(val)
        i = inorder.index(val)
        
        root.right = self.buildTree(inorder[i + 1:], postorder)
        root.left = self.buildTree(inorder[:i], postorder)
        
        return root
```

### 优化递归

⚠️注意，由于没有重复元素

1. 先用字典做一个反向索引，加速查找index的速度
2. 使用下标，而不是新建一个数组


```python
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        self.map_inorder = {}

        for i in range(len(inorder)):
            self.map_inorder[inorder[i]] = i

        return self.helper(inorder, postorder, 0, len(inorder) - 1)

    def helper(self, inorder: List[int], postorder: List[int], low: int, high: int) -> TreeNode:
        if low > high:
            return None
        val = postorder.pop()
        root = TreeNode(val)
        i = self.map_inorder[val]

        root.right = self.helper(inorder, postorder, i + 1, high)
        root.left = self.helper(inorder, postorder, low, i - 1)

        return root
```

### 空间优化递归

先创建右子树部分，然后在做左边

```python
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        return self.helper(inorder, postorder, None)
    
    def helper(self, inorder: List[int], postorder: List[int], stop: TreeNode) -> TreeNode:
             
        if len(inorder) == 0 or inorder[-1] == stop:
            return None
        
        val = postorder.pop()
        root = TreeNode(val)
        
        root.right = self.helper(inorder, postorder, val)
        inorder.pop()
        root.left = self.helper(inorder, postorder, stop)
        
        return root
```

--End--


