---
layout: post
index: 124
title: "LeetCode-124.二叉树中的最大路径和(Binary Tree Maximum Path Sum)"
categories: Leetcode
tags: Leetcode Tree DFS Recursion
excerpt: "假如我年少有为"
---

* content
{:toc}

## 124. 二叉树中的最大路径和

路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

示例 1：

![图片说明](./images/leetcode-algorithm-124-1.png) 

```
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
```

示例 2：

![图片说明](./images/leetcode-algorithm-124-2.png) 

```
输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
```
 
提示：

```
树中节点数目范围是 [1, 3 * 104]
-1000 <= Node.val <= 1000
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

Link：[https://leetcode.com/problems/binary-tree-maximum-path-sum/](https://leetcode.com/problems/binary-tree-maximum-path-sum/)


## 深度优先搜索

O(N)

这是一道代码看起来很简单，但是能够想出来，应该是很厉害的

观察1, 对于全是负数节点，最大的负数-1就是结果

```python
              -4
             /  \ 
           -10   -5
           /       \   
         -1        -6
        /  \      /  \
       -2  -3    -7  -9
```

观察2， 对于节点4, 两个子节点都是负数，都需要抛弃

```python
              -4
             /  \ 
            4    6
          /  \     \
        -2   -3     3
                   /  \
                  2    8
```

观察3，对于节点3, 需要返回max(root, root + left, root + right)

```python
               3
             /   \ 
            1     8
          /  \   /  \
         6   7   9   10
```

代码如下:

```python
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        
        self.res = float('-inf')
        self.helper(root)
        return self.res
        
    def helper(self, root: TreeNode) -> int:
        
        if root is None:
            return 0
        
        left = max(0, self.helper(root.left))
        right = max(0, self.helper(root.right))
        
        self.res = max(self.res, left + root.val + right)
        
        return max(left, right) + root.val
```

--End--