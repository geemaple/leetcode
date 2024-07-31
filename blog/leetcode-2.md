---
layout: post
index: 2
title: "LeetCode-2.两数相加(Add Two Numbers)"
categories: Leetcode
tags: Leetcode LinkedList
excerpt: "给链表头加一个哨兵, 省去了处理特殊逻辑，生活会简单许多。噢力给～"
---

* content
{:toc}

## 2. 两数相加

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

例如:

```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/add-two-numbers/](https://leetcode-cn.com/problems/add-two-numbers/)

Link：[https://leetcode.com/problems/add-two-numbers/](https://leetcode.com/problems/add-two-numbers/)

### 双指针

O(M + N), M和N分别是两个链表的长度

对于链表的题目，通常都没有什么算法可言，考察更多的是coding的基本功以及对于指针的理解

该题目，链表第一位是**个位**，依次是**十位，百位，千位...**

遍历两个链表，按位相加即可， 进位保存在临时变量中。

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        pre = head = ListNode()
        addition = 0
        
        while (l1 is not None or l2 is not None or addition > 0):
            num1 = 0 if l1 is None else l1.val
            num2 = 0 if l2 is None else l2.val
            
            total = num1 + num2 + addition
            addition = total // 10
            pre.next = ListNode(val = total % 10)
            
            pre = pre.next
            l1 = None if l1 is None else l1.next
            l2 = None if l2 is None else l2.next
            
        return head.next

```

--End--