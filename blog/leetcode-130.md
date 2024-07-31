---
layout: post
index: 130
title: "LeetCode-130.被围绕的区域(Surrounded Regions)"
categories: Leetcode
tags: Leetcode DFS BFS DisjointSet
excerpt: "KLV Changed my life"
---

* content
{:toc}

## 130. 被围绕的区域

给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 
示例 1：

![图片说明](./images/leetcode-algorithm-130.png)

```
输入：board = [["X","X","X","X"],
              ["X","O","O","X"],
              ["X","X","O","X"],
              ["X","O","X","X"]]
输出：[["X","X","X","X"],
      ["X","X","X","X"],
      ["X","X","X","X"],
      ["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
```

示例 2：

输入：board = [["X"]]
输出：[["X"]]
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 为 'X' 或 'O'

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/surrounded-regions](https://leetcode-cn.com/problems/surrounded-regions)

Link：[https://leetcode.com/problems/surrounded-regions](https://leetcode.com/problems/surrounded-regions)

## 宽度优先搜索

O(N)

从任意一个'0'出发，BFS搜索，如果被包围，就设置翻转

```python
from collections import deque
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        visited = set()
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 'X' or (i, j) in visited:
                    continue

                self.helper(i, j, board, visited)

    def helper(self, i : int, j : int, board: List[List[str]], visited: set):
        
        directions = [-1, 0, 1, 0, -1] # x, y合一方向数组
        start = (i, j)
        queue = deque([start])
        visited.add(start)
        captured = True
        booty = [start]
        
        
        while len(queue) > 0:
            x, y = queue.popleft()
            
            for k in range(4):
                neighbor = (x + directions[k], y + directions[k + 1])
                if 0 <= neighbor[0] < len(board) and 0 <= neighbor[1] < len(board[i]):
                    if neighbor not in visited:
                        visited.add(neighbor)
                        if board[neighbor[0]][neighbor[1]] == 'O':
                            queue.append(neighbor)
                            booty.append(neighbor)
                else:
                    captured = False

        if captured:
            for x, y in booty:
                board[x][y] = 'X'
```

从四个边开始BFS，记录不能翻转的，然后统一处理

```python
from collections import deque
class Solution:
    def solve(self, board: List[List[str]]) -> None:       
        """
        Do not return anything, modify board in-place instead.
        """
        visited = set()

        for i in range(len(board)):
            self.bfs(board, visited, i, 0) # 第一列
            self.bfs(board, visited, i, len(board[i]) - 1) # 最后一列

        for j in range(1, len(board[0]) - 1):
            self.bfs(board, visited, 0, j) # 第一行
            self.bfs(board, visited, len(board) - 1, j) # 最后一行

        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 'O' and (i, j) not in visited:
                    board[i][j] = 'X'

    def bfs(self, board, visited, i, j):

        if board[i][j] == 'X' or (i, j) in visited:
            return

        directions = [-1, 0, 1, 0, -1]
        queue = deque([(i, j)])
        visited.add((i, j))

        while(len(queue) > 0):
            x, y = queue.popleft()
            
            for k in range(4):
                neighbor = (x + directions[k], y + directions[k + 1])

                if 0 <= neighbor[0] < len(board) and 0 <= neighbor[1] < len(board[i]) and neighbor not in visited and board[neighbor[0]][neighbor[1]] == 'O':
                    visited.add(neighbor)
                    queue.append(neighbor)
```

## 深度优先搜索

也可以用深度优先搜索，只是广度优先比较简单

## 并查集

定义一个超级节点代表'自由'，把所有从边遍历的节点'0'，都与这个自由节点相连， 最后没有与'自由'节点相连的同一翻转成'X'

--End--