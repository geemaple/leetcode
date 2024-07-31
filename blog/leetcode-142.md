---
layout: post
index: 142
title: "LeetCode-142.环形链表 II(Linked List Cycle II)"
categories: Leetcode
tags: Leetcode LinkedList TwoPointers
excerpt: ""
---

* content
{:toc}

## 142. 环形链表 II

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：

你是否可以使用 O(1) 空间解决此题？
 

示例 1：

![图片说明](./images/leetcode-algorithm-142-1.png) 

```
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
```

示例 2：

![图片说明](./images/leetcode-algorithm-142-2.png) 

```
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
```

示例 3：

![图片说明](./images/leetcode-algorithm-142-3.png) 

```
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
```

提示：

```
链表中节点的数目范围在范围 [0, 104] 内
-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/linked-list-cycle-ii/](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

Link：[https://leetcode.com/problems/linked-list-cycle-ii/](https://leetcode.com/problems/linked-list-cycle-ii/)

## 双指针

对于链表找环路的题目，有个通用的解法快慢指针(Floyd判断)。给定两个指针slow和fast，从起始位置出发

每次fast前进两步，slow前进一步， 如果fast走到尽头，那就是没有回路

如果有回路，那么在某一时刻，fast和slow会再次相遇

第一次相遇时，将fast从新放置到链表开头，此后，让fast和slow每次都前进一步

再次相遇时，相遇点既是环路得开始点

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow = fast = head
        cycle = False
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
            
            if slow == fast:
                cycle = True
                break
                
        if not cycle:
            return None
        
        fast = head
        while fast != slow:
            slow = slow.next
            fast = fast.next
            
        return fast
```

## One More Thing

``` 
                                   M
--------------------- S ------- 
                      /        \
                    /            \
                   |      R       |
                    \            /  K
                      \        /
                         ----
```

环的起点s到到链表开头距离为s, 环的长度为r

🐰兔子每次走两步，🐢乌龟每次走一步, 第一次在某点k相遇时, 兔子多转了n圈

兔子 = 2k, 乌龟 = k

2k - k = nr

**k = nr**

**s = k - m**

把第一个k代入

```
s = nr - m

  = (n - 1) * r + (r - m)

```

所以, 兔子🐰从起点走到s, 距离是s

乌龟🐢从k点顺时针走到s, 距离也是s, 只是乌龟要走n圈

--End--


