class Solution:
    def isValid(self, s: str) -> bool:
        
        mapping = {
            ')': '(',
            '}': '{',
            ']': '[',
        }
        
        stack = []
        
        for i in range(len(s)):
            
            if s[i] not in mapping:
                stack.append(s[i])
                continue
                
            if len(stack) > 0 and stack[-1] == mapping[s[i]]:
                stack.pop()
            else:
                return False
        
        return len(stack) == 0