class Solution {
public:
    string intToRoman(int num) {

        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string res = "";

        for (auto i = 0; i < 13; ++i)
        {
            while(num - values[i] >= 0)
            {
                res += romans[i];
                num -= values[i];
            }
        }

        return res;
    }
};
