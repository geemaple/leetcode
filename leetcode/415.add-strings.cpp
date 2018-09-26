class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int size = max(num1.size(), num2.size());
        int addons = 0;
        string res = "";
        for(auto i = 0; i < size; ++i)
        {
            // warning: (num1.size() - 1 - i) is always >= 0 since size() is unsigned long
            int digit1 = (i + 1 <= num1.size()) ? num1[num1.size() - 1 - i] - '0' : 0;
            int digit2 = (i + 1 <= num2.size()) ? num2[num2.size() - 1 - i] - '0' : 0;
            
            int number = digit1 + digit2 + addons;
            addons = number / 10;
            
            res = to_string(number % 10) + res;
        }
        
        if (addons > 0)
        {
            res = to_string(addons) + res;
        }
        
        return res;
    }
};