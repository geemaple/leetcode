---
layout: post
index: 23
title: "LeetCode-23.合并K个排序链表(Merge k Sorted Lists)"
categories: Leetcode
tags: Leetcode LinkedList Heap Divide&Conquer
excerpt: "蜗牛与雄鹰"
---

* content
{:toc}

这是前面[Merge Two Sorted Lists](http://geemaple.github.io/2020/07/29/leetcode-21/)的一个follow-up

排序超大数量级的数据，可以分成N个机器分别排序，然后把结果汇总起来。

## 23. 合并K个升序链表

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

```
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/merge-k-sorted-lists/](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

Link：[https://leetcode.com/problems/merge-k-sorted-lists/](https://leetcode.com/problems/merge-k-sorted-lists/)

## 小堆

O(N*logK), 其中K = 链表条数。N = 总元素个数

将N个链表头数据放入到小堆中, 然后将堆顶移除，填入到结果链表中，并将堆顶的下一个元素放入到堆中

### python版本差异

python2中，heap中的item如果是个tuple，只比较第一个元素

python3中，heap中的item如果是个tuple，如果第一个元素相等，会比较第二个，第三个元素...

所以代码中，额外代码```ListNode.__lt__ = node_comparator```来解决

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import heapq
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        
        def node_comparator(a, b):
            return a.val < b.val
        ListNode.__lt__ = node_comparator

        sentry =  ListNode(0)
        cur = sentry
        h = []

        for i in range(len(lists)):
            if lists[i] is not None:
                heapq.heappush(h, lists[i])

        while len(h) > 0:
            target = heapq.heappop(h)
            cur.next = target
            cur = cur.next
            if target.next is not None:
                heapq.heappush(h, target.next)

        return sentry.next
```

## 归并

O(N*logK), 比较次数=树的高度为K

两两合并，也就是1, 2合并，3, 4合并, 5, 6合并, ... 如图, linked-list-1最多比较logK次

> 如果1，2合并，再依次和3, 4...合并, 时间负责度就不一样了, 因为这样链表1和其他每个链表都比较1次

![图片说明](./images/leetcode-sketch-algorithm-23.jpg)

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import heapq
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        
        q = deque(lists)     
        while len(q) > 1:
            l1 = q.popleft()
            l2 = q.popleft()
    
            cur = sentry = ListNode()
            while l1 is not None and l2 is not None:
                if l1.val < l2.val:
                    cur.next = l1
                    l1 = l1.next
                else:
                    cur.next = l2
                    l2 = l2.next
                cur = cur.next
            
            cur.next = l1 if l1 is not None else l2
            q.append(sentry.next)

        return q[0] if len(q) > 0 else None 
```

--End--


