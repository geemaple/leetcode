#  Tag: Math, Backtracking
#  Time: O(N * 2^K)
#  Space: O(K)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/bLgWWGhaweM

#  Given a positive integer n, return the punishment number of n.
#  The punishment number of n is defined as the sum of the squares of all integers i such that:
#  
#  1 <= i <= n
#  The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.
#  
#   
#  Example 1:
#  
#  Input: n = 10
#  Output: 182
#  Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
#  - 1 since 1 * 1 = 1
#  - 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
#  - 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
#  Hence, the punishment number of 10 is 1 + 81 + 100 = 182
#  
#  Example 2:
#  
#  Input: n = 37
#  Output: 1478
#  Explanation: There are exactly 4 integers i in the range [1, 37] that satisfy the conditions in the statement:
#  - 1 since 1 * 1 = 1. 
#  - 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1. 
#  - 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0. 
#  - 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
#  Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478
#  
#   
#  Constraints:
#  
#  1 <= n <= 1000
#  
#  

class Solution:
    def punishmentNumber(self, n: int) -> int:
        res = 0
        for i in range(1, n + 1):
            if self.canPartition(str(i * i), 0, 0, i):
                res += i * i

        return res

    def canPartition(self, s: string, cur_sum: int, index: int, target: int) -> bool:
        if index == len(s):
            return cur_sum == target

        num = 0
        for i in range(index, len(s)):
            num = num * 10 + int(s[i])
            if cur_sum + num > target:
                break

            if self.canPartition(s, cur_sum + num, i + 1, target):
                return True
        return False
        
class Solution:
    def punishmentNumber(self, n: int) -> int:
        punishment_sum = 0
        for k in range(1, n + 1):
            k_squared = k * k
            if self.can_partition(k_squared, k, 0):
                punishment_sum += k_squared
        return punishment_sum

    def can_partition(self, num: int, target: int, cur_sum: int) -> bool:
        if num == 0:
            return cur_sum == target
        
        base = 1
        while num >= base:
            part = num % (base * 10)  # 取出最低的几位数
            if cur_sum + part > target:
                break
            if self.can_partition(num // (base * 10), target, cur_sum + part):
                return True
            base *= 10  # 继续尝试更长的前缀
        return False