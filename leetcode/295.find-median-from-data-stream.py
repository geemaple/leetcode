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

        heapq.heappush(self.max_heap, -num)
        heapq.heappush(self.min_heap, -self.max_heap[0])
        heapq.heappop(self.max_heap)

        if len(self.max_heap) < len(self.min_heap):
            heapq.heappush(self.max_heap, -self.min_heap[0]);
            heapq.heappop(self.min_heap)

    def findMedian(self) -> float:
        if len(self.max_heap) > len(self.min_heap):
            return -self.max_heap[0]

        return (-self.max_heap[0] + self.min_heap[0]) / 2

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

# follow-up 1
class MedianFinder:
    def __init__(self):
        self.count = [0] * 101
        self.total = 0

    def addNum(self, num: int) -> None:
        self.count[num] += 1
        self.total += 1

    def findMedian(self) -> float:
        half = self.total // 2
        cumulative_count = 0
        first = second = -1

        for i in range(101):
            cumulative_count += self.count[i]

            if self.total % 2 == 1:
                if cumulative_count > half:
                    return float(i)
            else:
                if cumulative_count > half and first == -1:
                    first = i
                if cumulative_count > half + 1:
                    second = i
                    break

        if first != -1 and second != -1:
            return (first + second) / 2.0
        
# follow-up 2
import bisect

class MedianFinder:
    def __init__(self):
        self.count = [0] * 101
        self.low_outliers = []  # for numbers < 0
        self.high_outliers = []  # for numbers > 100
        self.total = 0

    def addNum(self, num: int) -> None:
        if 0 <= num <= 100:
            self.count[num] += 1
        elif num < 0:
            bisect.insort(self.low_outliers, num)  # Insert while keeping sorted
        else:  # num > 100
            bisect.insort(self.high_outliers, num)  # Insert while keeping sorted
        self.total += 1

    def findMedian(self) -> float:
        half = self.total // 2
        cumulative_count = 0

        if self.total % 2 == 1:  # Total is odd
            for i in range(101):
                cumulative_count += self.count[i]
                if cumulative_count > half:
                    return float(i)

            # Handle low outliers
            for outlier in self.low_outliers:
                cumulative_count += 1
                if cumulative_count > half:
                    return float(outlier)

            # Handle high outliers
            for outlier in self.high_outliers:
                cumulative_count += 1
                if cumulative_count > half:
                    return float(outlier)

        else:  # Total is even
            first = second = None

            for i in range(101):
                cumulative_count += self.count[i]
                if cumulative_count > half:
                    first = i
                    break
            
            if first is None:
                for outlier in self.low_outliers:
                    cumulative_count += 1
                    if cumulative_count > half:
                        first = outlier
                        break
            
            cumulative_count = 0
            for i in range(101):
                cumulative_count += self.count[i]
                if cumulative_count > half + 1:
                    second = i
                    break
            
            if second is None:
                for outlier in self.high_outliers:
                    cumulative_count += 1
                    if cumulative_count > half + 1:
                        second = outlier
                        break
            
            return (first + second) / 2.0
