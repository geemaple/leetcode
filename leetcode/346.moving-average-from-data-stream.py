from collections import deque
class MovingAverage(object):

    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.dq = deque()
        self.size = size
        self.sum = 0

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        self.dq.append(val)
        self.sum += val
        if len(self.dq) > self.size:
            self.sum -= self.dq.popleft()
            
        return float(self.sum) / len(self.dq)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)