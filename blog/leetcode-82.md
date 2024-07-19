---
layout: post
index: 82
title: "LeetCode-82.删除排序链表中的重复元素 II(Remove Duplicates from Sorted List II)"
categories: Leetcode
tags: Leetcode LinkedList
excerpt: "Winter is coming"
---

* content
{:toc}

> 最近遇到了好多用眼睛一看很简单, 或者思路很简单, 但是代码实现却无从下手的问题, 甚至以为自己想好了，直到落到代码，才发现还是有好多处纰漏

## 82. 删除排序链表中的重复元素 II

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

```
输入: 1->2->3->3->4->4->5
输出: 1->2->5
```

示例 2:

```
输入: 1->1->1->2->3
输出: 2->3
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)

Link：[https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii)


## 模拟法

O(N)

新链表记得结尾要断掉

```python
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        sentryHead = ListNode()
        
        start = cur = head
        tmp = sentryHead

        while cur is not None:
            
            while cur.next is not None and cur.next.val == cur.val:
                cur = cur.next
            
            if start == cur:
                tmp.next = cur
                tmp = tmp.next
                
            start = cur = cur.next
            tmp.next = None
        
        return sentryHead.next
```

## One More Thing

作者：高畅, 谷歌无人车部门(Waymo)的工程师，从事计算机视觉和机器学习方向。

任何入门的内容，都会以101作为名称。所以适合任何对算法感兴趣的人。

2018年，作者在攻读硕士，准备秋招的几个月时间，刷了几百道题。有了刷题的积累和不错的运气，很快就找到了工作

2019毕业后入职前，将历史刷题归纳总结，便于他人阅读和学习，Respect!!!

---------------------------------------------------------------------------

一个面向有C++编程基础，但缺乏刷题经验的读者的教科书和工具书（不适合编程小白喔）。

永久免费，禁止任何盈利性利用，欢迎传阅和指正。

直达链接:[https://github.com/changgyhub/leetcode_101](https://github.com/changgyhub/leetcode_101)



--End--
