//  Tag: Math, Greedy
//  Time: O(1)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/pnX4dBWwczQ

//  You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
//  Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
//  Notes:
//  
//  When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
//  Bob can remap a digit to itself, in which case num does not change.
//  Bob can remap different digits for obtaining minimum and maximum values respectively.
//  The resulting number after remapping can contain leading zeroes.
//  
//   
//  Example 1:
//  
//  Input: num = 11891
//  Output: 99009
//  Explanation: 
//  To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
//  To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
//  The difference between these two numbers is 99009.
//  
//  Example 2:
//  
//  Input: num = 90
//  Output: 99
//  Explanation:
//  The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
//  Thus, we return 99.
//   
//  Constraints:
//  
//  1 <= num <= 108
//  
//  

class Solution {
public:
    int minMaxDifference(int num) {
        int min_v = num;
        int max_v = num;
        for (int i = 0; i < 10; i++) {
            int high = 0;
            int low = 0;
            int mul = 1;
            int n = num;
            while (n > 0) {
                bool replace = n % 10 == i;
                low += (replace ? 0 : n % 10) * mul;
                high += (replace ? 9 : n % 10) * mul;
                n /= 10;
                mul *= 10;
            }

            min_v = min(min_v, low);
            max_v = max(max_v, high);
        }
        return max_v - min_v;
    }
};