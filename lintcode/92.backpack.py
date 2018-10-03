class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param A: Given n items with size A[i]
    @return: The maximum size
    """
    def backPack(self, m, A):
        # write your code here
        table = [False for _ in range(m + 1)]
        table[0] = True

        for i in range(len(A)):
            for w in range(m, -1, -1):
                value = table[w]
                if w - A[i] >= 0:
                    value = value or table[w - A[i]]
                table[w] = value

        maxsize = 0

        for i in range(m, -1, -1):
            if table[i]:
                maxsize = i
                break

        return maxsize