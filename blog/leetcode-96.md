---
layout: post
index: 96
title: "LeetCode-96.不同的二叉搜索树(Unique Binary Search Trees)"
categories: Leetcode
tags: Leetcode DP Tree
excerpt: "新的起点"
---

* content
{:toc}

## 96. 不同的二叉搜索树

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

```
输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/unique-binary-search-trees/](https://leetcode-cn.com/problems/unique-binary-search-trees/)

Link：[https://leetcode.com/problems/unique-binary-search-trees/](https://leetcode.com/problems/unique-binary-search-trees/)


## 递归 + 记忆化搜索

树天然就是递归定义的，所以用递归应该会比较直观简单一些

这里有个非常重要的BST属性，即BST的中序遍历是一个递增序列。

那么, 反过来， 一个递增序列可能是多个BST的结果，需要依次分析

如果, 结果 = [], 那么就只有**1种可能**, 空树

如果, 结果 = [num], 那么就只有**1种可能**，num为跟节点

如果, 结果 = [num, num + 1], 那么只有**2种可能**, 其中一个数作为跟节点

其他情况，遍历，把一个较长的递增序列, 分别按照跟节点i拆分

例如[1, 2, 3, 4, n], 这里方块里面的数字代表**根节点**

```
[1, 2, 3, 4] = [1], 2, 3, 4
             = 1, [2], 3, 4
             = 1, 2, [3], 4
             = 1, 2, 3, [4]
```

代码如下：

```python
from functools import lru_cache
class Solution:
    def numTrees(self, n: int) -> int:
        return self.helper(1, n + 1)

    @lru_cache(maxsize=None)  
    def helper(self, start: int, end: int) -> int:
        
        if end - start <= 1:
            return 1
        
        if end - start == 2:
            return 2
        
        count = 0
        for i in range(start, end):
            left_count = self.helper(start, i)
            right_count = self.helper(i + 1, end)
            count += left_count * right_count
            
        return count
```

## 动态规划

O(N^2)

### 状态定义

dp[n]为连续N个数的序列(例如:[1...N])能够组成多少不同的BST

无论是[1,2]还是[5,6]只要长度相同，组成的BST个数也相同

### 状态转移

```python
              [i]
            /     \
[1 ... i- 1]       [i + 1 ... n]


dp[n] = dp[0] * dp[n - 1] +  # 第i = 1个数字作为root
        dp[1] * dp[n - 2] +  # 第i = 2个数字作为root
        dp[2] * dp[n - 3] +  # 第i = 3个数字作为root
        ...
        dp[n - 1] * dp[0]    # 第i = n个数字作为root
```

### 计算方向

从小树到大树

### 边界条件

```python
dp[0] = 1 # 空树
dp[1] = 1 # 数字为根
```

#### 代码实现

```python
class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0 for i in range(n + 1)]
        dp[0] = dp[1] = 1
        
        for i in range(2, n + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i - j - 1]
                
        return dp[-1]
```
--End--
