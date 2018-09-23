class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        stack = []
        pairs = {')': '(', '}': '{', ']': '['}

        for c in s:
            if c in pairs:
                if len(stack) == 0:
                    return False

                candidate = stack.pop()
                if pairs[c] != candidate:
                    return False
            else:
                stack.append(c)

        return len(stack) == 0