---
layout: post
index: 190
title: "LeetCode-190.颠倒二进制位(Reverse Bits)"
categories: Leetcode
tags: Leetcode BitManipulation
excerpt: ""
---

* content
{:toc}

## 190. 颠倒二进制位

颠倒给定的 32 位无符号整数的二进制位。

示例 1：

```
输入: 00000010100101000001111010011100
输出: 00111001011110000010100101000000
解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
     因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
```

示例 2：

```
输入：11111111111111111111111111111101
输出：10111111111111111111111111111111
解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
     因此返回 3221225471 其二进制表示形式为 10111111111111111111111111111111 。
```
 
提示：

```
请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在上面的 示例 2 中，输入表示有符号整数 -3，输出表示有符号整数 -1073741825。
```
 
进阶:

```
如果多次调用这个函数，你将如何优化你的算法？
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/reverse-bits/](https://leetcode-cn.com/problems/reverse-bits/)

Link：[https://leetcode.com/problems/reverse-bits/](https://leetcode.com/problems/reverse-bits/)

## 二进制

O(1), 执行次数 = 32次

每次拿到最后一位之后，原数字右移。然后把最后一位放入结果，做移动。

```python
class Solution:
    def reverseBits(self, n: int) -> int:
        
        res = 0
        for _ in range(32):
            
            res = res << 1
            if n & 1 == 1:
                res = res ^ 1
            
            n = n >> 1
            
        return res
```

加法(+1)也是可以搞定的

```python
class Solution:
    def reverseBits(self, n: int) -> int:
        
        res = 0
        for _ in range(32):
            res = res << 1
            res += (n & 1)
            n = n >> 1
            
        return res
```

## One More Thing

O(1), 执行次数log32 = 5次

关于如何优化，有人说加上缓存，理论上速度会更快, 但实际有人测试速度反而更慢, 远不如以下的代码:

以下可以说是分治的思想, 部分左右互换, 以8进制为例子:

```python

'a b c d'  e f g h

e f g h   'a b c d'
      
        ||
          
e f 'g h'   a b 'c d'
   
'g h' e f   'c d' a b

             ||

'g' h   'e' f   'c' d   'a' b

h 'g'   f 'e'   d 'c'   b 'a'
```

掩码表格, 取反会是个负数，所以用0xffffffff作为掩码:

```python
0xffff0000 = 0b11111111111111110000000000000000 = ~0x0000ffff & 0xffffffff
0x0000ffff = 0b00000000000000001111111111111111

0xff00ff00 = 0b11111111000000001111111100000000 = ~0x00ff00ff & 0xffffffff
0x00ff00ff = 0b00000000111111110000000011111111

0xf0f0f0f0 = 0b11110000111100001111000011110000 = ~0x0f0f0f0f & 0xffffffff
0x0f0f0f0f = 0b00001111000011110000111100001111

0xcccccccc = 0b11001100110011001100110011001100 = ~0x33333333 & 0xffffffff
0x33333333 = 0b00110011001100110011001100110011

0xaaaaaaaa = 0b10101010101010101010101010101010 = ~0x55555555 & 0xffffffff
0x55555555 = 0b01010101010101010101010101010101
```

实现代码，自顶向下

```python
class Solution:
    def reverseBits(self, n: int) -> int:

        res = n
        res = (res >> 16) | (res << 16)
        res= (res & 0xff00ff00) >> 8 | (res & 0x00ff00ff) << 8
        res= (res & 0xf0f0f0f0) >> 4 | (res & 0x0f0f0f0f) << 4
        res= (res & 0xcccccccc) >> 2 | (res & 0x33333333) << 2
        res= (res & 0xaaaaaaaa) >> 1 | (res & 0x55555555) << 1
        return res
```

以下为Java源码实现, 自底向上:

```java
 645:   http://developer.classpath.org/doc/java/lang/Integer-source.html
 646:   /**
 647:    * Reverse the bits in val.
 648:    * @since 1.5
 649:    */
 650:   public static int reverse(int val)
 651:   {
 652:     // Successively swap alternating bit groups.
 653:     val = ((val >> 1) & 0x55555555) + ((val << 1) & ~0x55555555);
 654:     val = ((val >> 2) & 0x33333333) + ((val << 2) & ~0x33333333);
 655:     val = ((val >> 4) & 0x0f0f0f0f) + ((val << 4) & ~0x0f0f0f0f);
 656:     val = ((val >> 8) & 0x00ff00ff) + ((val << 8) & ~0x00ff00ff);
 657:     return ((val >> 16) & 0x0000ffff) + ((val << 16) & ~0x0000ffff);
 658:   }
```

--End--


