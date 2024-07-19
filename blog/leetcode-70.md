---
layout: post
index: 70
title: "LeetCode-70.爬楼梯(Climbing Stairs)"
categories: Leetcode
tags: Leetcode DP
excerpt: "消防演习"
---

* content
{:toc}

## 70. 爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

```
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
```

示例 2：

```
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/climbing-stairs](https://leetcode-cn.com/problems/climbing-stairs)

Link：[https://leetcode.com/problems/climbing-stairs/](https://leetcode.com/problems/climbing-stairs/)

## 动态规划

### 递推公式

最后的N，只能从N - 1和N - 2两个地方跳跃过来

```
table[i] = table[i - 1] + table[i - 2]
```

### 初始条件

table[0] = 1

table[1] = 1

### 边界条件

从第二个开始遍历

### 计算方向

从低到高

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        table = [1 for i in range(n + 1)]
        
        for i in range(2, n + 1):
            table[i] = table[i - 1] + table[i - 2]
            
        return table[-1]
```

### 路径压缩

每个新值计算，只依赖前两个，也就是说我们可以把table压缩一下

数组大小 = 2， 取的地方都模2

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        table = [1 for i in range(2)]
        
        for i in range(2, n + 1):
            table[i % 2] = table[(i - 1) % 2] + table[(i - 2) % 2]
            
        return table[n % 2]
```

我们令第一个取值pre, 第二个取值next

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        pre, next = 1, 1
        
        for i in range(2, n + 1):
            pre, next = next, pre + next
            
        return next
```

--End--