import heapq
class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.leftHeap = []
        self.rightHeap = []
        

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        if len(self.leftHeap) <= len(self.rightHeap):
            heapq.heappush(self.leftHeap, -num)
        else:
            heapq.heappush(self.rightHeap, num)
        
        if len(self.rightHeap) > 0:
            left = -self.leftHeap[0]
            right = self.rightHeap[0]
            
            if left > right:
                heapq.heappop(self.leftHeap)
                heapq.heappop(self.rightHeap)
                
                heapq.heappush(self.leftHeap, -right)
                heapq.heappush(self.rightHeap, left)

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.leftHeap) > len(self.rightHeap):
            return -self.leftHeap[0]
        else:
            return (-self.leftHeap[0] + self.rightHeap[0]) / 2.0
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()