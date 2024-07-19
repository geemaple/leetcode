---
layout: post
index: 25
title: "LeetCode-25.K个一组翻转链表(Reverse Nodes in k-Group)"
categories: Leetcode
tags: Leetcode LinkedList
excerpt: "火力全开"
---

* content
{:toc}

这道题是前面[Swap Nodes in Pairs](http://geemaple.github.io/2020/08/01/leetcode-24/)的Follow-up

## 25. K个一组翻转链表

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例：

```
给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5
```

说明：

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/reverse-nodes-in-k-group/](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

Link：[https://leetcode.com/problems/reverse-nodes-in-k-group/](https://leetcode.com/problems/reverse-nodes-in-k-group/)
   
## 模拟法

当**k == 0**或者当**k == 1**时, 直接返回

以**k = 3**为例:

首先，找到每段tail的位置, 记录tmp的位置，作为下一个段的开始节点

然后重复将head的下一个丢到tail后面

```
s -> 1 -> 2 -> 3 -> 4 -> 5

^    ^         ^
head tmp       tail

s -> 2 -> 3 -> 1 -> 4 -> 5 # 第一次丢节点1
s -> 3 -> 2 -> 1 -> 4 -> 5 # 第二次丢节点2
```

代码如下:

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        
        if k < 2:
            return head
        
        cur = sentry = ListNode()
        sentry.next = head
        
        while cur is not None:
            cur = self.reverse(cur, k)
            
        return sentry.next
        
        
    def reverse(self, cur: ListNode, k: int) -> ListNode:
        
        head = tail = cur
        res = head.next
        
        for i in range(k):
            tail = tail.next
            if tail is None:
                return None
         
        for i in range(k - 1):
            tmp = head.next
            head.next = head.next.next
            tmp.next = tail.next
            tail.next = tmp
            
        return res
```
--End--


