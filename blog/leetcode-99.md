---
layout: post
index: 99
title: "LeetCode-99.恢复二叉搜索树(Recover Binary Search Tree)"
categories: Leetcode
tags: Leetcode Tree DFS
excerpt: "选择"
---

* content
{:toc}

## 99. 恢复二叉搜索树

给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。

进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？


示例 1：

![图片说明](./images/leetcode-algorithm-99-1.jpg)

```
输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
```

示例 2：

![图片说明](./images/leetcode-algorithm-99-2.jpg)

```
输入：root = [3,1,4,null,null,2]
输出：[2,1,4,null,null,3]
解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
```

提示：

```
树上节点的数目在范围 [2, 1000] 内
-231 <= Node.val <= 231 - 1
```


来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/recover-binary-search-tree/](https://leetcode-cn.com/problems/recover-binary-search-tree/)

Link：[https://leetcode.com/problems/recover-binary-search-tree/](https://leetcode.com/problems/recover-binary-search-tree/)

## 深度优先搜索

O(N)

BST的中序遍历，是一个递增序列

我们需要找到，不满足递增的一组，把第一个记录下来first

对于任意不满足的，始终把second记录下来

交换两个记录节点的值

问题是，无论递归还是非递归都用的O(N)空间复杂度

### 递归代码

```python
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.pre = None
        self.firstNode = None
        self.secondNode = None
        self.helper(root)
        self.firstNode.val, self.secondNode.val = self.secondNode.val, self.firstNode.val

    def helper(self, node: TreeNode):
        if node is None:
            return

        self.helper(node.left)
        
        # do something
        if self.pre is not None and self.pre.val > node.val:

            if self.firstNode is None:
                self.firstNode = self.pre
      
            self.secondNode = node
        self.pre = node
        # do something
        self.helper(node.right)
```

### 非递归代码

```python
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        pre = None
        firstNode = None
        secondNode = None
        stack = []

        cur = root
        while cur is not None or len(stack) > 0:
            while cur is not None:
                stack.append(cur)
                cur = cur.left

            node = stack.pop()

            # do something
            if pre is not None and pre.val > node.val:
                if firstNode is None:
                    firstNode = pre
        
                secondNode = node
            pre = node
            # do something

            cur = node.right
            
        firstNode.val, secondNode.val = secondNode.val, firstNode.val
```

## Morris Traversal

那么使用O(1)空间有没有可能呢？还真有，有个叫morris traversal, 恢复的思路一致

具体遍历，后序会单独写篇文章

```python
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        pre = None
        firstNode = None
        secondNode = None

        cur = root
        while cur:
            if cur.left:
                tmp = cur.left
                while tmp.right is not None and tmp.right != cur:
                    tmp = tmp.right
                if tmp.right is None:
                    tmp.right, cur = cur, cur.left
                    continue
                    
                tmp.right = None
        
            # do something
            if pre is not None and pre.val > cur.val:
                if firstNode is None:
                    firstNode = pre

                secondNode = cur
            pre = cur
            # do something
            cur = cur.right
            
        firstNode.val, secondNode.val = secondNode.val, firstNode.val
```

--End--


