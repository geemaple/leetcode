import heapq
class Solution:
    """
    @param nums: A list of integers
    @return: the median of numbers
    """

    def medianII(self, nums):
        # write your code here

        minHeap = []
        maxHeap = []

        results = []
        for n in nums:
            if len(maxHeap) <= len(minHeap):
                heapq.heappush(maxHeap, -n)
            else:
                heapq.heappush(minHeap, n)

            if len(minHeap) > 0:
                left = -maxHeap[0]
                right = minHeap[0]

                if left > right:
                    # exchange left and right
                    heapq.heappop(maxHeap)
                    heapq.heappush(maxHeap, -right)

                    heapq.heappop(minHeap)
                    heapq.heappush(minHeap, left)

            results.append(-maxHeap[0])

        return results