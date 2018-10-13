# f[i][j] = min(f[i - 1][k] + |j - A[i - 1]|) where 1 <= K <= 100, | K - j | <= target

class Solution:
    """
    @param: A: An integer array
    @param: target: An integer
    @return: An integer
    """
    def MinAdjustmentCost(self, A, target):
        # write your code here
        
        size = len(A)
        table = [[float('inf') for _ in range(100 + 1)] for _ in range(size + 1)]
        
        for i in range(1, 101):
            table[1][i] = abs(A[0] - i)
            
        for i in range(2, size + 1):
            for j in range(1, 100 + 1):
                value = float('inf')
                
                for k in range(j - target, j + target + 1):
                    if k < 1 or k > 100 or table[i - 1][k] == float('inf'):
                        continue
                    
                    value = min(value, table[i - 1][k] + abs(j - A[i - 1]))
                    
                table[i][j] = value                    
                
        return min(table[size])