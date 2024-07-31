---
layout: post
index: 113
title: "LeetCode-113.路径总和 II(Path Sum II)"
categories: Leetcode
tags: Leetcode Tree DFS
excerpt: "刻在你心底的名字"
---

* content
{:toc}

## 113. 路径总和 II

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例1: 

![图片说明](./images/leetcode-algorithm-113-1.jpg)

```
      
输入: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出: [[5,4,11,2],[5,8,4,5]]
```

示例2: 

![图片说明](./images/leetcode-algorithm-113-2.jpg)

```
输入: root = [1,2,3], targetSum = 5
输出: []
```

示例3: 

```
输入: root = [1,2], targetSum = 0
输出: []
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/path-sum/](https://leetcode-cn.com/problems/path-sum/)

Link：[https://leetcode.com/problems/path-sum/](https://leetcode.com/problems/path-sum/)

## 深度优先搜索

O(N)

要找到所有的答案, 那么基本上都是DFS无疑了。

```python
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        
        res = []
        self.helper(root, sum, [], res)
        return res
        
        
    def helper(self, node: TreeNode, target: int, ans: List[int], res: List[List[int]]):
        
        if node is None:
            return
        
        if node.left is None and node.right is None and target == node.val:
            res.append(ans + [node.val])
            
        self.helper(node.left, target - node.val, ans + [node.val], res)
        self.helper(node.right, target - node.val, ans + [node.val], res)
```

标准回溯

```python
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        
        res = []
        self.helper(root, sum, [], res)
        return res
        
        
    def helper(self, node: TreeNode, target: int, ans: List[int], res: List[List[int]]):
        
        if node is None:
            return
        
        ans.append(node.val)

        if node.left is None and node.right is None and target == node.val:
            res.append(ans.copy())
            
        self.helper(node.left, target - node.val, ans, res)
        self.helper(node.right, target - node.val, ans, res)
        ans.pop()
```

简洁代码

```python
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        
        if root is None:
            return []
        
        if root.left is None and root.right is None and sum == root.val:
            return [[root.val]]
        
        tmp = self.pathSum(root.left, sum - root.val) + self.pathSum(root.right, sum - root.val)
        return [[root.val] + sub for sub in tmp]
```

## 宽度优先搜索

O(N)

把累加结果放在每一层的节点上，然后判断叶子节的总和是否等于目标值

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
          
        if root is None:
            return []
            
        res = []
        queue = deque([(root, root.val, [root.val])])
        
        while len(queue) > 0:
            node, val, ans = queue.popleft()
            
            if node.left is None and node.right is None and val == targetSum:
                res.append(ans)
                
            if node.left is not None:
                queue.append((node.left, val + node.left.val, ans + [node.left.val]))
                
            if node.right is not None:
                queue.append((node.right, val + node.right.val, ans + [node.right.val]))
            
        return res
```

--End--


