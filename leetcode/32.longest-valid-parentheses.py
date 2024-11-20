#  Tag: String, Dynamic Programming, Stack
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
#   
#  Example 1:
#  
#  Input: s = "(()"
#  Output: 2
#  Explanation: The longest valid parentheses substring is "()".
#  
#  Example 2:
#  
#  Input: s = ")()())"
#  Output: 4
#  Explanation: The longest valid parentheses substring is "()()".
#  
#  Example 3:
#  
#  Input: s = ""
#  Output: 0
#  
#   
#  Constraints:
#  
#  0 <= s.length <= 3 * 104
#  s[i] is '(', or ')'.
#  
#  

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if len(s) == 0:
            return 0

        n = len(s)
        dp = [0 for i in range(n)]

        for i in range(1, n):
            if s[i] == ')':
                if s[i - 1] == '(':
                    dp[i] = dp[i - 2] + 2 if i - 2 >= 0 else 2
                else:
                    j = i - dp[i - 1] - 1
                    if j >= 0 and s[j] == '(':
                        dp[i] = dp[i - 1] + 2
                        if j >= 1:
                            dp[i] += dp[j - 1]

        return max(dp)

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        
        n = len(s)
        res = 0

        left = right = 0    
        for i in range(n):
            if s[i] == '(':
              left += 1
            else:
                right += 1

            if left == right:
                res = max(res, right * 2)
            elif right > left:
                left = right = 0

        left = right = 0   
        for i in range(n - 1, -1, -1):
            if s[i] == ')':
                right += 1
            else:
                left += 1

            if left == right:
                res = max(res, right * 2)
            elif left > right:
                left = right = 0

        return res
    
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        res = 0
        stack = [-1]
        
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if len(stack) == 0:
                    stack.append(i)
                
                res = max(res, i - stack[-1])
                    
        return res


                



        