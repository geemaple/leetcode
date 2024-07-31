---
layout: post
index: 24
title: "LeetCode-24.两两交换链表中的节点(Swap Nodes in Pairs)"
categories: Leetcode
tags: Leetcode LinkedList
excerpt: "早安八月"
---

* content
{:toc}

## 24. 两两交换链表中的节点

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例:

```
给定 1->2->3->4, 你应该返回 2->1->4->3.
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/swap-nodes-in-pairs/](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

Link：[https://leetcode.com/problems/swap-nodes-in-pairs/](https://leetcode.com/problems/swap-nodes-in-pairs/)

## 模拟法

O(N)

> 链表没什么算法可言，把纸上推演的步骤用代码实现即可，硬要说可以归类双指针

记得使用哨兵头节点，当tmp指向每组第一个时, 注意while循环的条件判断

```python
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        cur = sentry = ListNode()
        sentry.next = head
        
        while cur.next is not None and cur.next.next is not None:
            tmp = cur.next
            
            cur.next = tmp.next
            tmp.next = cur.next.next
            cur.next.next = tmp
            
            cur = tmp
            
        return sentry.next
```

记得使用哨兵头节点，当tmp指向每组第二个时, 同样，注意while循环的条件判断

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        cur = sentry = ListNode()
        sentry.next = head

        while cur.next is not None and cur.next.next is not None:
            tmp = cur.next.next

            cur.next.next = tmp.next
            tmp.next = cur.next
            cur.next = tmp

            cur = cur.next.next
```

--End--


