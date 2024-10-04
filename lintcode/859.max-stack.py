#  Tag: Stack
#  Time: -
#  Space: O(N)
#  Ref: Leetcode-716
#  Note: -

#  Design a max stack that supports push, pop, top, peekMax and popMax.
#  
#  1.
#  push(x) -- Push element x onto stack.
#  2.
#  pop() -- Remove the element on top of the stack and return it.
#  3.
#  top() -- Get the element on the top.
#  4.
#  peekMax() -- Retrieve the maximum element in the stack.
#  5.
#  popMax() -- Retrieve the maximum element in the stack, and remove it.
#  If you find more than one maximum elements, only remove the top-most one.
#  
#  ---
#  *
#  
#  ```
#  Input:
#  push(5)
#  push(1)
#  push(5)
#  top()
#  popMax()
#  top()
#  peekMax()
#  pop()
#  top()
#  Output:
#  5
#  5
#  1
#  5
#  1
#  5
#  ```
#  
#  1. `-1e7 <= x <= 1e7`
#  2. Number of operations won't exceed `10000`.
#  3. The last four operations won't be called when stack is empty.

class MaxStack:
    
    def __init__(self):
        # do intialization if necessary
        self.stack = []
        self.max_stack = []
    
    """
    @param: number: An integer
    @return: nothing
    """
    def push(self, x):
        # write your code here
        max_val = x if len(self.max_stack) == 0 else self.max_stack[-1]
        self.stack.append(x)
        self.max_stack.append(max_val if max_val > x else x)

    """
    @return: An integer
    """
    def pop(self):
        # write your code here
        if len(self.stack) > 0:
            self.max_stack.pop()
            return self.stack.pop()

    """
    @return: An integer
    """
    def top(self):
        # write your code here
        if len(self.stack) > 0:
            return self.stack[-1]
    """
    @return: An integer
    """
    def peekMax(self):
        # write your code here
        if len(self.max_stack) > 0:
            return self.max_stack[-1]
    """
    @return: An integer
    """
    def popMax(self):
        # write your code here
        if len(self.max_stack) > 0:
            max_val = self.max_stack[-1]
            
            tmp = []
            while self.top() != max_val:
                tmp.append(self.pop())
                
            self.pop()

            while len(tmp) > 0:
                self.push(tmp.pop())

            return max_val

