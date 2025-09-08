//  Tag: Math
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/Fen3cNUNyyk

//  No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
//  Given an integer n, return a list of two integers [a, b] where:
//  
//  a and b are No-Zero integers.
//  a + b = n
//  
//  The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.
//   
//  Example 1:
//  
//  Input: n = 2
//  Output: [1,1]
//  Explanation: Let a = 1 and b = 1.
//  Both a and b are no-zero integers, and a + b = 2 = n.
//  
//  Example 2:
//  
//  Input: n = 11
//  Output: [2,9]
//  Explanation: Let a = 2 and b = 9.
//  Both a and b are no-zero integers, and a + b = 11 = n.
//  Note that there are other valid answers as [8, 3] that can be accepted.
//  
//   
//  Constraints:
//  
//  2 <= n <= 104
//  
//  

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res(2, 0);
        for (int i = 1; i < n; i++) {
            if (check(i) && check(n - i)) {
                res[0] = i;
                res[1] = n - i;
                break;
            }
        }
        return res;
    }

    bool check(int num) {
        while (num > 0) {
            if (num % 10 == 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 0, b = 0;
        int base = 1;

        while (n > 0) {
            int d = n % 10;
            if (d == 0) {
                a += 5 * base;
                b += 5 * base;
                n -= 10;
            } else if (d == 1 && n >= 10) {
                a += 6 * base;
                b += 5 * base;
                n -= 10;
            } else {
                a += (d - d / 2) * base;
                b += (d / 2) * base;
            }
            n /= 10;
            base *= 10;
        }

        return {a, b};
    }
};