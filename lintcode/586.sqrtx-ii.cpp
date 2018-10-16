class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        // write your code here
        
        double start = 1;
        double end = x;
        
        if (x < 1)
        {
            start = x;
            end = 1;
        }
        
        while (end - start > 1e-10)
        {
            double mid = (start + end ) / 2;
            
            if (mid * mid < x)
            {
                start = mid;
            }
            else if (mid * mid > x)
            {
                end = mid;
            }
            else
            {
                break;
            }
        }
        
        return start;
    }
};