//  Tag: Math, Combinatorics
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/xokW4a6BVrs

//  You are given three integers n, m, k. A good array arr of size n is defined as follows:
//  
//  Each element in arr is in the inclusive range [1, m].
//  Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
//  
//  Return the number of good arrays that can be formed.
//  Since the answer may be very large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: n = 3, m = 2, k = 1
//  Output: 4
//  Explanation:
//  
//  There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
//  Hence, the answer is 4.
//  
//  
//  Example 2:
//  
//  Input: n = 4, m = 2, k = 2
//  Output: 6
//  Explanation:
//  
//  The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2, 2, 1, 1] and [2, 2, 2, 1].
//  Hence, the answer is 6.
//  
//  
//  Example 3:
//  
//  Input: n = 5, m = 2, k = 0
//  Output: 2
//  Explanation:
//  
//  The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the answer is 2.
//  
//  
//   
//  Constraints:
//  
//  1 <= n <= 105
//  1 <= m <= 105
//  0 <= k <= n - 1
//  
//  

const int mod = 1e9 + 7;
const int limit = 1e5;

long long fact[limit + 1];
long long invert[limit + 1];

class Solution {
public:
    int power(int n, int q, int mod) {
        int res = 1;
        while (q > 0) {
            if (q % 2 == 1) {
                res = (1LL * res * n) % mod;
            }

            n = 1LL * n * n % mod;
            q /= 2;
        }
        return res;
    }

    int comb(int n, int m, int mod) {
        return 1LL * fact[n] * invert[m] % mod * invert[n - m] % mod;
    }

    void init() {
        if (fact[0] != 0) {
            return;
        }

        fact[0] = 1;
        for (int i = 1; i <= limit; i++) {
            fact[i] = 1LL * fact[i - 1] * i % mod;
        }

        invert[limit] = power(fact[limit], mod - 2, mod);
        for (int i = limit; i > 0; i--) {
            invert[i - 1] = 1LL * invert[i] * i % mod;
        }
    }

    int countGoodArrays(int n, int m, int k) {
        init();
        return 1LL * m * power(m - 1, n - k - 1, mod) % mod * comb(n - 1, k, mod) % mod;
    }
};