class Solution(object):

    def findPreviousCharIndex(self, s, index):
        count = 0
        for i in range(index, -1, -1):
            if s[i] == '#':
                count += 1
            else:
                if count > 0:
                    count -= 1
                else:
                    return i
        return -1

    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """

        left = len(S) - 1
        right = len(T) - 1

        while (left >= 0 and right >= 0):
            left = self.findPreviousCharIndex(S, left)
            right = self.findPreviousCharIndex(T, right)

            if S[left] != T[right]:
                return False

            left -= 1
            right -= 1

        if (left == -1):
            right = self.findPreviousCharIndex(T, right)

        if (right == -1):
            left = self.findPreviousCharIndex(S, left)

        return left == right