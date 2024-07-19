---
layout: post
index: 105
title: "LeetCode-105.从前序与中序遍历序列构造二叉树(Construct Binary Tree from Preorder and Inorder Traversal)"
categories: Leetcode
tags: Leetcode Array Tree DFS
excerpt: ""
---

* content
{:toc}

## 105. 从前序与中序遍历序列构造二叉树

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

```
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal)

Link：[https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

## 递归

O(N^2), 如果这个树是一个链表的话, N个节点，每个节点创建O(N)

基本的思路是用postorder最后一个作为跟节点，然后根据inorder值的位置，来确定左子树+右子树

### 普通递归

```python
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder) == 0 or len(inorder) == 0:
            return None
        
        val = preorder.pop(0)
        root = TreeNode(val)
        i = inorder.index(val)
   
        root.left = self.buildTree(preorder, inorder[:i])
        root.right = self.buildTree(preorder, inorder[i + 1:])
        
        return root
```

### 时间优化递归

O(N)

⚠️注意，由于没有重复元素

1. 先用字典做一个反向索引，加速查找index的速度
2. 使用下标，而不是新建一个数组
3. 反转preorder, 每次pop最后一个

```python
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        self.map_inorder = {}

        for i in range(len(inorder)):
            self.map_inorder[inorder[i]] = i

        preorder.reverse()
        return self.helper(preorder, inorder, 0, len(inorder) - 1)

    def helper(self, preorder: List[int], inorder: List[int], low: int, high: int) -> TreeNode:
        if low > high:
            return None

        val = preorder.pop()
        root = TreeNode(val)
        i = self.map_inorder[val]

        root.left = self.helper(preorder, inorder, low, i - 1)
        root.right = self.helper(preorder, inorder, i + 1, high)
        
        return root
```

### 空间优化递归

先创建左子树部分，然后在做右边

```python
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        preorder.reverse()
        inorder.reverse()
        
        return self.helper(preorder, inorder, None)
    
    
    def helper(self, preorder: List[int], inorder: List[int], stop: TreeNode) -> TreeNode:
             
        if len(inorder) == 0 or inorder[-1] == stop:
            return None
        
        val = preorder.pop()
        root = TreeNode(val)
        root.left = self.helper(preorder, inorder, val)
        inorder.pop()
        root.right = self.helper(preorder, inorder, stop)

        return root
```

--End--


