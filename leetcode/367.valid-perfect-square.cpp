class Solution {
public:
    bool isPerfectSquare(int num) {
        long long start = 0;
        long long end = num;
        
        while(start + 1 < end)
        {
            long long mid = start + (end - start) / 2;
            if (mid * mid < num)
            {
                start = mid;
            }
            else if(mid * mid > num)
            {
                end = mid;
            }
            else
            {
                return true;
            }
        }
        
        return start * start == num || end * end == num;
    }
};