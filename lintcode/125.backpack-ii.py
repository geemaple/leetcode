# f[i][w] = max(f[i - 1][w], f[i - 1][w - A[i - 1]] + v[i - 1])
class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param A: Given n items with size A[i]
    @param V: Given n items with value V[i]
    @return: The maximum value
    """
    def backPackII(self, m, A, V):
        # write your code here
        table = [-1 for _ in range(m + 1)]
        table[0] = 0

        for i in range(len(A)):
            for w in range(m, -1, -1):
                value = table[w]

                if w - A[i] >= 0 and table[w - A[i]] != -1:
                    value = max(value, table[w - A[i]] + V[i])

                table[w] = value

        return max(table)