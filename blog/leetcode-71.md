---
layout: post
index: 71
title: "LeetCode-71.简化路径(Simplify Path)"
categories: Leetcode
tags: Leetcode String Stack
excerpt: "1024放假"
---

* content
{:toc}

## 71. 简化路径

给出一个文件(Unix 风格的)的绝对路径，简化它，将其转换为标准路径。

在 Unix 文件系统中, 一个点 . 表示当前目录；两个点 .. 表示将目录切换到上一级

⚠️注意，返回的结果必须始终以斜杠 / 开头，并且两个目录名之间只能有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

示例 1：

```
输入："/home/"
输出："/home"
解释：最后一个目录名后面没有斜杠
```

示例 2：

```
输入："/../"
输出："/"
解释：由于 / 是最高级路径，移动到上一级是不可能的，保持 / 不变
```

示例 3：

```
输入："/home//foo/"
输出："/home/foo"
解释：标准路径中，多个连续斜杠需用一个斜杠替换。
```

示例 4：

```
输入："/a/./b/../../c/"
输出："/c"
```

示例 5：

```
输入："/a/../../b/../c//.//"
输出："/c"
```

示例 6：

```
输入："/a//b////c/d//././/.."
输出："/a/b/c"
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/simplify-path/](https://leetcode-cn.com/problems/simplify-path/)

Link：[https://leetcode.com/problems/simplify-path/](https://leetcode.com/problems/simplify-path/)

## 栈

O(N)

⚠️这里有个非常意想不到的Corner-case, '/...'解释为在根目录下有个'...'命名的文件

```python
class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        
        paths = path.split('/')
        for sub in paths:

            if len(sub) == 0:
                continue

            if sub == '..':
                if len(stack) > 0:
                    stack.pop()
            elif sub != '.':
                stack.append(sub)
                
        return '/' + '/'.join(stack)
```

--End--