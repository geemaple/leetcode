---
layout: post
index: 19
title: "LeetCode-19.删除链表的倒数第N个节点(Remove Nth Node From End of List)"
categories: Leetcode
tags: Leetcode Array HashTable TwoPointers
excerpt: "K-Sum终结者"
---

* content
{:toc}
## 19. Remove Nth Node From End of List

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

```
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```

说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

Link：[https://leetcode.com/problems/remove-nth-node-from-end-of-list/](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

## 两次扫描

O(N)

先扫描链表的长度，倒数第N个就很容易计算出来是第几个

## 双指针

O(N)

双指针也称快慢指针，可以满足题目要求的只需一次扫描

创建哨兵节点head，快指针从哨兵节点head先走N步, 然后慢指针从哨兵head开始扫描

等快指针结束后，慢指针停留的位置target便可以删除

第一步:

```
head -> 1 -> 2 -> 3 -> 4 -> 5
 ^           ^
slow        fast 
```

第二步：

```
head -> 1 -> 2 -> 3 -> 4 -> 5
        ^         ^
       slow      fast 
```

依次移动，直到**fast.next == None**：

```
head -> 1 -> 2 -> 3 -> 4 -> 5
                  ^         ^
                slow       fast 
```

最后一步，删除slow对应的节点target：

```
head -> 1 -> 2 -> 3 -> 4 -> 5
                  ^    ^
               slow -> ​target
```

代码如下

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        sentryHead = ListNode()
        sentryHead.next = head
        
        slow = fast = sentryHead
        step = 0
        
        while(fast.next is not None):
            fast = fast.next
            if step >= n:
                slow = slow.next
        
            step += 1
        
        slow.next = slow.next.next
        return sentryHead.next
        
```

--End--


