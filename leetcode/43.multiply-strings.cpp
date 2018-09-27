// res[i + j] += a[i] * b[j]
class Solution {
public:
    string multiply(string num1, string num2) {
        
        int size = num1.size() + num2.size();
        vector<int> digits(size, 0);
        
        for(auto i = 0; i < num1.size(); ++i)
        {
            int digit1 = num1[i] - '0';
            for(auto j = 0; j < num2.size(); ++j)
            {
                int digit2 = num2[j] - '0';
                int index = size - 1 - i - 1 - j;
                digits[index] += digit1 * digit2;
            }
        }
        
        int addon = 0;
        string res = "";
        
        for (auto i = 0; i < digits.size(); ++i)
        {
            int number = digits[i] + addon;
            addon = number / 10;
            res = to_string(number % 10) + res;
        }
        
        while (res.size() > 1 && res[0] == '0') {
            res = res.substr(1, res.size() - 1);
        }
        
        return res;
    }
};