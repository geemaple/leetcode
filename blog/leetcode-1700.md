---
layout: post
index: 1700
title: "LeetCode-1700.无法吃午餐的学生数量(Number of Students Unable to Eat Lunch)"
categories: Leetcode
tags: Leetcode Array
excerpt: "早安"
---

* content
{:toc}

## 1700. 无法吃午餐的学生数量

学校食堂的自助午餐提供**圆形**和**方形**两种三明治，分别用数字**0**和**1**表示。所有学生排成一排，每个学生要么喜欢圆形的要么喜欢方形的。
餐厅里三明治的数量**等于**学生的数量。所有三明治都放在一个**栈**里，每一轮：

如果队列最前面的学生**喜欢**栈顶的三明治，那么会拿走它并离开队列。

否则，最前面的学生会放弃这个三明治，并回到队列的尾部。

这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止。

给你两个整数数组 students 和 sandwiches ，其中 sandwiches[i] 是栈里面第**i​​​**​​​个三明治的类型（i = 0 是栈的顶部）， students[j] 是初始队列里第**j​​​​​​**名学生对三明治的喜好（j = 0 是队列的最开始位置）。请你返回无法吃午餐的学生数量。

示例 1：

```
输入：students = [1,1,0,0], sandwiches = [0,1,0,1]
输出：0 
```

示例 2：

```
输入：students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
输出：3
```

提示：

```
1 <= students.length, sandwiches.length <= 100
students.length == sandwiches.length
sandwiches[i] 要么是 0 ，要么是 1 。
students[i] 要么是 0 ，要么是 1 。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/number-of-students-unable-to-eat-lunch](https://leetcode-cn.com/problems/number-of-students-unable-to-eat-lunch)

Link：[https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/)


## 模拟

O(N ^ 2)

学生是不断循环排队的，所以只要拿出当前的三明治🥪，看看有没有学生拿走即可

```python
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        
        for s in sandwiches:
            if s in students:
                students.remove(s)
            else:
                break

        return len(students)
```

## 预处理优化

首先，统计下学生们的偏好，记录下各需要多少种

```python
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        prefer = [0, 0]
        for s in students:
            prefer[s] += 1
            
        sold = 0
        for s in sandwiches:
            if prefer[s] > 0:
                sold += 1
                prefer[s] -= 1
            else:
                break
                
        return len(sandwiches) - sold
```

--End--


