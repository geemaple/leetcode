---
layout: post
index: 109
title: "LeetCode-109.有序链表转换二叉搜索树(Convert Sorted List to Binary Search Tree)"
categories: Leetcode
tags: Leetcode LinkedList DFS
excerpt: "刷出奇迹"
---

* content
{:toc}

## 109. 有序链表转换二叉搜索树

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

![图片说明](./images/leetcode-algorithm-109.jpg)

示例:

```
给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)

Link：[https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

## 递归 + 双指针

O(N)

BST的中序遍历的结果是一个不下降的序列。找到中间节点，左边小于的都是左子树，右边大于的都是右子树

> 这道题，和上一道题是一样的，只是对应的数据结构是链表。数组很容易找到中间的那个元素，链表如何找到中间节点，就成了最直接的问题

链表的中间节点，使用快慢指针。但要记住，**一定要把指针断开**

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        left, cur, right = self.splitLinkedList(head)
        
        root = None
        
        if cur is not None:
            root = TreeNode(cur.val)

            root.left = self.sortedListToBST(left)
            root.right = self.sortedListToBST(right)
                
        return root

    def splitLinkedList(self, head: ListNode) -> Tuple[ListNode, ListNode, ListNode]:
    
        if head is None:
            return (None, None, None)
    
        sentryHead = ListNode(0)
        sentryHead.next = head
        
        fast = sentryHead
        slow = sentryHead

        while fast.next is not None and fast.next.next is not None:
            fast = fast.next.next
            slow = slow.next
            
        cur = slow.next
        right = slow.next.next
        slow.next = None # 断开左右两部分
        
        return (sentryHead.next, cur, right)
```

--End--


