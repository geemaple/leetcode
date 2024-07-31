---
layout: post
index: 89
title: "LeetCode-89.格雷编码(Gray Code)"
categories: Leetcode
tags: Leetcode Backtracking
excerpt: "概率游戏"
---

* content
{:toc}

## 89. 格雷编码

格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。

格雷编码序列必须以 0 开头。

示例 1:

```
输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2

对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。

00 - 0
10 - 2
11 - 3
01 - 1
```

示例 2:

```
输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/gray-code](https://leetcode-cn.com/problems/gray-code)

Link：[https://leetcode.com/problems/gray-code/](https://leetcode.com/problems/gray-code/)


## 回溯法

也算是暴力解法，每次**异或**只变化一个bit位的值, 查看是否可行

```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        
        ans = [0]
        visited = set(ans)
        self.helper(0, n, visited, ans)
        return self.res

    def helper(self, cur: int, n: int, visited: set, ans: List[int]) -> bool:
        
        if len(ans) == 2 ** n:
            self.res = ans.copy()
            return True

        for i in range(n):
            num = cur ^ (1 << i)
            if num in visited:
                continue
                
            visited.add(num)
            if self.helper(num, n, visited, ans + [num]):
                return True
            visited.remove(num)

        return False
```

## 动态规划

O(N)

第N个结果，可以依赖第N - 1个结果

```python
                                         0 + 00 = 000
                                         0 + 01 = 001
                     0 + 0 = 00          0 + 11 = 011
0    ->    0   ->    0 + 1 = 01    ->    0 + 10 = 010

```

在前一个基础上填上一个0

```python
0   ->    1   ->    1 + 1 = 11    ->    1 + 10 = 110
                    1 + 0 = 10          1 + 11 = 111
                                        1 + 01 = 101
                                        1 + 00 = 100
```

在前一个逆序基础上填上一个1,

第0个比较特殊，是个初始值

```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        
        res = [0]
        
        for i in range(n):
            size = len(res)
            for j in range(size)[::-1]:
                val = (1 << i) | res[j]
                res.append(val)
        
        return res
```

## One more thing

二进制转格雷编码公式: G(i) = i ^ (i / 2) = i ^ (i >> 1)

⚠️，按照题目说明，满足条件的格雷码不止一组

### 二进制转格雷编码

例如 100101, 相当于每一位和它前一位异或运算

```
      nums = [1, 0, 0, 1, 0, 1]
           
nums >> 1  = [0, 1, 0, 0, 1, 0, 1]

       xor = [1, 1, 0, 1, 1, 1]

xor[0] = nums[0] ^ 0 = nums[0]
xor[1] = nums[0] ^ nums[1]
xor[2] = nums[1] ^ nums[2]
...
xor[n] = nums[n] ^ nums[n - 1]
```

### 相邻格雷码证明

```
    i = ...?01...1
i + 1 = ...?10...0
```

首先i + 1，会把一个二进制数，最后一个0置成1, 并且这个1后面都是0, 也就是仅?之后是不一样的

```
           i = . . . ? 0 1 . . . 1
      i >> 1 =   . . . ? 0 1 . . . 1
         xor = xxxxxxx   1 0 . . 0
               =======   =========
       i + 1 = . . . ? 1 0 . . . 0
(i + 1) >> 1 =   . . . ? 1 0 . . . 0
         xor = xxxxxxx   1 0 . . 0
```

如上图，划线部分上下是一致的，所以异或的结果也一致，那也就只有**一位**是不同的，满足格雷编码条件

以n=3为例

```
i       000    001    010    011    100    101    110    111       
i >> 1   000    001    010    011    100    101    110    111
                    
        000    001    011    010    110    111    101    100
         0      1      3      2      6      7      5      4  
```

### 代码实现

```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        
        res = []
        for i in range(1 << n):
            res.append(i ^ (i >> 1))
            
        return res
```

--End--
