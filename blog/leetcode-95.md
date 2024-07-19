---
layout: post
index: 95
title: "LeetCode-95.不同的二叉搜索树 II(Unique Binary Search Trees II)"
categories: Leetcode
tags: Leetcode DP Tree
excerpt: "日常要完"
---

* content
{:toc}

## 95. 不同的二叉搜索树 II

给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

示例：

```
输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

提示：

0 <= n <= 8

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/unique-binary-search-trees-ii](https://leetcode-cn.com/problems/unique-binary-search-trees-ii)

Link：[https://leetcode.com/problems/unique-binary-search-trees-ii/](https://leetcode.com/problems/unique-binary-search-trees-ii/)

## 异类

本来一道题目，找出所有的答案，那肯定是DFS了，结果这道题啪啪打脸

另外，由于生成所有，这道题复杂度仍然很高，即使动态规划通常都是将指数复杂度变成多项式复杂度

```
   2
 /   \
1     3   
```

如上图，对于[2, 1, 3], [2, 3, 1], 会组成同一颗BST

⚠️以下代码，虽然是个❌错误答案❌，但感觉有助于理解题目本身, 它本身的问题是既没办法去重复(即记忆化搜索)，也没办法状态推导

树的深拷贝，虽然有专门的一道题，值得练习一下

```python
from collections import deque
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        
        res = []
        self.helper(n, set(), res, None)
        return res
        
    def helper(self, n : int, visited: set, res: List[TreeNode], root: TreeNode):
        
        if len(visited) == n:
            res.append(root)
            return
        
        for i in range(1, n + 1):
            if i in visited:
                continue
                
            node = TreeNode(i)
            visited.add(i)
            tree = self.copyTree(root)
            tree = self.attachNode(node, tree)
            self.helper(n, visited, res, tree)
            visited.remove(i)
                
    def copyTree(self, root: TreeNode):
        
        if root is None:
            return None
        
        mapping = {}      
        queue = deque([root])
        mapping[root] = TreeNode(root.val)
        
        while len(queue) > 0:
            node = queue.popleft()
            if node.left is not None:
                left = TreeNode(node.left.val)
                mapping[node].left = left
                mapping[node.left] = left
                queue.append(node.left)
                
            if node.right is not None:
                right = TreeNode(node.right.val)
                mapping[node].right = right
                mapping[node.right] = right
                queue.append(node.right)        
        
        return mapping[root]        
                
    def attachNode(self, node: TreeNode, root: TreeNode):
        
        if root is None:
            return node
        
        cur = root
        while cur is not None:
            if node.val > cur.val:
                if cur.right is not None:
                    cur = cur.right
                else:
                    cur.right = node
                    break
                    
            if node.val < cur.val:
                if cur.left is not None:
                    cur = cur.left
                else:
                    cur.left = node
                    break
        
        return root
```

## 递归 + 记忆化搜索

树天然就是递归定义的，所以用递归应该会比较直观简单一些

这里有个非常重要的BST属性，即BST的中序遍历是一个递增序列。

那么, 反过来， 一个递增序列可能是多个BST的结果

⚠️如果用记忆化搜索，子树会共享到多个结果里。 所以，如果不希望这样，重复计算是有必要的

```python
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n <= 0:
            return []
        
        return self.helper(1, n + 1)
    
    @lru_cache(maxsize=None)
    def helper(self, start: int, end: int) -> List[TreeNode]:
        if end - start < 1:
            return [None]
            
        res = []
        for i in range(start, end):
            left_trees = self.helper(start, i)
            right_trees = self.helper(i + 1, end)
            
            for left in left_trees:
                for right in right_trees:
                    root = TreeNode(i)
                    root.left = self.copyTree(left)
                    root.right = self.copyTree(right)
                    
                    res.append(root)
        
        return res   
```

## 动态规划

### 状态定义

dp[n]为[1...N]序列能够组成所有不同的BST, 同时dp[n]节点个数等于N

### 状态转移

```python
                root(j)
                /     \
sub[1 ... j - 1]       sub[j + 1 ... k]
                         
    dp[j - 1]               dp[k - j] # dp[k - j] 每个节点元素值 += offset(j)

例如: [1...7]在root(3)的情况下

                 root(3)
                /      \
           dp[2]       dp[4] # 对于dp[4]中的每个节点 += 3，[1,2,3,4] -> [4,5,6,7]

dp[n] = [root(i) for i in range(1, n + 1)]
```

### 计算方向

从小树到大树/长度由小到大

### 边界条件

```python
dp[0] = [] # 空树
```

### 代码如下

⚠️动态规划相当于记忆化搜索，子树会共享到多个结果里。 所以，如果不希望这样，也需要拷贝左子树

```python
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n <= 0:
            return []
        
        dp = [[] for i in range(n + 1)]
        dp[0].append(None)
        
        for k in range(1, n + 1):
            for j in range(1, k + 1):
                for left in dp[j - 1]:
                    for right in dp[k - j]:
                        root = TreeNode(j)
                        root.left = left # self.copyTree(right, 0)
                        root.right = self.copyTree(right, j)
                    
                        dp[k].append(root)
    
        return dp[-1]


    def copyTree(self, root: TreeNode, offset: int):
        
        if root is None:
            return None
        
        node = TreeNode(root.val + offset)
        node.left = self.copyTree(root.left, offset)
        node.right = self.copyTree(root.right, offset)
        
        return node
```

--End--
