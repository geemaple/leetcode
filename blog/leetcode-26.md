---
layout: post
index: 26
title: "LeetCode-26.删除排序数组中的重复项(Remove Duplicates from Sorted Array)"
categories: Leetcode
tags: Leetcode Array TwoPointers
excerpt: "Kali"
---

* content
{:toc}

## 26. 删除排序数组中的重复项

给一个排序数组，你需要"原地"删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

你必须在"原地"修改输入数组，且要求空间复杂度为O(1)

示例 1:

```
数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组nums的前两个元素被修改为 1, 2。 

```

示例 2:

```
数组 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
```

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

```
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

Link：[https://leetcode.com/problems/remove-duplicates-from-sorted-array/](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

## 双指针

O(N)

使用的是同向双指针，一快一慢

slow慢指针用来保存结果。

fast快指针用来寻找合适的候选。

```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        slow = fast = 0
        while fast < len(nums):
                        
            while fast + 1 < len(nums) and nums[fast] == nums[fast + 1]:
                fast += 1
            
            if nums[slow] < nums[fast]:
                nums[slow], nums[fast] = nums[fast], nums[slow]
            
            slow += 1
            fast += 1
            
        return slow
```

思路一致，但是更简短的代码:

```python
class Solution(object):
    def removeDuplicates(self, nums: List[int]) -> int:        
        i = 0
        for j in range(len(nums)):
            if (i == 0 or nums[i - 1] < nums[j]):
                nums[i] = nums[j]
                i += 1

        return i
```

--End--


