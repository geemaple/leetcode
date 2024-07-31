---
layout: post
index: 20
title: "LeetCode-20.有效的括号(Valid Parentheses)"
categories: Leetcode
tags: Leetcode String Stack
excerpt: "K-Sum终结者"
---

* content
{:toc}
## 20. Valid Parentheses

给一个字符串, 只包括 '('，')'，'{'，'}'，'['，']' ，判断字符串是否有效。

有效字符串需需满足：

左括号必须用相同类型的右括号匹配。

左括号必须以正确的顺序匹配。

> 注意空字符串可被认为是有效字符串。

示例 1:

```
输入: "()"
输出: true
```

示例 2:

```
输入: "()[]{}"
输出: true
```

示例 3:

```
输入: "(]"
输出: false
```

示例 4:

```
输入: "([)]"
输出: false
```

示例 5:

```
输入: "{[]}"
输出: true
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/valid-parentheses/](https://leetcode-cn.com/problems/valid-parentheses/)

Link：[https://leetcode.com/problems/valid-parentheses/](https://leetcode.com/problems/valid-parentheses/)

## 栈

O(N)

如果是左括号，则将括号压入栈中。

如果是右括号，则查看栈顶是否有匹配，没有则返回False

如果最终栈不为空，返回False

### 空间复杂度

空间复杂度，指额外的空间使用。

比方说，如果答案要求返回数组，那么这个数组是必须的，不计算在空间复杂度里面

本题使用了mapping和stack, 空间复杂度分别为O(3)和O(N)

最终空间复杂度主要为stack使用部分，为O(N)

```python
class Solution:
    def isValid(self, s: str) -> bool:
        
        mapping = {
            ')': '(',
            '}': '{',
            ']': '[',
        }
        
        stack = []
        
        for i in range(len(s)):
            
            if s[i] not in mapping:
                stack.append(s[i])
                continue
                
            if len(stack) > 0 and stack[-1] == mapping[s[i]]:
                stack.pop()
            else:
                return False
        
        return len(stack) == 0
```

--End--


