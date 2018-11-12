class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        mapping = {')':'(', '}':'{', ']':'['}
        
        for l in s:
            if l not in mapping:
                stack.append(l)
            else:
                if len(stack) == 0 or stack[-1] != mapping[l]:
                    return False
                
                stack.pop()
                
        return len(stack) == 0
            