---
layout: post
index: 58
title: "LeetCode-58.最后一个单词的长度(Length of Last Word)"
categories: Leetcode
tags: Leetcode String
excerpt: "狼烟起"
---

* content
{:toc}

## 58. 最后一个单词的长度

给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

示例:

```
输入: "Hello World"
输出: 5
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/length-of-last-word/](https://leetcode-cn.com/problems/length-of-last-word/)

Link：[https://leetcode.com/problems/length-of-last-word/](https://leetcode.com/problems/length-of-last-word/)

## 倒着数

O(N)

```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        
        tail = len(s) - 1

        while tail >= 0 and s[tail] == ' ':
            tail -= 1
            
        length = 0
        while tail >= 0 and s[tail] != ' ':
            length += 1
            tail -= 1

        return length
```

## 题外话

### Anki软件

Anki是一款不错的记忆辅助软件，用来背单词，刷题再好不过了。

### 如何使用

背诵少量代码是可以的，但是对于大量代码来说，背诵是不现实的

需要记忆的只是其中的题型，解题思路，踩过的坑。

正面：

58\. Length of Last Word

反面：

for循环，注意结尾空字符的情况

### 按时复习

刚开始，时间精力不够，可以只复习解题的思路。

后续时间充裕的时候，一定要写代码，保持一个良好的状态

--End--