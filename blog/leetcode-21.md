---
layout: post
index: 21
title: "LeetCode-21.合并两个有序链表(Merge Two Sorted Lists)"
categories: Leetcode
tags: Leetcode LinkedList
excerpt: "第一个回复"
---

* content
{:toc}
## 21. Merge Two Sorted Lists

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/merge-two-sorted-lists/](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

Link：[https://leetcode.com/problems/merge-two-sorted-lists/](https://leetcode.com/problems/merge-two-sorted-lists/)

## 双指针

O(N)

比较两个链表头，把小的拿出来放到新的链表中

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur = head = ListNode()
        
        while(l1 is not None and l2 is not None):
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
                
            cur = cur.next
            
        cur.next = l1 if l1 is not None else l2
            
        return head.next
```

可以将链表想像成无穷多个，结尾以无穷大结束

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur = head = ListNode()
        
        while(l1 is not None or l2 is not None):
            
            l1_val = l1.val if l1 is not None else float('inf') 
            l2_val = l2.val if l2 is not None else float('inf') 
            
            if l1_val <= l2_val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
                
            cur = cur.next
            
        return head.next
```

## [17. 电话号码的字母组合(Letter Combinations of a Phone Number)](http://geemaple.github.io/2020/07/24/leetcode-17/)

> 感谢知乎用户(@一个小老虎)的评论反馈

递归有栈溢出的风险, 如果不用递归, 那该怎么实现？

排列组合还可以用队列Queue实现，而且还能够处理动态输入的情况

以'23'为例, 初始化队列包含空字符

```
['']
```

先输入2, 将2对应的字母'abc'分别拼接上队列中长度等于0的, 也就是空字符''

```
['a', 'b', 'c']
```

在输入3， 将3对应的字母'def'分别拼接上队列中长度等于1的, 也就是字母'a','b'和'c'

```
['b', 'c', 'ad', 'ae', 'af']
['c', 'ad', 'ae', 'af', 'bd', 'be', 'bf']
['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']
```

代码如下：

```python
from collections import deque
class Solution:    
    def letterCombinations(self, digits: str) -> List[str]:    
        
        if len(digits) == 0:
            return []
        
        digitToLetter = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
        }
        
        ans = deque()
        ans.append('')
        
        for i in range(len(digits)):
            num = digits[i]
            while len(ans) > 0 and len(ans[0]) == i: 
                prefix = ans.popleft()
                for letter in digitToLetter[num]:
                    ans.append(prefix + letter)
                    
        return list(ans)
```

--End--


