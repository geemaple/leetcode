class Solution(object):
    def decodeString(self, s):
        """
            :type s: str
            :rtype: str
            """
        stack = []
        
        for c in s:
            if c != ']':
                stack.append(c)
            else:
                chunk = ''
                while(stack[-1] != '['):
                    chunk = stack.pop() + chunk
                
                stack.pop()
                
                base = 1
                count = 0
                while(len(stack) > 0 and stack[-1].isdigit()):
                    count += base * int(stack.pop())
                    base *= 10
                
                
                for i in range(count):
                    for j in range(len(chunk)):
                        stack.append(chunk[j])

    return ''.join(stack)

