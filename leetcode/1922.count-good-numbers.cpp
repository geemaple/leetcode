//  Tag: Math, Recursion
//  Time: O(LogN)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/RLJUBra6NG4

//  A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
//  
//  For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
//  
//  Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
//  A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
//   
//  Example 1:
//  
//  Input: n = 1
//  Output: 5
//  Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
//  
//  Example 2:
//  
//  Input: n = 4
//  Output: 400
//  
//  Example 3:
//  
//  Input: n = 50
//  Output: 564908303
//  
//   
//  Constraints:
//  
//  1 <= n <= 1015
//  
//  

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = n - odd;
        int mod = 1e9 + 7;
        return 1LL * pow(5, even, mod) * pow(4, odd, mod) % mod;
    }

    int pow(int x, long long power, int mod) {
        int res = 1;
        while (power) {
            if (power % 2 == 1) {
                res = 1LL * res * x % mod;
            } 
            x = 1LL * x * x % mod;
            power = power / 2;
        }
        return res;
    }
};