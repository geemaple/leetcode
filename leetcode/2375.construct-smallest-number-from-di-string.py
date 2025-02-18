#  Tag: String, Backtracking, Stack, Greedy
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/P8i_9XLrj3w

#  You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.
#  A 0-indexed string num of length n + 1 is created using the following conditions:
#  
#  num consists of the digits '1' to '9', where each digit is used at most once.
#  If pattern[i] == 'I', then num[i] < num[i + 1].
#  If pattern[i] == 'D', then num[i] > num[i + 1].
#  
#  Return the lexicographically smallest possible string num that meets the conditions.
#   
#  Example 1:
#  
#  Input: pattern = "IIIDIDDD"
#  Output: "123549876"
#  Explanation:
#  At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
#  At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
#  Some possible values of num are "245639871", "135749862", and "123849765".
#  It can be proven that "123549876" is the smallest possible num that meets the conditions.
#  Note that "123414321" is not possible because the digit '1' is used more than once.
#  Example 2:
#  
#  Input: pattern = "DDD"
#  Output: "4321"
#  Explanation:
#  Some possible values of num are "9876", "7321", and "8742".
#  It can be proven that "4321" is the smallest possible num that meets the conditions.
#  
#   
#  Constraints:
#  
#  1 <= pattern.length <= 8
#  pattern consists of only the letters 'I' and 'D'.
#  
#  

class Solution:
    def smallestNumber(self, pattern: str) -> str:
        n = len(pattern)
        res = [0] * (n + 1)
        used = [False] * 10
        self.helper(pattern, used, res, 0)
        return ''.join([str(x) for x in res])

    def helper(self, pattern: str, used: list, res: list, i: int) -> bool:
        if i == len(res):
            return True

        for num in range(1, 10):
            if used[num]:
                continue

            if (i == 0) or \
                (pattern[i - 1] == 'I' and num > res[i - 1]) or \
                (pattern[i - 1] == 'D' and num < res[i - 1]):

                used[num] = True
                res[i] = num
                if self.helper(pattern, used, res, i + 1):
                    return True
                res[i] = 0
                used[num] = False

        return False
    
class Solution:
    def smallestNumber(self, pattern: str) -> str:
        n = len(pattern)
        stack = []
        res = []
        for i in range(0, n + 1):
            stack.append(str(i + 1))
            if i == n or pattern[i] == 'I': 
                res += stack[::-1]
                stack = []
        return ''.join(res)