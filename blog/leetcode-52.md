---
layout: post
index: 52
title: "LeetCode-52.N皇后 II(N-Queens II)"
categories: Leetcode
tags: Leetcode Backtracking
excerpt: "不退缩"
---

* content
{:toc}

> 这道题，其实和上一题差不多，上一题答案都知道了，个数也就是顺带的事情

## 52. N皇后 II

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

![图片说明](./images/leetcode-algorithm-51.png)

上图为 8 皇后问题的一种解法。

给定一个整数 n，返回 n 皇后不同的解决方案的数量。

示例:

```
输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
```

提示：

皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或 N-1 步，可进可退。（引用自 百度百科 - 皇后 ）


来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/n-queens-ii/](https://leetcode-cn.com/problems/n-queens-ii/)

Link：[https://leetcode.com/problems/n-queens-ii/](https://leetcode.com/problems/n-queens-ii/)

## DFS

O(N!)

### 回溯

```python
class Solution:
    def totalNQueens(self, n: int) -> int:
        self.res = 0
        self.helper(n, [], [], [])
        return self.res
        
    def helper(self, n: int, pos: List[int], diffs:List[int], sums:List[int]) -> None:
        
        if len(pos) == n:
            self.res += 1
            return
        
        row = len(pos) 
        for col in range(n):   
            if col in pos or row - col in diffs or row + col in sums:
                continue
            
            self.helper(n, pos + [col], diffs + [row - col], sums + [row + col])
```

### 位运算

该算法时间复杂度很高，所以当n超过32时，也不知道要算多久才能算出来

实践证明，32位数字足够用了

```python
class Solution:
    def totalNQueens(self, n: int) -> int:
        self.res = 0
        self.helper(n, 0, 0, 0, 0)
        return self.res
        
    def helper(self, n: int, row: int, cols: int, diffs:int, sums:int) -> None:
        
        if row == n:
            self.res += 1
            return
        
        # (cols | diffs | sums) 三个方向取或，0就是没有占用的位置
        # ～取反，1就是没有占用的位置, 但是32位的头部0也会变成1 
        # 所以, ((1 << n) - 1)只有后这些位置是有意义的。
        candidate = ~(cols | diffs | sums) & ((1 << n) - 1) 
        
        while candidate > 0:
            
            # 得到末尾的1(负数的表示正数取反+1), 获得放置位置
            p = candidate & -candidate 
            
            # 往下递归时，列垂直向下, ↖️↘️往右移一位, ↙️↗️往左移一位
            self.helper(n, row + 1, cols | p, (diffs | p) >> 1, (sums | p) << 1)
            
            # 消掉末尾的1
            candidate &= candidate - 1 
```

耗时测试如下：

```python
from typing import List
from collections import Counter
from time import time

[答案代码块]

s = Solution()
for i in range(100):
    start = time()
    res = s.totalNQueens(i)
    print('n=%s 耗时:%s, 结果%s' % (i, time() - start, res))

[console输出]
n=0 耗时:2.1457672119140625e-06, 结果1
n=1 耗时:5.0067901611328125e-06, 结果1
n=2 耗时:4.76837158203125e-06, 结果0
n=3 耗时:6.9141387939453125e-06, 结果0
n=4 耗时:1.9073486328125e-05, 结果2
n=5 耗时:5.316734313964844e-05, 结果10
n=6 耗时:0.000179290771484375, 结果4
n=7 耗时:0.0005168914794921875, 结果40
n=8 耗时:0.0018699169158935547, 结果92
n=9 耗时:0.008151054382324219, 结果352
n=10 耗时:0.03539919853210449, 结果724
n=11 耗时:0.15874195098876953, 结果2680
n=12 耗时:0.8340210914611816, 结果14200
n=13 耗时:4.572168827056885, 结果73712
n=14 耗时:26.882348775863647, 结果365596
n=15 耗时:185.4061300754547, 结果2279184
n=16 耗时:1221.420109987259, 结果14772512
...
```

--End--