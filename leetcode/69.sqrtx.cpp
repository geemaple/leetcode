class Solution {
public:
    int mySqrt(int x) {
        
        if (x < 2)
        {
            return x;
        }
        
        long long start = 0;
        long long end = x / 2;
        
        while(start + 1 < end)
        {
            long long mid = start + (end - start) / 2;
            if (mid * mid > x)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        return (end * end <= x) ? end : start;
        
    }
};