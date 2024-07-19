---
layout: post
index: 136
title: "LeetCode-136.只出现一次的数字(Single Number)"
categories: Leetcode
tags: Leetcode HashTable BitManipulation
excerpt: ""
---

* content
{:toc}

## 136. 只出现一次的数字

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

```
输入: [2,2,1]
输出: 1
```

示例 2:

```
输入: [4,1,2,1,2]
输出: 4
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/single-number/](https://leetcode-cn.com/problems/single-number/)

Link：[https://leetcode.com/problems/single-number/](https://leetcode.com/problems/single-number/)

## 二进制

O(N)

```python
x ^ 0 = x
x ^ x = 0
```

利用上述特性, 0与任意bit异或，都等于bit值。所以初始化为0

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for n in nums:
            res ^= n
            
        return res
```

--End--


