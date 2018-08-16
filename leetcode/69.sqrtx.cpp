class Solution {
public:
    int mySqrt(int x) {
        long start = 0;
        long end = x;

        while(start + 1 < end)
        {
            long mid = start + (end - start) / 2;

            if (mid * mid > x)
            {
                end = mid;
            }
            else if (mid * mid < x)
            {
                start = mid;
            }
            else
            {
                return (int)mid;
            }
        }

        return (int)((end * end > x) ? start : end);
    }
};
