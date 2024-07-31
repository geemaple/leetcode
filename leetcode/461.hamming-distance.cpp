//  Tag: Bit Manipulation
//  Time: O(1)
//  Space: O(1)
//  Ref: -
//  Note: -

//  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//  Given two integers x and y, return the Hamming distance between them.
//   
//  Example 1:
//  
//  Input: x = 1, y = 4
//  Output: 2
//  Explanation:
//  1   (0 0 0 1)
//  4   (0 1 0 0)
//         ↑   ↑
//  The above arrows point to positions where the corresponding bits are different.
//  
//  Example 2:
//  
//  Input: x = 3, y = 1
//  Output: 1
//  
//   
//  Constraints:
//  
//  0 <= x, y <= 231 - 1
//  
//  

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int res = 0;
        while (n) {
            res += 1;
            n = n & (n - 1);
        }
        return res;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int res = 0;
        while (diff) {
            res += diff & 1;
            diff = diff >> 1;
        }
        return res;
    }
};