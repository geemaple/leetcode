from typing import List
class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        n = len(mat)
        m = len(mat[0])

        if (m * n == r * c):
            res = [[0 for j in range(c)] for i in range(r)]
            for i in range(m * n):
                res[i // c][i % c] = mat[i // m][i % m]
            return res
        else:
            return mat


s = Solution()
res = s.matrixReshape([[1,2],[3,4]], 1, 4)
print(res)