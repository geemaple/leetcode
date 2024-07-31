---
layout: post
index: 80
title: "LeetCode-80.删除排序数组中的重复项 II(Remove Duplicates from Sorted Array II)"
categories: Leetcode
tags: Leetcode Array TwoPointers
excerpt: "烽火戏诸侯"
---

* content
{:toc}

## 80. 删除排序数组中的重复项 II

给你一个排序数组nums ，原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，须在原数组修改​，且额外空间复杂度O(1)。

说明：

为什么返回数值是整数，但输出的答案是数组呢？

```
请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下：

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

示例 1：

```
输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 你不需要考虑数组中超出新长度后面的元素。
```

示例 2：

```
输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。 你不需要考虑数组中超出新长度后面的元素。
```

提示：

```
0 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 按递增顺序排列
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii)

Link：[https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii)


## 双指针

O(N)

这里有个坑，如果用nums[i] == nums[i - 1]来做比较，那么由于交换，会影响比较的结果。

所以使用nums[i] == nums[j - 1]来做比较

```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j = 0
        count = 0
        for i in range(len(nums)):
            if j > 0 and nums[i] == nums[j - 1]:
                if count < 1:
                    nums[i], nums[j] = nums[j], nums[i]
                    count += 1
                    j += 1
            else:
                nums[i], nums[j] = nums[j], nums[i]
                count = 0
                j += 1
        
        return j
```


--End--
