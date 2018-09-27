class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        size = max(len(a), len(b))
        addOn = 0

        res = ''
        for i in range(size):
            digitA = int(a[~i]) if (i + 1 <= len(a)) else 0
            digitB = int(b[~i]) if (i + 1 <= len(b)) else 0

            number = digitA + digitB + addOn
            addOn = number // 2

            res = str(number % 2) + res

        if addOn > 0:
            res = str(addOn) + res

        return res