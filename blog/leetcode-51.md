---
layout: post
index: 51
title: "LeetCode-51.N 皇后(N-Queens)"
categories: Leetcode
tags: Leetcode Backtracking
excerpt: "1/3"
---

* content
{:toc}

## 51. N 皇后

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

![图片说明](./images/leetcode-algorithm-51.png)

上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。


示例：

```
输入：4
输出：[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
```

提示：

皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/n-queens/](https://leetcode-cn.com/problems/n-queens/)

Link：[https://leetcode.com/problems/n-queens/](https://leetcode.com/problems/n-queens/)

## DFS

O(N!)

国际象棋的皇后，是"米"字形攻击的状态

如果按照水平排递增，就不用考虑同一排会攻击的情况

那么只要考虑(__|__ __\\__, __/__)三种情况, 其中垂直是非常好判断的，只要不在同一列就行

'\\'方向, **x坐标 - y坐标**的值是一样的

```
  x - 1 |       |
  y - 1 |       |       
------------------------
        |   x   |
        |   y   |
------------------------
        |       | x + 1
        |       | y + 1
```

'/'方向, **x坐标 + y坐标**的值是一样的

```
        |       | x - 1
        |       | y + 1     
------------------------
        |   x   |
        |   y   |
------------------------
  x + 1 |       |
  y - 1 |       |
```

代码如下:

```python
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        res = []
        board = [['.' for i in range(n)] for j in range(n)]     
        pos = set() # ⬆️⬇️
        diffs = set() # ↖️↘️
        sums = set() # ↙️↗️
        self.helper(board, res, pos, diffs, sums)
        
        return res
        
    def helper(self, board: List[List[int]], res: List[List[str]], pos: List[int], diffs:List[int], sums:List[int]) -> None:
        
        if len(pos) == len(board):
            res.append([''.join(board[i]) for i in range(len(pos))])
            return
        
        row = len(pos)
        for col in range(len(board)):   
            if col in pos or row - col in diffs or row + col in sums:
                continue
            
            board[row][col] = 'Q'
            pos.add(col)
            diffs.add(row - col)
            sums.add(row + col)
            
            self.helper(board, res, pos, diffs, sums)
            
            sums.remove(row + col)
            diffs.remove(row - col)
            pos.remove(col)
            
            board[row][col] = '.'
```

精简代码如下：

**pos[row] = col**代表第(row, col)放置了一个皇后

```python
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        res = []    
        self.helper(res, n, [], [], [])
        return res
        
    def helper(self, res: List[List[str]], n: int, pos: List[int], diffs:List[int], sums:List[int]) -> None:
        
        if len(pos) == n:
            res.append(['.' * i + 'Q' + '.' * (n - i - 1)  for i in pos])
            return
        
        row = len(pos) 
        for col in range(n):   
            if col in pos or row - col in diffs or row + col in sums:
                continue
            
            self.helper(res, n, pos + [col], diffs + [row - col], sums + [row + col])
```

--End--