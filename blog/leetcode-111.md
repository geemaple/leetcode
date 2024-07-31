---
layout: post
index: 111
title: "LeetCode-111.二叉树的最小深度(Minimum Depth of Binary Tree)"
categories: Leetcode
tags: Leetcode Tree DFS BFS
excerpt: "钱包大战"
---

* content
{:toc}

## 111. 二叉树的最小深度

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

示例 1：

![图片说明](./images/leetcode-algorithm-111.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：2
```

示例 2：

```
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
```

提示：

```
树中节点数的范围在 [0, 105] 内
-1000 <= Node.val <= 1000
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

Link：[https://leetcode.com/problems/minimum-depth-of-binary-tree/](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

## 深度优先搜索

O(N)

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
                  
        if root.left is None:
            return self.minDepth(root.right) + 1
        
        if root.right is None:
            return self.minDepth(root.left) + 1
        
        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
```

## 宽度优先搜索

O(N)

数一下层数，找到最短的那个节点的层数即可

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        
        if root is None:
            return 0
        
        res = 0
        queue = deque([root])
        
        while len(queue):
            size = len(queue)
            res += 1
    
            for i in range(size):
                node = queue.popleft()

                if node.left is None and node.right is None:
                    return res

                if node.left is not None:
                    queue.append(node.left)

                if node.right is not None:
                    queue.append(node.right)
            
        return res
```

--End--


