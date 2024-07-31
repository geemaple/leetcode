---
layout: post
index: 27
title: "LeetCode-27.移除元素(Remove Element)"
categories: Leetcode
tags: Leetcode Array TwoPointers
excerpt: "黑灰白"
---

* content
{:toc}

## 27. Remove Element

给一个数组nums和一个值val，要求"原地"移除所有数值等于 val 的元素，并返回移除后数组的新长度。

要求只使用O(1)的额外空间，元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:

```
给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

```

示例 2:

```
给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。
```

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

```
// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/remove-element/](https://leetcode-cn.com/problems/remove-element/)

Link：[https://leetcode.com/problems/remove-element/](https://leetcode.com/problems/remove-element/)

## 双指针

O(N)

相向双指针

左指针start用来保存有效结果, 所以只有```nums[start] != val```时, start才加1

右指针end用来做交换，每交换一次，end向左移动一位

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        start = 0
        end = len(nums) - 1
        
        while start <= end:
            
            if nums[start] == val:
                nums[start], nums[end] = nums[end], nums[start]
                end -= 1
            else:
                start += 1
        
        return start
```

同向双指针

慢指针slow用来保存有效结果

快指针fast用来快速扫描

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        slow = 0
        for fast in range(len(nums)):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
        
        return slow
```

--End--


