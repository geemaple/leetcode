//  Tag: Math
//  Time: O(LogN)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/_C41NB1Mw6w

//  Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.
//  An integer y is a power of three if there exists an integer x such that y == 3x.
//   
//  Example 1:
//  
//  Input: n = 12
//  Output: true
//  Explanation: 12 = 31 + 32
//  
//  Example 2:
//  
//  Input: n = 91
//  Output: true
//  Explanation: 91 = 30 + 32 + 34
//  
//  Example 3:
//  
//  Input: n = 21
//  Output: false
//  
//   
//  Constraints:
//  
//  1 <= n <= 107
//  
//  

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) {
                return false;
            } else {
                n = n / 3;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<long long> table(15, 1);
        for (int i = 1; i < 15; i++) {
            table[i] = table[i - 1] * 3;
        }

        for (int i = 14; i >= 0; i--) {
            if (n >= 2 * table[i]) { 
                return false;
            } else if (n >= table[i]) {
                n -= table[i];
            }
        }

        return true;
    }
};