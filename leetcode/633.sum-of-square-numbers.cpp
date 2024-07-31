//  Tag: Math, Two Pointers, Binary Search
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
//   
//  Example 1:
//  
//  Input: c = 5
//  Output: true
//  Explanation: 1 * 1 + 2 * 2 = 5
//  
//  Example 2:
//  
//  Input: c = 3
//  Output: false
//  
//   
//  Constraints:
//  
//  0 <= c <= 231 - 1
//  
//  

class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        long right = sqrt(c);

        while (left <= right) {
            long res = left * left + right * right;
            if (res == c) {
                return true;
            } 

            if (res > c) {
                right --;
            } else {
                left ++;
            }
        }

        return false;
    }
};