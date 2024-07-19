---
layout: post
index: 72
title: "LeetCode-72.编辑距离(Edit Distance)"
categories: Leetcode
tags: Leetcode String DP
excerpt: "禁酒令"
---

* content
{:toc}

## 72. 编辑距离

给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

1. 插入一个字符
2. 删除一个字符
3. 替换一个字符
 

示例 1：

```
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
```

示例 2：

```
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/edit-distance](https://leetcode-cn.com/problems/edit-distance)

Link：[https://leetcode.com/problems/edit-distance/](https://leetcode.com/problems/edit-distance/)


## 动态规划

O(M*N)

```
    ''    R    O    S    # word2

''   0    1    2    3

H    1    --------------------> 插入
         | \
O    2   |   \
         |     \ 
R    3   |       \
         |         \ 
S    4   |           \
         |             \  替换
E    5   v 删除           45.Degree

# word1
```

### 递推公式

定义table[i][j]代表word1[:i]与word2[:j]能够匹配的时候需要的操作次数(包含i, j)

```
# 如果两个单词字符word1[i] == word2[j]:
table[i][j] = table[i - 1][j - 1]

# 如果不想等, 三个策略选择次数最少的一个方案:

# 策略1, word1插入一个字符

table[i][j] = table[i][j - 1] + 1

# 策略2, word1删除一个字符

table[i][j] = table[i - 1][j] + 1

# 策略3, word1替换一个字符

table[i][j] = table[i - 1][j - 1]

```

### 计算方向

 水平逐行扫描

 ### 边界条件

```
# 水平第一行, 代表空字符的word1, 与word2相比配, 只能依次插入

# 水平第一行, 代表word1, 与空字符的word2相比配, 只能依次删除

```

 ### 初始条件

```
table[0][0] = 0 # 表示两个空字符，无需任何操作
```

代码如下:

```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        
        table = [[0 for j in range(len(word2) + 1)] for i in range(len(word1) + 1)]
        
        # 第一排初始值, 只能依次插入
        for j in range(1, len(table[0])):
            table[0][j] = table[0][j - 1] + 1
        
        # 第一列初始值, 只能插入
        for i in range(1, len(table)):
            table[i][0] = table[i - 1][0] + 1
        
        for i in range(len(word1)):
            for j in range(len(word2)):
    
                if word1[i] == word2[j]:
                    table[i + 1][j + 1] = table[i][j]
                else:
                    # 插入, 删除, 替换
                    table[i + 1][j + 1] = min(table[i + 1][j], table[i][j + 1], table[i][j]) + 1
        
        return table[-1][-1]
```

## 手动递推

```
    ''    R    O    S    # word2

''   0    1    2    3

H    1    1    2    3
         
O    2    2    1    2
         
R    3    2    2    2
     
S    4    3    3    2
         
E    5    4    4    3

# word1
```

--End--