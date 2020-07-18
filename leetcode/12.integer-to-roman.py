class Solution:
    def intToRoman(self, num: int) -> str:
        
        romans = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        res = ''

        for i in range(len(romans)):
            while (num - values[i] >= 0):
                res += romans[i]
                num -= values[i]

        return res