# f[i][j] = (min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1) if matrix[i][j] == 0 else 0
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if matrix is None or len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
            
        m = len(matrix)
        n = len(matrix[0])
        
        k = 2
        table = [[0 for _ in range(n)] for _ in range(k)]
        result = 0
        
        for i in range(m):
            for j in range(n):
                
                if i == 0 or j == 0:
                    table[i % k][j] = 1 if matrix[i][j] == '1' else 0
                elif matrix[i][j] == '1':
                    table[i % k][j] = 1 + min(table[(i - 1) % k][j], table[i % k][j - 1], table[(i - 1) % k][j - 1])
                else:
                    table[i % k][j] = 0 # this is important when using circular array
                
                result = max(result, table[i % k][j])
                
        return result ** 2