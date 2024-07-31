---
layout: post
index: 547
title: "LeetCode-547.省份数量(Number of Provinces)"
categories: Leetcode
tags: Leetcode DFS DisjointSet
excerpt: "朋友圈"
---

* content
{:toc}

> 这道题原来叫朋友圈，不知道为啥后来改名字了

## 547. 省份数量

有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。

示例 1：

![图片说明](./images/leetcode-algorithm-547-1.jpg)

```
输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
输出：2
```

示例 2：

![图片说明](./images/leetcode-algorithm-547-2.jpg)

```
输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
输出：3
```

提示：

```
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] 为 1 或 0
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/number-of-provinces/](https://leetcode-cn.com/problems/number-of-provinces/)

Link：[https://leetcode.com/problems/number-of-provinces/](https://leetcode.com/problems/number-of-provinces/)


## 搜索

O(MN)

从一个点出发，搜索遍所有的好友关系, 那这些人就是同一个朋友圈的。这道题朋友圈 = 省份

### 宽度优先搜索

```python
from collections import deque
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        
        res = 0
        visited = set()
        
        for i in range(len(isConnected)):
            if i not in visited:
                res += 1
                self.bfs(isConnected, i, visited)
        
        return res
        
        
    def bfs(self, isConnected: List[List[int]], i: int, visited: set):
            
        visited.add(i)
        queue = deque([i])
        
        while len(queue) > 0:
            index = queue.popleft()
            
            for neighbor in range(len(isConnected[index])):
                if isConnected[index][neighbor] == 1 and neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
```

### 深度优先搜索

```python
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        
        res = 0
        visited = set()
        
        for i in range(len(isConnected)):
            if i not in visited:
                res += 1
                self.dfs(isConnected, i, visited)
        
        return res
        
        
    def dfs(self, isConnected: List[List[int]], i: int, visited: set):
           
        visited.add(i)
        for j in range(len(isConnected[i])):
            if isConnected[i][j] == 1 and j not in visited:
                self.dfs(isConnected, j, visited)
```

## 并查集

并查集中有N个孤立节点, 每链接两个**孤立**节点, 剩余的个数就是**N -= 1**

```python
class UnionFind:
    def __init__(self, num: int):
        self.count = num
        self.ancestor = [i for i in range(num)]
        
    def find(self, node: int) -> int:
        
        path = []
        while self.ancestor[node] != node:
            path.append(node)
            node = self.ancestor[node]
            
        for child in path:
            self.ancestor[child] = node
            
        return node
    
    def union(self, a: int, b: int):
        
        if self.find(a) != self.find(b):
            self.count -= 1
            self.ancestor[self.find(a)] = self.find(b)
        

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        
        res = 0
        num = len(isConnected)
        visited = set()
        union_find = UnionFind(num)
        
        for i in range(num):
            for j in range(i + 1, num):
                if isConnected[i][j] == 1:
                    union_find.union(i, j)

        return union_find.count
```

--End--