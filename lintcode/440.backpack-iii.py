# f[i][w] = max(f[i - 1][w - k * A[i - 1]] + k * V[i - 1] where k >= 0)
#         = max(f[i - 1][w], f[i - 1][w - A[i - 1]] + V[i - 1], f[i - 2][w - 2 * A[i - 1]] + 2 * V[i - 1] ...)
#
# suppose: w1 = w - A[i - 1] w1 is weight and also index
# 
#         = max(f[i - 1][w], f[i - 1][w1] + V[i - 1], f[i - 2][w1 - A[i - 1]] + 2 * V[i - 1], f[i - 2][w1 - 2 * A[i - 1]] + 3 * V[i - 1])
#         = max(f[i - 1][w], max(f[i - 1][w1], f[i - 2][w1 - A[i - 1]] + V[i - 1], f[i - 2][w1 - 2 * A[i - 1]] + 2 * V[i - 1]... ) + V[i - 1])
#         = max(f[i - 1][w], f[i][w1]+ v[i - 1])
# f[i][w] = max(f[i - 1][w], f[i][w - A[i - 1]] + V[i - 1])

class Solution:
    """
    @param A: an integer array
    @param V: an integer array
    @param m: An integer
    @return: an array
    """
    def backPackIII(self, A, V, m):
        # write your code here
        table = [-1 for _ in range(m + 1)]
        table[0] = 0

        for i in range(len(A)):
            for w in range(m + 1):
                value = table[w]

                if (w - A[i] >= 0 and table[w - A[i]] != -1):
                    value = max(value, table[w - A[i]] + V[i])

                table[w] = value

        return max(table)