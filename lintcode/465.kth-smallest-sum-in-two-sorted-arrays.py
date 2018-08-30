import heapq
class Solution:
    """
    @param A: an integer arrays sorted in ascending order
    @param B: an integer arrays sorted in ascending order
    @param k: An integer
    @return: An integer
    """
    def kthSmallestSum(self, A, B, k):
        # write your code here

        hq = []
        for i in range(len(B)):
            heapq.heappush(hq, (B[i] + A[0], i, 0))

        for i in range(k - 1):
            val, x, y = hq[0]
            heapq.heappop(hq)

            if y + 1 < len(A):
                heapq.heappush(hq, (B[x] + A[y + 1], x, y + 1))

        return hq[0][0]