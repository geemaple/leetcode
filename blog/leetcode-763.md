---
layout: post
index: 763
title: "LeetCode-763.划分字母区间(Partition Labels)"
categories: Leetcode
tags: Leetcode TwoPointers Greedy
excerpt: ""
---

* content
{:toc}

## 763. 划分字母区间

字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

示例：

```
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
```

提示：

```
S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/partition-labels](https://leetcode-cn.com/problems/partition-labels)

Link：[https://leetcode.com/problems/partition-labels/](https://leetcode.com/problems/partition-labels/)

## 贪心

O(N)

首先统计每个字母的起始位置+结束位置

然后根据统计，尽可能少的截取每一个字符串，这样总结果数量会最多

```python
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        
        process = {}
        for i in range(len(S)):
            char = S[i]
            if char not in process:
                process[char] = [i, i]
            else:
                process[char][1] = i

        res = []
        i = 0
        while i < len(S):

            right = process[S[i]][1]
            left = i + 1
            while left <= right:
                right = max(right, process[S[left]][1])
                left += 1
            
            res.append(right - i + 1)
            i = right + 1
        
        return res
```

发现起始坐标也没啥用，那么也可以省略

```python
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        
        process = {}
        for i in range(len(S)):
            char = S[i]
            process[char] = i

        res = []
        i = 0
        while i < len(S):

            right = process[S[i]]
            left = i + 1
            while left <= right:
                right = max(right, process[S[left]])
                left += 1
            
            res.append(right - i + 1)
            i = right + 1
        
        return res
```

## 双指针

O(N)

有了上面的基本思路之后，使用两个指针作为滑动窗口，然后把窗口的长度记录在结果里

```python
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        
        process = {}
        for i in range(len(S)):
            char = S[i]
            process[char] = i

        res = []
        left = right = 0
        for i in range(len(S)):
            
            char = S[i]
            right = max(right, process[char])
            
            if i == right:
                res.append(right - left + 1)
                left = right + 1
        
        return res
```

--End--


