#  Tag: Array, Binary Search, Sorting, Heap (Priority Queue), Matrix
#  Time: O(KlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
#  Note that it is the kth smallest element in the sorted order, not the kth distinct element.
#  You must find a solution with a memory complexity better than O(n2).
#   
#  Example 1:
#  
#  Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
#  Output: 13
#  Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
#  
#  Example 2:
#  
#  Input: matrix = [[-5]], k = 1
#  Output: -5
#  
#   
#  Constraints:
#  
#  n == matrix.length == matrix[i].length
#  1 <= n <= 300
#  -109 <= matrix[i][j] <= 109
#  All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
#  1 <= k <= n2
#  
#   
#  Follow up:
#  
#  Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
#  Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.
#  
#  

import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        heap = []
        m = len(matrix)
        n = len(matrix[0])

        for i in range(m):
            heapq.heappush(heap, (matrix[i][0], i, 0))

        for i in range(k - 1):
            val, x, y = heapq.heappop(heap)
            if (y + 1 < n):
                heapq.heappush(heap, (matrix[x][y + 1], x, y + 1))
        return heap[0][0]

# Follow up
import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        left = matrix[0][0]
        right = matrix[-1][-1]
        while left < right:
            mid = (left + right) >> 1
            if self.count_less_equal(matrix, mid) < k:
                left = mid + 1
            else:
                right = mid

        return left

    def count_less_equal(self, matrix: list, target) -> int:
        n = len(matrix)
        row = n - 1
        col = 0
        count = 0
        while row >= 0 and col < n:
            if matrix[row][col] <= target:
                count += row + 1
                col += 1
            else:
                row -= 1

        return count