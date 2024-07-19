---
layout: post
index: 83
title: "LeetCode-83.删除排序链表中的重复元素(Remove Duplicates from Sorted List)"
categories: Leetcode
tags: Leetcode LinkedList
excerpt: "Big Sur is coming this (snow) fall"
---

* content
{:toc}

## 83. 删除排序链表中的重复元素

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

```
输入: 1->1->2
输出: 1->2
```

示例 2:

```
输入: 1->1->2->3->3
输出: 1->2->3
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list)

Link：[https://leetcode.com/problems/remove-duplicates-from-sorted-list](https://leetcode.com/problems/remove-duplicates-from-sorted-list)


## 模拟法

O(N)

```python
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        
        pre = None
        cur = head
        
        while cur is not None:
            if pre is not None and pre.val == cur.val:
                cur = cur.next
                pre.next = cur
            else:
                pre = cur
                cur = cur.next
        
        return head
```

## One More Thing

离今年的153大旗，还有70道

刷到这里，可能发现，很多题都已经忘记了。再次尝试的时候又踩了新的坑。

其实，好多问题很难有人一次就做对，第一次通常都是学习模仿的过程。

如果能做出来，说明基础还不错，多看看社区，网络其他人的解法。说不定有更多的收获，无论是语言本身，还是思考分析过程

**However**

不管第一次结果如何，几个月之后甚至几年之后还能够回忆起来。

能够顺畅的理解分析，从暴力破解到最优解法。

那时，才是自己的收获。

--End--

