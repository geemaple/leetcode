---
layout: post
index: 108
title: "LeetCode-108.将有序数组转换为二叉搜索树(Convert Sorted Array to Binary Search Tree)"
categories: Leetcode
tags: Leetcode Tree DFS
excerpt: "人的一生能够选择的事情很少，所有的奇迹都是自己创造的"
---

* content
{:toc}

## 108. 将有序数组转换为二叉搜索树

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

```
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)

Link：[https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

## 递归

O(N)

BST的中序遍历的结果是一个不下降的序列。找到中间节点，左边小于的都是左子树，右边大于的都是右子树

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        left = 0
        right = len(nums) - 1
        
        if left > right:
            return None
            
        mid = (right + left) // 2
        val = nums[mid]
        root = TreeNode(val)
        
        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid + 1:])

        return root
```

另一种

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        left = 0
        right = len(nums) - 1
        return self.helper(nums, left, right)
        
        
    def helper(self, nums: List[int], left: int, right: int):
        if left > right:
            return None
            
        mid = (right + left) // 2
        val = nums[mid]
        root = TreeNode(val)
        
        root.left = self.helper(nums, left, mid - 1)
        root.right = self.helper(nums, mid + 1, right)

        return root
```

## 非递归版本

当你把上面的运算过程画成一个递归树，剩下的就比较好办了, 后执行的右子树先入栈

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if len(nums) == 0:
            return None
        
        root = TreeNode(0)
        stack = [(root, 0, len(nums) - 1)]
 
        while len(stack) > 0:
            node, left, right = stack.pop()
            mid = (right + left) // 2    
            node.val = nums[mid]
            if right >= mid + 1:
                node.right = TreeNode(0)
                stack.append((node.right, mid + 1, right))

            if left <= mid - 1:
                node.left = TreeNode(0)
                stack.append((node.left, left, mid - 1))

        return root
```

--End--


