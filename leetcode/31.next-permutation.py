#
# @lc app=leetcode id=31 lang=python
#
# [31] Next Permutation
#
# https://leetcode.com/problems/next-permutation/description/
#
# algorithms
# Medium (29.56%)
# Total Accepted:    209.3K
# Total Submissions: 698.7K
# Testcase Example:  '[1,2,3]'
#
# Implement next permutation, which rearranges numbers into the
# lexicographically(字典顺序) next greater permutation of numbers.
# 
# If such arrangement is not possible, it must rearrange it as the lowest
# possible order (ie, sorted in ascending order).
# 
# The replacement must be in-place and use only constant extra memory.
# 
# Here are some examples. Inputs are in the left-hand column and its
# corresponding outputs are in the right-hand column.
# 
# 1,2,3 → 1,3,2
# 3,2,1 → 1,2,3
# 1,1,5 → 1,5,1
# 
#

# O(N)
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        start = len(nums) - 2
        while start >= 0:
            if nums[start] < nums[start + 1]:
                break
            start -= 1

        if start < 0:
            self.reverse(nums, 0, len(nums) - 1)
        else:
            bigger = 0
            for i in range(start + 1, len(nums)):
                if nums[start] >= nums[i]:
                    break
                    
                bigger = i

            nums[start], nums[bigger] = nums[bigger], nums[start]
            self.reverse(nums, start + 1, len(nums) - 1)
    
    def reverse(self, nums: List[int], start: int, end: int) -> None:
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1

# Q: 在所有由nums元素组成的数种，求比当前顺序排列大的最小组合
# A: [1, 2, 7, 4, 3, 1] -> [1,3,1,2,4,7]
# 从后往前起，找到第一组生序(2, 7), 记录2的位置i
# 从后往前起，找到第一个比i大的数字3记录j
# 交换i，j的位置后，i之后的数字仍然为降序
# 反转i之后的元素
