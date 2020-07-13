class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int pop = x % 10; // gets last number
            x /= 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8)) return 0;
            res = res * 10 + pop;
        }
        
        return res;
    }
};

class Solution2 {
public:
    int reverse(int x) {
        
        int res = 0;
        while(x != 0)
        {
            int pop = x % 10;
            x = x / 10;

            int candidate = res * 10 + pop;

            if (candidate / 10 != res)
            {
                return 0;
            }

            res = candidate;            
        }

        return res;
    }
};
