---
layout: post
index: 117
title: "LeetCode-117.填充每个节点的下一个右侧节点指针 II(Populating Next Right Pointers in Each Node II)"
categories: Leetcode
tags: Leetcode Tree DFS
excerpt: "平凡之路"
---

* content
{:toc}

## 117. 填充每个节点的下一个右侧节点指针 II

给定一个二叉树

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

填充它的每个**next**指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将**next**指针设置为**NULL**。

初始状态下，所有**next**指针都被设置为**NULL**。

进阶：

```
你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
```

示例：

![图片说明](./images/leetcode-algorithm-117.jpg)

```
输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
```

提示：

```
树中的节点数小于 6000
-100 <= node.val <= 100
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/)

Link：[https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

## 宽度优先搜索

O(N)

### 使用队列

上一题的代码可以原封不动地放在这里，哈哈~

```python
from collections import deque
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        if root is None:
            return None
        
        queue = deque([root])
        
        while len(queue) > 0:
            count = len(queue)
            
            for i in range(count):
                cur = queue.popleft()
                
                if i + 1 < count:
                    cur.next = queue[0]
                    
                if cur.left is not None:
                    queue.append(cur.left)
                    
                if cur.right is not None:
                    queue.append(cur.right)
                    
        return root
```

### 不使用队列

需要一个哨兵头节点，不然代码写起来太麻烦了

有了头节点，每一排当作链表链接起来

结尾记得把头节点拆掉

```python
class Solution:
    def connect(self, root: 'Node') -> 'Node':
                
        node = root
        head = Node()
        while node is not None:

            cur = head
            while node is not None:
                if node.left is not None:
                    cur.next = node.left
                    cur = cur.next
                
                if node.right is not None:
                    cur.next = node.right
                    cur = cur.next

                node = node.next

            node = head.next
            head.next = None
            
        return root
```

单词循环代码

```python
class Solution:
    def connect(self, root: 'Node') -> 'Node':
                
        node = root
        cur = head = Node()
        while node is not None:

            if node.left is not None:
                cur.next = node.left
                cur = cur.next

            if node.right is not None:
                cur.next = node.right
                cur = cur.next

            node = node.next

            if node is None:
                cur = head
                node = head.next
                head.next = None
                
        return root
```

--End--


