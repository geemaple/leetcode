#
# @lc app=leetcode id=278 lang=python
#
# [278] First Bad Version
#
# https://leetcode.com/problems/first-bad-version/description/
#
# algorithms
# Easy (33.03%)
# Total Accepted:    311.8K
# Total Submissions: 932.3K
# Testcase Example:  '5\n4'
#
# You are a product manager and currently leading a team to develop a new
# product. Unfortunately, the latest version of your product fails the quality
# check. Since each version is developed based on the previous version, all the
# versions after a bad version are also bad.
# 
# Suppose you have n versions [1, 2, ..., n] and you want to find out the first
# bad one, which causes all the following ones to be bad.
# 
# You are given an API bool isBadVersion(version) which will return whether
# version is bad. Implement a function to find the first bad version. You
# should minimize the number of calls to the API.
# 
# Example:
# 
# 
# Given n = 5, and version = 4 is the first bad version.
# 
# call isBadVersion(3) -> false
# call isBadVersion(5) -> true
# call isBadVersion(4) -> true
# 
# Then 4 is the first bad version. 
# 
# 
#
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

# start + 1 < end, 最终剩余2个, 结束要start，end各判断一遍
class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        start = 0
        end = n
        while (start + 1 < end):
            mid = start + (end - start) / 2

            if isBadVersion(mid):
                end = mid
            else:
                start = mid

        return start if isBadVersion(start) else end

# start < end mid值偏左，所以start要加1
class Solution2(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        start = 1
        end = n

        while (start < end):
            mid = (end - start) // 2 + start

            if isBadVersion(mid):
                end = mid
            else:
                start = mid + 1

        return start