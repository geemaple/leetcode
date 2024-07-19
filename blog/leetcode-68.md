---
layout: post
index: 68
title: "LeetCode-68.文本左右对齐(Text Justification)"
categories: Leetcode
tags: Leetcode Math String
excerpt: "前端工程师必备"
---

* content
{:toc}

## 68. 文本左右对齐

给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

```
单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
```

示例:

```
输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```

示例 2:

```
输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
```

示例 3:

```
输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/text-justification](https://leetcode-cn.com/problems/text-justification)

Link：[https://leetcode.com/problems/text-justification/](https://leetcode.com/problems/text-justification/)

## 模拟法

O(N)

这道题还真不难，也没啥算法，这道题Corner-Case有：

1. 比如一行只有一个单词的时候
2. 最后一行，需要单独处理
3. 空格分配不均匀时, 左侧分配的空格更多

```python
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:

        length = 0
        line = []
        res = []

        for word in words:
            # 当前word长度 + 总长度 + 应该有多少个空格 <= maxWidth
            if len(word) + length + len(line) <= maxWidth:
                length += len(word)
                line.append(word)
            else:
                blanks = (maxWidth - length)
                padding = blanks // (len(line) - 1) if len(line) > 1 else maxWidth - length
                extra_padding = blanks % (len(line) - 1) if len(line) > 1 else 0
                
                output = line[0]
                if len(line) > 1:
                    for text in line[1:]:
                        output += ' ' * padding
                        if extra_padding > 0:
                            output += ' '
                            extra_padding -= 1
                        output += text
                else:
                    output += ' ' * (padding + extra_padding)
                res.append(output)
                
                length = len(word)
                line =[word]
                
        # 最后一行
        if len(line) > 0:
            output = ' '.join(line) + ' ' * (maxWidth - length - (len(line) - 1))
            res.append(output)

        return res
```

思路一致，简洁的令人发指

```python
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res, cur, num_of_letters = [], [], 0
        for w in words:
            if num_of_letters + len(w) + len(cur) > maxWidth:
                for i in range(maxWidth - num_of_letters):
                    cur[i%(len(cur)-1 or 1)] += ' '
                res.append(''.join(cur))
                cur, num_of_letters = [], 0
            cur += [w]
            num_of_letters += len(w)
        return res + [' '.join(cur).ljust(maxWidth)]
```

--End--
