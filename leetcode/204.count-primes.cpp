//  Tag: Array, Math, Enumeration, Number Theory
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer n, return the number of prime numbers that are strictly less than n.
//   
//  Example 1:
//  
//  Input: n = 10
//  Output: 4
//  Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//  
//  Example 2:
//  
//  Input: n = 0
//  Output: 0
//  
//  Example 3:
//  
//  Input: n = 1
//  Output: 0
//  
//   
//  Constraints:
//  
//  0 <= n <= 5 * 106
//  
//  

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<bool> prime(n, true);
        int count = n - 2; 
        for (int i = 2; i < sqrt(n) + 1; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    if (prime[j]) {
                        prime[j] = false;
                        count--;
                    }
                }
            }
        }

        return count;
    }
};


class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<bool> prime(n, true);
        int count = n / 2 - 1; // 去掉1

        for (int i = 3; i < sqrt(n) + 1; i+=2) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    if (prime[j]) {
                        prime[j] = false;
                        count--;
                    }
                }
            }
        }

        return count + 1;  // 加上2
    }
};