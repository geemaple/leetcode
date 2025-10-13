#  Tag: Array, Hash Table, Two Pointers, Binary Search, Dynamic Programming, Sorting, Counting
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/mKT1UAcPglw

#  A magician has various spells.
#  You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.
#  It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.
#  Each spell can be cast only once.
#  Return the maximum possible total damage that a magician can cast.
#   
#  Example 1:
#  
#  Input: power = [1,1,3,4]
#  Output: 6
#  Explanation:
#  The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.
#  
#  Example 2:
#  
#  Input: power = [7,1,6,6]
#  Output: 13
#  Explanation:
#  The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with damage 1, 6, 6.
#  
#   
#  Constraints:
#  
#  1 <= power.length <= 105
#  1 <= power[i] <= 109
#  
#  

class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        n = len(power)
        power.sort()
        dp = [0 for i in range(n)]
        dp[0] = power[0]

        max_dp = 0
        res = dp[0]
        j = 0
        for i in range(1, n):
            if power[i] == power[i - 1]:
                dp[i] = power[i] + dp[i - 1]
            else:
                while power[j] + 2 < power[i]:
                    max_dp = max(max_dp, dp[j])
                    j += 1

                dp[i] = power[i] + max_dp

            res = max(res, dp[i])

        return res