# f(x) = f(x - 1) + f(x - 2)
# if x != 0: f(x - 1) is valid
# if 10 <= (x - 1)* 10 + x <= 26: f(x-2) is valid

class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        size = len(s)
        table = [0] * (size + 1)
        table[0] = 1

        for i in range(1, size + 1):

            if s[i - 1] != '0':
                table[i] += table[i - 1]

            if i - 2 >=0 and (s[i - 2] == '1' or (s[i - 2] == '2' and int(s[i - 1]) <= 6)):
                table[i] += table[i - 2]

        return table[-1]