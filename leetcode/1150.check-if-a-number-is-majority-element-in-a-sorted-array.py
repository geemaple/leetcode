#
# @lc app=leetcode id=1150 lang=python
#
# [1150] Check If a Number Is Majority Element in a Sorted Array
#
# https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/description/
#
# algorithms
# Easy (59.97%)
# Total Accepted:    10.1K
# Total Submissions: 16.9K
# Testcase Example:  '[2,4,5,5,5,5,5,6,6]\n5'
#
# Given an array nums sorted in non-decreasing order, and a number target,
# return True if and only if target is a majority element.
# 
# A majority element is an element that appears more than N/2 times in an array
# of length N.
# 
# 
# 
# Example 1:
# 
# 
# Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
# Output: true
# Explanation: 
# The value 5 appears 5 times and the length of the array is 9.
# Thus, 5 is a majority element because 5 > 9/2 is true.
# 
# 
# Example 2:
# 
# 
# Input: nums = [10,100,101,101], target = 101
# Output: false
# Explanation: 
# The value 101 appears 2 times and the length of the array is 4.
# Thus, 101 is not a majority element because 2 > 4/2 is false.
# 
# 
# 
# 
# Note:
# 
# 
# 1 <= nums.length <= 1000
# 1 <= nums[i] <= 10^9
# 1 <= target <= 10^9
# 
# 
#
# O(logN) but faster than Solution2
class Solution(object):
    def isMajorityElement(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        
        head = self.headOfElement(nums, target) #O(logN)
        tail = len(nums) // 2 + head #O(1)
        
        return head >= 0 and tail < len(nums) and nums[tail] == target #O(1)
        
        
    def headOfElement(self, nums, target):
        
        start = 0
        end = len(nums) - 1
        
        while (start + 1 < end):
            mid = start + (end - start) // 2
            
            if nums[mid] == target:
                end = mid
            elif nums[mid] > target:
                end = mid
            else:
                start = mid
                
        if nums[start] == target:
            return start
        
        if nums[end] == target:
            return end
        
        return -1

# O(logN)
class Solution2(object):
    def isMajorityElement(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        
        tail = self.tailOfElement(nums, target) #O(logN)
        head = self.headOfElement(nums, target) #O(logN)
        
        return head >= 0 and (tail - head + 1) > len(nums) // 2 #O(1)
        
        
    def headOfElement(self, nums, target):
        
        start = 0
        end = len(nums) - 1
        
        while (start + 1 < end):
            mid = start + (end - start) // 2
            
            if nums[mid] == target:
                end = mid
            elif nums[mid] > target:
                end = mid
            else:
                start = mid
                
        if nums[start] == target:
            return start
        
        if nums[end] == target:
            return end
        
        return -1
    
    def tailOfElement(self, nums, target):
        
        start = 0
        end = len(nums) - 1
        
        while (start + 1 < end):
            mid = start + (end - start) // 2
            
            if nums[mid] == target:
                start = mid
            elif nums[mid] > target:
                end = mid
            else:
                start = mid
                
        if nums[end] == target:
            return end
        
        if nums[start] == target:
            return start
        
        return -1