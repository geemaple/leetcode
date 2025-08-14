//  Tag: Hash Table, Math, Sorting, Counting, Enumeration
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/7jkS-3NNIKU

//  You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
//  Return true if and only if we can do this so that the resulting number is a power of two.
//   
//  Example 1:
//  
//  Input: n = 1
//  Output: true
//  
//  Example 2:
//  
//  Input: n = 10
//  Output: false
//  
//   
//  Constraints:
//  
//  1 <= n <= 109
//  
//  

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long long c = counter(n);
        for (int i = 0; i < 32; i++) {
            if (counter(1 << i) == c) {
                return true;
            }
        }
        return false;
    }

    long counter(int n) {
        long res = 0;
        while (n > 0) {
            res += pow(10, n % 10);
            n /= 10;
        }
        return res;
    }
};