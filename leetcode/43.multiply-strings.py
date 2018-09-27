# res[i + j] += a[i] * b[j]
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        
        size = len(num1) + len(num2)
        digits = [0] * size

        for i in range(len(num1)):
            digit1 = int(num1[i])

            for j in range(len(num2)):
                
                digit2 = int(num2[j])
                index = size - 1 - i - 1 - j
                digits[index] += digit1 * digit2

        res = ''
        addon = 0
        for i in range(len(digits)):
            number = digits[i] + addon
            addon = number / 10
            res = str(number % 10) + res

        while(len(res) > 1 and res[0] == '0'):
            res = res[1:]

        return res