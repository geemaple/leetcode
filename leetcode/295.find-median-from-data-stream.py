#  Tag: Two Pointers, Design, Sorting, Heap (Priority Queue), Data Stream
#  Time: O(logN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
#  
#  For example, for arr = [2,3,4], the median is 3.
#  For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
#  
#  Implement the MedianFinder class:
#  
#  MedianFinder() initializes the MedianFinder object.
#  void addNum(int num) adds the integer num from the data stream to the data structure.
#  double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
#  
#   
#  Example 1:
#  
#  Input
#  ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
#  [[], [1], [2], [], [3], []]
#  Output
#  [null, null, null, 1.5, null, 2.0]
#  
#  Explanation
#  MedianFinder medianFinder = new MedianFinder();
#  medianFinder.addNum(1);    // arr = [1]
#  medianFinder.addNum(2);    // arr = [1, 2]
#  medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
#  medianFinder.addNum(3);    // arr[1, 2, 3]
#  medianFinder.findMedian(); // return 2.0
#  
#   
#  Constraints:
#  
#  -105 <= num <= 105
#  There will be at least one element in the data structure before calling findMedian.
#  At most 5 * 104 calls will be made to addNum and findMedian.
#  
#   
#  Follow up:
#  
#  If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
#  If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
#  
#  

import heapq
class MedianFinder:

    def __init__(self):
        self.max_heap = []
        self.min_heap = []

    def addNum(self, num: int) -> None:
        if len(self.max_heap) > len(self.min_heap):
            heapq.heappush(self.min_heap, num)
        else:
            heapq.heappush(self.max_heap, -num)

        if len(self.min_heap) > 0:
            left = -self.max_heap[0]
            right = self.min_heap[0]
            if left > right:
                heapq.heappop(self.max_heap)
                heapq.heappop(self.min_heap)

                heapq.heappush(self.max_heap, -right)
                heapq.heappush(self.min_heap, left)

    def findMedian(self) -> float:
        if len(self.max_heap) > len(self.min_heap):
            return -self.max_heap[0]

        return (-self.max_heap[0] + self.min_heap[0]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()