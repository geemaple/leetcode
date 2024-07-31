---
layout: post
index: 9
title: "LeetCode-9.回文数(Palindrome Number)"
categories: Leetcode
tags: Leetcode Math
excerpt: "?Borrow or rob?"
---

* content
{:toc}

## 9. 回文数

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

```
输入: 121
输出: true
```

示例 2:

```
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
```

示例 3:

```
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
```

进阶: 你能不将整数转为字符串来解决这个问题吗？

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/palindrome-number/](https://leetcode-cn.com/problems/palindrome-number/)

Link：[https://leetcode.com/problems/palindrome-number/](https://leetcode.com/problems/palindrome-number/)

## 模拟法

O(N)

负数一定不是， 其他情况如果将数字逆序，得到的数字和原来相等，那么就是一个回文

### 没有32位限制

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        
        mirror = 0
        num = x
        
        while(num > 0):
            digit = num % 10
            num = num // 10
            
            mirror = mirror * 10 + digit
            
        return mirror == x
```

### 有32位限制

负数一定不是，结尾为0的大于0的数也一定不是

而且，可以只转换一半的数字，这样可以避免数字转换溢出，然后判断左右两边的数是否相等

```
# 奇数情况
78987
7898 -> 7
789 -> 78
78 -> 789

# 偶数情况
789987
78998 -> 7
7899 -> 78
789 -> 789
```

cpp代码如下：

```cpp

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        
        int left = x;
        int right = 0;
        while (right < left) {
            right = right * 10 + left % 10;
            left = left / 10;
        }
            
        return (left == right || left == right / 10);
        
    }
};

```

--End--


