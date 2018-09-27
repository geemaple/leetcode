class Solution {
public:
    string addBinary(string a, string b) {
        int size = max(a.size(), b.size());
        int addOn = 0;

        string res = "";
        for(auto i = 0; i < size; ++i)
        {
            int digitA = (i + 1 <= a.size()) ? a[a.size() - 1 - i] - '0' : 0;
            int digitB = (i + 1 <= b.size()) ? b[b.size() - 1 - i] - '0' : 0;
            int number = (digitA + digitB + addOn);
            addOn = number / 2;
            res = to_string(number % 2) + res;
        }

        if (addOn > 0)
        {
            res = to_string(addOn) + res;
        }

        return res;
    }
};
