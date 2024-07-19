---
layout: post
index: 6
title: "LeetCode-6.Z字形变换(ZigZag Conversion)"
categories: Leetcode
tags: Leetcode String
excerpt: "归去来，与天杀价净赚三百"
---

* content
{:toc}

> 这道题更像是一则广告，吸引程序员投简历的。

## 6. Z 字形变换

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

```
P   A   H   N
A P L S I I G
Y   I   R
```

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

```
string convert(string s, int numRows);
```

示例 1:

```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

示例 2:

```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/zigzag-conversion/](https://leetcode-cn.com/problems/zigzag-conversion/)

Link：[https://leetcode.com/problems/zigzag-conversion/](https://leetcode.com/problems/zigzag-conversion/)

## 模拟法1

O(N)

创建N个数组，每个收集对应行的字母, 最后再把N个字符串合并

先收集垂直向下的|, 然后收集斜向上的/, 重复直到字符串用完

```python
P     I    N  # P     # I    # N 
A   L S  I G  # A   L # S  I # G
Y A   H R     # Y A   # H R  #
P     I       # P     # I    #
```

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        if numRows < 2 or numRows >= len(s):
            return s
        
        rows = ['' for i in range(numRows)]
        
        i = 0
        while (i < len(s)):
            n = 0
            while n < numRows and i < len(s):
                # 垂直向下｜
                rows[n] += s[i]
                i += 1
                n += 1
            
            n = numRows - 2
            while n > 0 and i < len(s):
                # 斜向上 /
                rows[n] += s[i]
                i += 1
                n -= 1
                    
        return ''.join(rows)
```



## 模拟法2

O(N)

最好在纸上多举几个例子, 找下规律

注意每行答案，下一个字母与上一个字母坐标差值

比如3行第一排，第一个字母P, 需要每走4步，得到下一个答案字母P -> A -> H -> N 记作：**# 4  4  4**

```python
P   A   H   N  # 4  4  4
A P L S I I G  # 2  2  2  2  2  2
Y   I   R      # 4  4
```

```python
P     I    N  # 6  6
A   L S  I G  # 4  2  4  2
Y A   H R     # 2  4  2
P     I       # 6
```

```python     
P       H     # 8
A     S I     # 6  2
Y   I   R     # 4  4
P L     I G   # 2  6  2
A       N     # 8
```

第一行和最后一行, 每个元素相隔```base = (numRows - 1) * 2```

其他行，间隔m和n循环出现，且```m + n = base```

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        if numRows < 2 or numRows >= len(s):
            return s
        
        base = (numRows - 1) * 2
        res = ''
        
        for i in range(numRows):
            step = i
            last = i * 2
            
            while(step < len(s)):
                res += s[step]
                if base - last > 0:
                    step += base - last
                    last = base - last
                else:
                    step += base
                    last = base
                    
        return res
```

--End--


