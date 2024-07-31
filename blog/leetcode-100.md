---
layout: post
index: 100
title: "LeetCode-100.相同的树(Recover Binary Search Tree)"
categories: Leetcode
tags: Leetcode Tree DFS
excerpt: "伟大的航线"
---

* content
{:toc}

## 100. 相同的树

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

```
输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
```

示例 2:

```
输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
```

示例 3:

```
输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/same-tree](https://leetcode-cn.com/problems/same-tree)

Link：[https://leetcode.com/problems/same-tree/](https://leetcode.com/problems/same-tree/)

## 深度优先搜索

```python
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p is None and q is None:
            return True

        if p is None or q is None:
            return False

        if p.val != q.val:
            return False

        if not self.isSameTree(p.left, q.left):
            return False

        if not self.isSameTree(p.right, q.right):
            return False

        return True
```

简洁版本

```python
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p is not None and q is not None:
            return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

        return p is q
```

--End--

这本应该在去年完成的，但发生了一些糟糕的事情，就像疫情一样突如其来，真切地感受了计划和意外不知道哪一个先到来。不过，希望大难必有后福。

呼吸会变成空气，只是时间的问题，年轻时经过峰回路转的绝望，也许并不是一件坏事情。

**~~3D~~2Y, 新世界见**