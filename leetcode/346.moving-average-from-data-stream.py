class MovingAverage(object):

    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.size = size
        self.id = 0
        self.presum = [0] * (size + 1)
        

    def mode(self, index):
        return index % (self.size + 1)

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        self.id += 1
        self.presum[self.mode(self.id)] = self.presum[self.mode(self.id - 1)] + val
        if (self.id <= self.size):
            return float(self.presum[self.mode(self.id)]) / self.id
        else:
            return float(self.presum[self.mode(self.id)] - self.presum[self.mode(self.id - self.size)]) / self.size



# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
