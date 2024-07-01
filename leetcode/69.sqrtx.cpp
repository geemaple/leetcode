//  Tag: Math, Binary Search
//  Time: N(logN)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
//  You must not use any built-in exponent function or operator.
//  
//  For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
//  
//   
//  Example 1:
//  
//  Input: x = 4
//  Output: 2
//  Explanation: The square root of 4 is 2, so we return 2.
//  
//  Example 2:
//  
//  Input: x = 8
//  Output: 2
//  Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
//  
//   
//  Constraints:
//  
//  0 <= x <= 231 - 1
//  
//  

class Solution {
public:
    int mySqrt(int x) {
        long start = 0;
        long end = x;

        while (start < end) {
            int mid = start + (end - start + 1) / 2;
            int sqrt = x / mid;

            if (mid > sqrt) {
                end = mid - 1;
            } else {
                start = mid;
            }
        }

        return start;
    }
};

class Solution {
public:
    int mySqrt(int t) {
        long long x = t;

        while (x * x > t) {
            x = (x + t / x) / 2;
        }

        return x;
    }
};