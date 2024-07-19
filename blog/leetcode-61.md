---
layout: post
index: 61
title: "LeetCode-61.旋转链表(Rotate List)"
categories: Leetcode
tags: Leetcode LinkedList TwoPointers
excerpt: "马恩河战役"
---

* content
{:toc}

## 61. 旋转链表

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

```
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL

解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
```

示例 2:

```
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL

解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
```

来源：力扣（LeetCode）

链接：https://leetcode-cn.com/problems/rotate-list/

Link：https://leetcode.com/problems/rotate-list/

## 双指针

找到最后**k+1**节点, 然后把两部分对调

```
1 -> 2 -> 3 -> 4 -> 5 -> None
          ^         ^
        start      end
```

### 循环访问

O(N), N = MAX(链表长度, K)

个人比较喜欢的解法，K过大会超时

```python
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        
        newHead = ListNode()
        newHead.next = head
        
        fast = slow = newHead
        count = 0
        
        while fast.next is not None:
            fast = fast.next
            count += 1
            
            if count > k:
                slow = slow.next
            elif fast.next is None:
                fast = newHead
             
        fast.next = head
        newHead.next = slow.next
        slow.next = None
        
        return newHead.next
```

### 先获取长度

O(N)

```python
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        
        if head is None:
            return None
        
        length = 0
        cur = head
        while (cur is not None):
            cur = cur.next
            length += 1

        step = k % length
        slow = fast = head

        count = 0
        while(fast.next is not None):
            fast = fast.next
            count += 1
            if count > step:
                slow = slow.next

        new_head = ListNode(0)
        new_head.next = head

        fast.next = head
        new_head.next = slow.next
        slow.next = None

        return new_head.next
```
--End--
