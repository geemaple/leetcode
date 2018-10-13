# f[i][j][t] = f[i - 1][j][t] + f[i - 1][j - 1][t - A[i - 1]]
class Solution:
    """
    @param A: An integer array
    @param k: A positive integer (k <= length(A))
    @param target: An integer
    @return: An integer
    """
    def kSum(self, A, k, target):
        # write your code here
        size = len(A)
        table = [[[0 for _ in range(target + 1)] for _ in range(k + 1)] for _ in range(size + 1)]
        table[0][0][0] = 1
        
        for i in range(1, size + 1):
            for j in range(0, k + 1):
                for t in range(0, target + 1):
                    table[i][j][t] += table[i - 1][j][t]
                    if j - 1 >= 0 and t - A[i - 1] >= 0:
                        table[i][j][t] += table[i - 1][j - 1][t - A[i - 1]]
                        
        return table[size][k][target]