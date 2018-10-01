# f[i] = (f[i - 1] == false or f[i - 2] == false) 
class Solution:
    """
    @param n: An integer
    @return: A boolean which equals to true if the first player will win
    """
    def firstWillWin(self, n):
        # write your code here
        if n == 0:
            return False

        if n == 1 or n == 2:
            return False

        table = [False for _ in range(n + 1)]

        for i in range(3, n + 1):
            table[i] = not table[i - 1] or not table[i - 2]

        return table[-1]