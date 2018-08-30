import heapq
class Solution:
    """
    @param arrays: a list of array
    @param k: An integer
    @return: an integer, K-th largest element in N arrays
    """
    def KthInArrays(self, arrays, k):
        # write your code here
        hq = []

        for sub in arrays:
            for num in sub:
                if len(hq) < k:
                    heapq.heappush(hq, num)
                elif hq[0] < num:
                    heapq.heappop(hq)
                    heapq.heappush(hq, num)

        return hq[0]