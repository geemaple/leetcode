---
layout: post
index: 65
title: "LeetCode-65.有效数字(Valid Number)"
categories: Leetcode
tags: Leetcode Math String
excerpt: "千呼万唤使出来"
---

* content
{:toc}

## 65. 有效数字

验证给定的字符串是否可以解释为十进制数字。

例如:

```
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
```

说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表：

```
数字 0-9
指数 - "e"
正/负号 - "+"/"-"
小数点 - "."
当然，在输入中，这些字符的上下文也很重要。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/valid-number/](https://leetcode-cn.com/problems/valid-number/)

Link：[https://leetcode.com/problems/valid-number/](https://leetcode.com/problems/valid-number/)

## 依次判断

O(N)

```python
class Solution:
    def isNumber(self, s: str) -> bool:
        
        s = s.strip()
        
        i = 0
        
        # 符号位
        if i < len(s) and (s[i] == '+' or s[i] == '-'):
            i += 1
            
        # 数字
        point_count = 0
        digit_count = 0
        while i < len(s) and ('0' <= s[i] <= '9' or s[i] == '.'):
            if s[i] == '.':
                point_count += 1
            else:
                digit_count += 1
                
            i += 1
                
        if point_count > 1 or digit_count < 1:
            return False
        
        # 指数位
        if i < len(s) and s[i] == 'e':
            i += 1
            
            if i < len(s) and (s[i] == '+' or s[i] == '-'):
                i += 1
                
            digit_count = 0
            while i < len(s) and '0' <= s[i] <= '9':
                digit_count += 1
                i += 1
                
            if digit_count < 1:
                return False
            
        return i == len(s)
```

## 正则表达式

参考:[https://leetcode.com/problems/valid-number/discuss/23728/A-simple-solution-in-Python-based-on-DFA](https://leetcode.com/problems/valid-number/discuss/23728/A-simple-solution-in-Python-based-on-DFA)

```python
import re
class Solution:
    def isNumber(self, s: str) -> bool:
        return re.search(r'^\s*[+-]?(\d+(\.\d*)?|\.\d+)(e[+-]?\d+)?\s*$', s)
```

## 有限自动机

```
blank    +/-    digit    .    digit    e    +/-    digit    blank

1      2        3      4      5      6      7      8        9
```

### 状态转换

```
1 -> blank=1, sign=2, digit=3, dot=4
2 -> digit=3, dot=4
3 -> digit=3, dot=4, e=6, blank=9  # ⚠️这里dot的转移状态和社区大神的不一致, 但个人觉得更好理解
4 -> digit=5
5 -> digit=5, e=6, blank=9
6 -> sign=7, digit=8
7 -> digit=8
8 -> digit=8, blank=9
9 -> blank=9
```

### 结束状态

3, 5, 8, 9
4 比较特殊， 如果遇到过数字，就是有效结束状态

```python
class Solution:
    def isNumber(self, s: str) -> bool:
        table = [{}, 
            {'blank': 1, 'sign': 2, 'digit': 3, '.': 4}, 
            {'digit': 3, '.': 4},
            {'digit': 3, '.': 5, 'e': 6, 'blank': 9},
            {'digit': 5},
            {'digit': 5, 'e': 6, 'blank': 9},
            {'sign': 7, 'digit': 8},
            {'digit': 8},
            {'digit': 8, 'blank': 9},
            {'blank': 9}]
        state = 1
        digit_seen = False

        for c in s:
            if '0' <= c <= '9':
                c = 'digit'
                digit_seen = True
            if c == ' ':
                c = 'blank'
            if c in ['+', '-']:
                c = 'sign'
            if c not in table[state].keys():
                return False
            state = table[state][c]

        return state in [3, 5, 8, 9] or (state == 4 and digit_seen)
```

--End--