class Solution(object):
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        
        if A is None or B is None or len(A) == 0 or len(B) == 0:
            return [[]]

        m = len(A)
        n = len(B[0])

        res = [[0 for _ in range(n)] for _ in range(m)]
        sparseB = [[] for _ in range(len(B))]

        for i in range(len(B)):
            for j in range(len(B[i])):
                sparseB[i].append((j, B[i][j]))


        for i in range(m):
            for k in range(len(A[i])):
                if A[i][k] != 0:
                    for p in range(len(sparseB[k])):
                        j, val = sparseB[k][p]
                        res[i][j] += A[i][k] * val

        return res