import heapq
class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        hq = []
        m = len(matrix)
        n = len(matrix[0])

        for i in range(m):
            heapq.heappush(hq, (matrix[i][0], i, 0))

        for i in range(k - 1):
            val, x, y = hq[0]
            heapq.heappop(hq)
            if (y + 1 < n):
                heapq.heappush(hq, (matrix[x][y + 1], x, y + 1))
        return hq[0][0]