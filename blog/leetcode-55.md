---
layout: post
index: 55
title: "LeetCode-55.跳跃游戏(Jump Game)"
categories: Leetcode
tags: Leetcode Array Greedy
excerpt: "跳出____"
---

* content
{:toc}

## 55. 跳跃游戏

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

```
输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
```

示例 2:

```
输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/jump-game/](https://leetcode-cn.com/problems/jump-game/)

Link：[https://leetcode.com/problems/jump-game/](https://leetcode.com/problems/jump-game/)

## 贪心

O(N)

> 贪心除了经典的题目, 一般很少碰到, 贪心的难点是如何证明贪心的解法是正确的, 通常我们**举一个反例**来反驳它

以 **[2, 3,  1,  1,  4]** 为例:

```
# 第一步跳跃距离, 从f跳跃到t
[2, 3,  1,  1,  4]   
 f      t       

# 在下次跳跃之前，看看最远能跳到哪, 考察位置[a, b]
[2, 3,  1,  1,  4]
 ^      ^          
    a   b

# a能跳到末尾, 解题结束
```

代码如下：

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        farthest = 0
        step = 0
        
        for i in range(len(nums)):
            
            distance = i + nums[i]
            farthest = max(farthest, distance)
            
            # 在跳跃之前停下来，看看最远能跳多远，然后选择最远的距离
            if i == step:
                step = farthest

        return step >= len(nums) - 1
```

查看每个位置，最远能跳到多远，直到i > farthest时， 说明不可达

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        farthest = 0
    
        for i in range(len(nums)):
            if i > farthest:
                return False
            farthest = max(farthest, i + nums[i])
            
        return True
```

--End--