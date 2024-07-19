---
layout: post
index: 92
title: "LeetCode-92.反转链表 II(Reverse Linked List II)"
categories: Leetcode
tags: Leetcode LinkedList
excerpt: "你好微软，很高兴遇到你"
---

* content
{:toc}

## 92. 反转链表 II

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

```
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/reverse-linked-list-ii/](https://leetcode-cn.com/problems/reverse-linked-list-ii/)

Link：[https://leetcode.com/problems/reverse-linked-list-ii/](https://leetcode.com/problems/reverse-linked-list-ii/)


## 模拟法

O(N)

先找到反转起点的上一个，加一个哨兵会比较好处理

然后依次反转n - m + 1个

有的时候明明想对了，但是代码却有自己的想法，写成了环

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        
        sentryHead = ListNode(0)
        sentryHead.next = head
        
        cur = reverse_start = sentryHead
        position = 0
        while cur is not None:
            if position == m - 1:
                reverse_start = cur
                break
                
            position += 1
            cur = cur.next
            
        
        cur = reverse_end = reverse_start.next
        position = 0
        while cur is not None:
            if position == n - m + 1:
                break
                
            tmp = reverse_start.next
            reverse_start.next = cur
            
            next = cur.next
            cur.next = tmp
            
            cur = next
            position += 1
            
        reverse_end.next = next
        
        return sentryHead.next
```

这个是之前的我写出来的，思路一致，代码简洁不少。

随着时间推移, 但很少能写出一摸一样的代码，变菜了

```python
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        
        sentryHead = ListNode(0)
        sentryHead.next = head
        
        cur = sentryHead
        for _ in range(m - 1):
            cur = cur.next

        head = cur
        cur = head.next
        
        for _ in range(n - m):

            tmp = cur.next
            cur.next = cur.next.next
            
            tmp.next = head.next
            head.next = tmp
        
        return sentryHead.next
```


--End--
