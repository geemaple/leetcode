class Solution:
    def romanToInt(self, s: str) -> int:

    roman = {'M': 1000,'D': 500 ,'C': 100,'L': 50,'X': 10,'V': 5,'I': 1}
    res = 0
    for i in range(0, len(s) - 1):
        if roman[s[i]] < roman[s[i+1]]:
            res -= roman[s[i]]
        else:
            res += roman[s[i]]

    return res + roman[s[-1]]


class Solution2:
    def romanToInt(self, s: str) -> int:
        
        romans = ["M" , "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        res = 0

        for i in range(len(romans)):
            while s.startswith(romans[i]):
                res += values[i]
                s = s[len(romans[i]): len(s)]

        return res