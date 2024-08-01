#  Tag: String, Stack
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#  An input string is valid if:
#  
#  Open brackets must be closed by the same type of brackets.
#  Open brackets must be closed in the correct order.
#  Every close bracket has a corresponding open bracket of the same type.
#  
#   
#  Example 1:
#  
#  Input: s = "()"
#  Output: true
#  
#  Example 2:
#  
#  Input: s = "()[]{}"
#  Output: true
#  
#  Example 3:
#  
#  Input: s = "(]"
#  Output: false
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 104
#  s consists of parentheses only '()[]{}'.
#  
#  

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        p = {
            '(' : ')',
            '{' : '}',
            '[' : ']',
        }

        for ch in s:
            if ch in p:
                stack.append(p[ch])
            else:
                if len(stack) > 0 and ch == stack[-1]:
                    stack.pop()
                else:
                    return False
                    
        return len(stack) == 0 
