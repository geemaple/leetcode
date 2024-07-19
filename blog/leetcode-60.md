---
layout: post
index: 60
title: "LeetCode-60.第k个排列(Permutation Sequence)"
categories: Leetcode
tags: Leetcode Math Backtracking
excerpt: "离司出走"
---

* content
{:toc}

## 60. 第k个排列

给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

```
"123"
"132"
"213"
"231"
"312"
"321"
```

给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。

给定 k 的范围是[1,  n!]。

示例 1:

```
输入: n = 3, k = 3
输出: "213"
```

示例 2:

```
输入: n = 4, k = 9
输出: "2314"
```

来源：力扣（LeetCode）

链接：https://leetcode-cn.com/problems/permutation-sequence/

Link：https://leetcode.com/problems/permutation-sequence/

## DFS

O(K * O(N)), 其中K = N!

依次查找，直到找到第K个组合，然后返回

```python
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        self.res = ''
        self.count = 0
        self.helper(n, k, '', set())
        return self.res
        
    def helper(self, n: int, k: int, ans: str, visited: set) -> None:

        if self.count >= k:
            return
        
        if len(ans) == n:
            self.count += 1
            if self.count == k:
                self.res = ans
            return
        
        for i in range(1, n + 1):
            if i in visited:
                continue

            visited.add(i)
            self.helper(n, k, ans + str(i), visited)
            visited.remove(i)
```

## 数学之美

O(N^2)

**N! = N * (N - 1)!**
 
每组个数都是一致的，如果用k-1除以(N-1)的阶层，那么就知道第一个数落在哪个范围内

k的余额 = index * (n - 1)!

以n=3, k=3为例:

```
以1开头的有2!个:
1 + [2, 3]
1 + [3, 2]

以2开头的有2!个:
2 + [1, 3]
2 + [3, 1]

以3开头的有2!个:
3 + [1, 2]
3 + [2, 1]

index = (k - 1) // (n - 1)! = (3 - 1) // 2! = 1
以此类推，可以逐个确定每一位数字是什么
```

代码如下

```python
import math
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        
        numbers = [str(i + 1) for i in range(n)]
        res = ''
        
        for i in range(n):
            bucket = math.factorial(n - 1 - i)
            
            index = (k - 1) // bucket
            k = k - index * bucket
            
            res += numbers[index]
            numbers.pop(index)
        
        return res
```

计算阶层的时候可以从小到大计算，然后保存在数组中，作为查询表

```python
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
                
        lookup = [1 for i in range(n)]
        for i in range(2, n):
            lookup[i] = lookup[i - 1] * i
        
        numbers = [str(i + 1) for i in range(n)]
        res = ''
        for i in range(n):
            bucket = lookup[n - 1 - i]
            
            index = (k - 1) // bucket
            k = k - index * bucket
            
            res += numbers[index]
            numbers.pop(index)
        
        return res
```

--End--