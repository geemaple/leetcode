class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        
        size = max(len(num1), len(num2))
        addon = 0
        res = ''

        for i in range(size):
            digit1 = int(num1[~i]) if i + 1 <= len(num1) else 0
            digit2 = int(num2[~i]) if i + 1 <= len(num2) else 0

            number = digit1 + digit2 + addon
            addon = number / 10
            res = str(number % 10) + res

        if addon > 0:
            res = str(addon) + res

        return res