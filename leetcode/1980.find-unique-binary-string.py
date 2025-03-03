#  Tag: Array, Hash Table, String, Backtracking
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/B7Nl-Lb76JU

#  Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
#   
#  Example 1:
#  
#  Input: nums = ["01","10"]
#  Output: "11"
#  Explanation: "11" does not appear in nums. "00" would also be correct.
#  
#  Example 2:
#  
#  Input: nums = ["00","01"]
#  Output: "11"
#  Explanation: "11" does not appear in nums. "10" would also be correct.
#  
#  Example 3:
#  
#  Input: nums = ["111","011","001"]
#  Output: "101"
#  Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
#  
#   
#  Constraints:
#  
#  n == nums.length
#  1 <= n <= 16
#  nums[i].length == n
#  nums[i] is either '0' or '1'.
#  All the strings of nums are unique.
#  
#  

class Solution(object):
    def findDifferentBinaryString(self, nums):
        result = ""
        for i in range(len(nums)):
            result += '1' if nums[i][i] == '0' else '0'

        return result

class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        table = set(nums)
        n = len(nums[0])
        self.res = None
        self.helper(table, '', 0, n)
        return self.res

    def helper(self, table: set, tmp: str, i: int, n: int) -> bool:
        if i == n:
            self.res = tmp
            return tmp not in table

        for ch in '01':
            if self.helper(table, tmp + ch, i + 1, n):
                return True

        return False
