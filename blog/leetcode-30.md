---
layout: post
index: 30
title: "LeetCode-30.串联所有单词的子串(Substring with Concatenation of All Words)"
categories: Leetcode
tags: Leetcode String HashTable TwoPointers
excerpt: "第一组30道题结束了"
---

* content
{:toc}

## 30. 串联所有单词的子串

给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，任意单词 words 之间不存在共用字符。

示例 1：

```
输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
```

示例 2：

```
输入：
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
输出：[]
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)

Link：[https://leetcode.com/problems/substring-with-concatenation-of-all-words/](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)

## 哈希

O(N * M)

找到所有可能的子串(N个)，检查子串是否符合条件(最多M次), 每个单词字符串长度(K)

```
b a r f o o t h e f o o b a r m a n
^ ^ ^ ^ ^ ^      
b a r f o o t h e f o o b a r m a n
  ^ ^ ^ ^ ^ ^      
b a r f o o t h e f o o b a r m a n
    ^ ^ ^ ^ ^ ^      
b a r f o o t h e f o o b a r m a n
      ^ ^ ^ ^ ^ ^ 
...
```

时间复杂度O(K * N * M), 单词的长度K有限，所有复杂度O(M * N)

```python
from collections import Counter
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        
        if len(s) == 0 or len(words) == 0 or len(words[0]) == 0:
            return []
        
        words_count = Counter()
        for word in words:
            words_count[word] += 1
            
        res = []
        word_length = len(words[0])
        sub_length = len(words) * word_length

        for i in range(len(s) - sub_length + 1):
            check_count = Counter()
            
            for j in range(i, i + sub_length, word_length):
                word = s[j : j + word_length]          
                if word in words_count:
                    check_count[word] += 1
                else:
                    break

            if check_count == words_count:
                res.append(i)
            
        return res
```

## 双指针(滑动窗口)

O(N)

双箭头作为起点，每次移动单词长度，就能覆盖所有**窗口起点**的情况

```
b a r f o o t h e f o o b a r m a n
^     ^ 
^      
b a r f o o t h e f o o b a r m a n
  ^     ^
  ^  
b a r f o o t h e f o o b a r m a n
    ^     ^
    ^      
```

以其中一种为例, 每次移动**一个单词**长度。

每一个单词进入窗口，离开窗口, 最多处理两次 O(K * N * 2), 单词的长度K有限, 所以是O(N)

```
# 使用[bar] 还剩[foo]
b a r f o o t h e f o o b a r m a n  
i      
j   | 
# 右移动j, 使用[bar, foo] 还剩[]
b a r f o o t h e f o o b a r m a n  
i
      j   |
# 此时，拿到答案i, 右移动i, 使用[foo] 还剩[bar]
b a r f o o t h e f o o b a r m a n  
      i     
      j   |
# 使用[foo, the] 还剩[bar]
b a r f o o t h e f o o b a r m a n  
      i
            j   |
# [the]不在有效值中, 清空使用记录，右移动i到j的下一个单词
b a r f o o t h e f o o b a r m a n  
                  i     
            j   |
# 使用[foo], 还剩[bar]
b a r f o o t h e f o o b a r m a n  
                  i     
                  j   |
# 使用[foo, bar], 还剩[]
b a r f o o t h e f o o b a r m a n  
                  i     
                        j   |
# 此时，拿到答案i, 右移动i, 使用[bar] 还剩[foo]
b a r f o o t h e f o o b a r m a n  
                        i     
                        j   |
# 使用[foo, man] 还剩[bar], 右窗口到尽头，已经结束
b a r f o o t h e f o o b a r m a n  
                        i     
                              j   |
```

代码如下:

```python
from collections import Counter
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        
        if len(s) == 0 or len(words) == 0 or len(words[0]) == 0:
            return []
        
        words_count = Counter()
        for word in words:
            words_count[word] += 1
            
        res = []
        word_length = len(words[0])
        sub_length = len(words) * word_length
        
        for i in range(word_length):
            left = i
            check_count = Counter()
            count = 0
            
            for j in range(i, len(s) - word_length + 1, word_length):
                in_word = s[j: j + word_length]
  
                if in_word in words_count:
                    check_count[in_word] += 1
                    
                    if check_count[in_word] <= words_count[in_word]:
                        count += 1
                    else:
                        while check_count[in_word] > words_count[in_word]:
                            out_word = s[left: left + word_length]
                            check_count[out_word] -= 1
                            
                            if check_count[out_word] < words_count[out_word]:
                                count -= 1
                            left += word_length
                        
                    if count == len(words):
                        res.append(left)
                        out_word = s[left: left + word_length]
                        check_count[out_word] -= 1
                        count -= 1
                        left += word_length
                else:
                    check_count = Counter()
                    left = j + word_length
                    count = 0
                
        return res
```
--End--


