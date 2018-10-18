# f[i][j] = min(
#    f[i - 1][j] + 1, 
#    f[i][j - 1] + 1,  
#    f[i - 1][j - 1] + 1,  where s1[i - 1] != s2[j - 1]
#    f[i - 1][j - 1] where s1[i - 1] == s2[j - 1]
# )

class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m = len(word1)
        n = len(word2)

        table = [[float('inf') for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 or j == 0:
                    table[i][j] = abs(i - j)
                    continue
                
                table[i][j] = min(table[i][j], table[i - 1][j] + 1) # delete
                table[i][j] = min(table[i][j], table[i][j - 1] + 1) # insert

                if word1[i - 1] == word2[j - 1]:
                    table[i][j] = min(table[i][j], table[i - 1][j - 1])  # last equal
                else:
                    table[i][j] = min(table[i][j], table[i - 1][j - 1] + 1) # replace

        return table[m][n]

# sliding array
class Solution2(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m = len(word1)
        n = len(word2)
        
        k = 2
        table = [[float('inf') for _ in range(n + 1)] for _ in range(k)]

        for i in range(m + 1):
            for j in range(n + 1):
                table[i % k][j] = float('inf')           
                
                if i == 0 or j == 0:
                    table[i % k][j] = abs(i - j)
                    continue
                
                table[i % k][j] = min(table[i % k][j], table[(i - 1) % k][j] + 1) # delete
                table[i % k][j] = min(table[i % k][j], table[i % k][j - 1] + 1) # insert

                if word1[i - 1] == word2[j - 1]:
                    table[i % k][j] = min(table[i % k][j], table[(i - 1) % k][j - 1])  # last equal
                else:
                    table[i % k][j] = min(table[i % k][j], table[(i - 1) % k][j - 1] + 1) # replace

        return table[m % k][n]
