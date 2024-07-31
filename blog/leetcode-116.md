---
layout: post
index: 116
title: "LeetCode-116.填充每个节点的下一个右侧节点指针(Populating Next Right Pointers in Each Node)"
categories: Leetcode
tags: Leetcode Tree DFS BFS
excerpt: "青春有你"
---

* content
{:toc}

## 116. 填充每个节点的下一个右侧节点指针

给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

示例：

![图片说明](./images/leetcode-algorithm-116.jpg)

```
输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
```

提示：

```
树中节点的数量少于 4096
-1000 <= node.val <= 1000
```

进阶：

你只能使用常量级额外空间。

使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node)

Link：[https://leetcode.com/problems/populating-next-right-pointers-in-each-node/](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

## 宽度优先搜索

O(N)

### 使用队列

用队列记录每一层，把该层指针指向后一个就可以了

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

```python
  node
  /  \
left right
```

一个节点node的左右很容易把left.next = right

```python
  node1    ----->    node2
  /  \                /  \
left right ----->   left right

       ^              ^
```

跨节点的时候, 上一层是已经链接好的

node1.right.next = node2.next.left, 然后只关注node2节点后面的部分

cur始终指向一层的第一个节点，level用来做层级操作

```python
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        if root is None:
            return None
        
        cur = root
        
        while cur.left is not None:

            next_level = cur.left

            while cur is not None:
                cur.left.next = cur.right
                if cur.next is not None:
                    cur.right.next = cur.next.left
                cur = cur.next
                
            cur = next_level
            
        return root
```

### 深度优先搜索

O(N)

```python
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        self.helper(root)
        return root
        
    def helper(self, node: 'Node'):
        if node is None:
            return None
        
        if node.left is not None:
            node.left.next = node.right
        
        if node.right is not None and node.next is not None:
            node.right.next = node.next.left
            
        self.helper(node.left)
        self.helper(node.right)
```

--End--


