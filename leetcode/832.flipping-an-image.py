class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for i in range(len(A)):
            start = 0
            end = len(A[i]) - 1
            while (start <= end):
                A[i][start], A[i][end] = 1 - A[i][end], 1 - A[i][start]
                start += 1
                end -= 1
                
            if start == end:
                A[i][start] = 1 - A[i][start]
        
        return A