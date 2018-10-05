# f[i][j] = max(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1] + 1 where A[i - 1] == B[j - 1])
class Solution:
    """
    @param A: A string
    @param B: A string
    @return: The length of longest common subsequence of A and B
    """
    def longestCommonSubsequence(self, A, B):
        # write your code here
        if A is None or B is None or len(A) == 0 or len(B) == 0:
            return 0

        m = len(A)
        n = len(B)
        table = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 or j == 0:
                    table[i][j] = 0
                    continue

                table[i][j] = max(table[i - 1][j], table[i][j - 1])

                if (A[i - 1] == B[j - 1]):
                    table[i][j] = table[i - 1][j - 1] + 1

        return table[m][n]