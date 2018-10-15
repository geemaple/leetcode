class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.container = []
        self.minstack = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.container.append(x)
        cur_min = x
        if len(self.minstack) > 0:
            cur_min = min(cur_min, self.minstack[-1])
        self.minstack.append(cur_min)
        

    def pop(self):
        """
        :rtype: void
        """
        self.container.pop()
        self.minstack.pop()
        
    def top(self):
        """
        :rtype: int
        """
        return self.container[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.minstack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()