---
layout: post
index: 338
title: "LeetCode-338.比特位计数(Counting Bits)"
categories: Leetcode
tags: Leetcode DP BitManipulation
excerpt: ""
---

* content
{:toc}

## 338. 比特位计数

给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

```
输入: 2
输出: [0,1,1]
```

示例 2:

```
输入: 5
输出: [0,1,1,2,1,2]
```

进阶:

```
给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
要求算法的空间复杂度为O(n)。
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/counting-bits](https://leetcode-cn.com/problems/counting-bits)

Link：[https://leetcode.com/problems/counting-bits/](https://leetcode.com/problems/counting-bits/)

## 比特位

O(N * sizeof(int))

```python
class Solution:
    def countBits(self, num: int) -> List[int]:
        res = []
        
        for i in range(num + 1):
            tmp = i
            count = 0
            while tmp > 0:
                if tmp & 1 == 1:
                    count += 1
                
                tmp = tmp >> 1
                    
            res.append(count)
            
        return res
```

## 动态规划

O(N)

DP是将复杂的问题，递归拆解成最优子问题，避免重复计算的编程方法

1. 最优子问题
2. 重复计算

这个动态规划，比较贴近直觉, 把一个数字最后一位去掉，那么去掉之后的数一定比当前小，并且已经计算过了

### 递推公式

```python
dp[i] = '最后一位是否为1' + dp[i >> 1]

#或者, i & (i - 1)去掉数字最后一个1, 然后把这个1加上
dp[i] = dp[i & (i - 1)] + 1
```

### 计算方向

从0到num

### 边界条件

注意0，没有更小的数字，所以不能递推

### 初始条件

dp[0] = 0

```python
class Solution:
    def countBits(self, num: int) -> List[int]:
        
        dp = [0 for i in range(num + 1)]
        
        for i in range(1, num + 1):
            dp[i] = (i & 1) + dp[i >> 1]
            
        return dp
```

还有一种就是，打掉最后一个1, 但要把打掉的这个1加上

```python
class Solution:
    def countBits(self, num: int) -> List[int]:
        
        dp = [0 for i in range(num + 1)]
        
        for i in range(1, num + 1):
            dp[i] = dp[i & (i - 1)] + 1
            
        return dp
```


--End--


