class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        bool minus = ((dividend > 0) ^ (divisor > 0));
        
        long long number = labs(dividend);
        long long div = labs(divisor);

        long long res = 0;
        
        while (number >= div) {
            long long tmp = div;
            long long mul = 1;
            while(number >= (tmp << 1)) {
                mul <<= 1;
                tmp <<= 1;
            }
            
            res += mul;
            number -= tmp;
        }
        
        return (int)(minus ? -res: res);
    }
};