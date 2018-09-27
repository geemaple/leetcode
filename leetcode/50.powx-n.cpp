// O(LogN) Iterative
class Solution {
public:
    double myPow(double x, int n)
    {
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double ans = 1;
        double current_product = x;
        for (auto i = n; i > 0; i /= 2) {
            if ((i % 2) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }
};

// O(LogN) Recursive
class Solution2 {
private:
    double recursivePow(double x, int n)
    {
        if (n == 0)
        {
            return 1.0;
        }

        double half = recursivePow(x, n / 2);

        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
public:
    double myPow(double x, int n) {
        if (n < 0){
            x = 1 / x;
            n = -n;
        }
         
        return recursivePow(x, n);
    }
};

// O(N)
class Solution3 {
public:
    double myPow(double x, int n) {
        if (n < 0){
            x = 1 / x;
            n = -n;
        }
         
        double ans = 1;
        for (auto i = 0; i < n; ++i)
        {
            ans = ans * x;
        }

        return ans;
    }
};
