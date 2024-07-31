---
layout: post
index: 1742
title: "LeetCode-1742.盒子中小球的最大数量(Maximum Number of Balls in a Box)"
categories: Leetcode
tags: Leetcode Array
excerpt: "努力决定下限，运气决定上限"
---

* content
{:toc}

## 1742. 盒子中小球的最大数量

你在一家生产小球的玩具厂工作，有 n 个小球，编号从 lowLimit 开始，到 highLimit 结束（包括 lowLimit 和 highLimit ，即 n == highLimit - lowLimit + 1）。另有无限数量的盒子，编号从 1 到 infinity 。

你的工作是将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。例如，编号 321 的小球应当放入编号 3 + 2 + 1 = 6 的盒子，而编号 10 的小球应当放入编号 1 + 0 = 1 的盒子。

给你两个整数 lowLimit 和 highLimit ，返回放有最多小球的盒子中的小球数量。如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量。

示例 1：

```
输入：lowLimit = 1, highLimit = 10
输出：2
解释：
盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
小球数量：2 1 1 1 1 1 1 1 1 0  0  ...
编号 1 的盒子放有最多小球，小球数量为 2 。
```

示例 2：

```
输入：lowLimit = 5, highLimit = 15
输出：2
解释：
盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
小球数量：1 1 1 1 2 2 1 1 1 0  0  ...
编号 5 和 6 的盒子放有最多小球，每个盒子中的小球数量都是 2 。
```

示例 3：

```
输入：lowLimit = 19, highLimit = 28
输出：2
解释：
盒子编号：1 2 3 4 5 6 7 8 9 10 11 12 ...
小球数量：0 1 1 1 1 1 1 1 1 2  0  0  ...
编号 10 的盒子放有最多小球，小球数量为 2 。
```

提示：

1 <= lowLimit <= highLimit <= 10^5

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/maximum-number-of-balls-in-a-box](https://leetcode-cn.com/problems/maximum-number-of-balls-in-a-box)

Link：[https://leetcode.com/problems/maximum-number-of-balls-in-a-box/](https://leetcode.com/problems/maximum-number-of-balls-in-a-box/)

## 暴力破解

把球的各个数位(10进制)加起来，放入到对应的盒子中， 例如编号365 = 3 + 6 + 5 = 14, 也就是将365号球放入到14盒子中

```python
from collections import Counter
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        
        counter = Counter()
        for num in range(lowLimit, highLimit + 1):
            
            box = 0
            while num > 0:
                box += num % 10
                num = num // 10
                
            counter[box] += 1
            
        return max(counter.values())
```

## 动态规划

### 记忆化计算

在暴力计算过程中，还是有很多重复计算的，并且一个数字可以拆解左边 + 右边的和, 而且可以把子树的结果保存起来，达到去掉重复计算的目的

```python
     365
     / \
   36   5
  / \
 3   6
```

然鹅，这个时间复杂度更高了

```python
from functools import lru_cache
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        
        counter = [0 for i in range(46)]
        for num in range(lowLimit, highLimit + 1):
            
            box = self.boxNumber(num)                
            counter[box] += 1
            
        return max(counter)
    
    @lru_cache(maxsize=None)
    def boxNumber(self, num: int) -> int:
        if 0 <= num <= 9:
            return num
        
        # 计算位数
        tmp = num
        digits = 0
        while tmp > 0:
            tmp = tmp // 10
            digits += 1
            
        zeros = 10 ** (digits >> 1)
        # 分成左右两部分
        left_num = num // zeros
        right_num = num - left_num * zeros
        
        return self.boxNumber(left_num) + self.boxNumber(right_num)
```

另一种思路， 是把一个数的末尾单独拆出来，2365 = 236 + 5 

```python
      2365
      /  \
    236   5
    / \
  23   6
 / \
2   3
```

缓存命中率明显提高了, 但依旧没有暴力破解快

```python
from functools import lru_cache
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        
        counter = [0 for i in range(46)]
        for num in range(lowLimit, highLimit + 1):
            
            box = self.boxNumber(num)                
            counter[box] += 1
            
        return max(counter)
    
    @lru_cache(maxsize=None)
    def boxNumber(self, num: int) -> int:
        if 0 <= num <= 9:
            return num
                 
        zeros = 10 
        # 分成左右两部分
        left_num = num // zeros
        right_num = num - left_num * zeros
        
        return self.boxNumber(left_num) + right_num
```

### 递推公式

O(N)

数字的范围 1 ～ 9999 + 1, 所以一共45盒子就足够了

一个数只要在上一个基础上+1，就可以了。但有些特殊的数字例外

```
9 到 10 可以看出盒子的编号减少了8 即 + 1 - 9，
99 到 100 可以看出盒子的编号减少了17 即 + 1 - 9 * 2，
999 到 1000 可以看出盒子的编号减少了26 即 + 1 - 9 * 3
```

代码如下

```python
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        
        counter = [0 for i in range(46)]
        pre = 0
        
        # 计算第一个
        tmp = lowLimit
        while tmp > 0:
            pre += 1
            tmp = tmp // 10
        
        counter[pre] = 1
        
        for num in range(lowLimit + 1, highLimit + 1):

            tmp = num
            zeros = 0
            while tmp % 10 == 0:
                zeros += 1
                tmp = tmp // 10
                
            cur = pre + 1 - 9 * zeros
            
            counter[cur] += 1
            pre = cur
            
        return max(counter)
```

--End--


