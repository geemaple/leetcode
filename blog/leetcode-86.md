---
layout: post
index: 86
title: "LeetCode-86.分隔链表(Partition List)"
categories: Leetcode
tags: Leetcode LinkedList TwoPointers
excerpt: "努力就会被看到"
---

* content
{:toc}

## 86. 分隔链表

给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

```
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/partition-list/](https://leetcode-cn.com/problems/partition-list/)

Link：[https://leetcode.com/problems/partition-list/](https://leetcode.com/problems/partition-list/)

## 模拟法

O(N)

先找到满足条件的插入位置，然后遍历把满足条件的节点按序放入插入位置

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        
        sentryHead = ListNode(0)
        sentryHead.next = head
        pre = sentryHead
        
        while pre.next is not None:
            if pre.next.val >= x:
                break
            pre = pre.next
            
        cur = pre
        while cur.next is not None:
            if cur.next.val >= x:
                cur = cur.next
            else:
                tmp = cur.next
                cur.next = cur.next.next
                
                tmp.next = pre.next
                pre.next = tmp
                pre = pre.next   
            
        return sentryHead.next
```

## 双指针

O(N)

用两个链表分别保存小于的 + 大于等于的节点，然后把两个链表连接起来

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        
        small_head = small = ListNode(0)
        bigger_head = bigger = ListNode(0)
        
        cur = head
        while cur is not None:
            if cur.val >= x:
                bigger.next = cur
                bigger = bigger.next
            else:
                small.next = cur
                small = small.next
                
            cur = cur.next
            
        bigger.next = None
        small.next = bigger_head.next
            
        return small_head.next
```

--End--
