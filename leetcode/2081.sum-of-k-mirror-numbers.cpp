//  Tag: Math, Enumeration
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/GlW7BUi1WRk

//  A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.
//  
//  For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
//  On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
//  
//  Given the base k and the number n, return the sum of the n smallest k-mirror numbers.
//   
//  Example 1:
//  
//  Input: k = 2, n = 5
//  Output: 25
//  Explanation:
//  The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
//    base-10    base-2
//      1          1
//      3          11
//      5          101
//      7          111
//      9          1001
//  Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
//  
//  Example 2:
//  
//  Input: k = 3, n = 7
//  Output: 499
//  Explanation:
//  The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
//    base-10    base-3
//      1          1
//      2          2
//      4          11
//      8          22
//      121        11111
//      151        12121
//      212        21212
//  Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
//  
//  Example 3:
//  
//  Input: k = 7, n = 17
//  Output: 20379000
//  Explanation: The 17 smallest 7-mirror numbers are:
//  1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
//  
//   
//  Constraints:
//  
//  2 <= k <= 9
//  1 <= n <= 30
//  
//  

class Solution {
public:
    long long kMirror(int k, int n) {
        long long res = 0;
        int l = 1;
        vector<long long> pre{0}, cur{0};

        for (int d = 1; d < 10 && n > 0; ++d) {
            cur.push_back(d);
            if (testK(d, k)) {
                res += d;
                --n;
            }
        }

        return res + find(2, 10, pre, cur, k, n);
    }

    bool testK(long long num, int base) {
        long long mul = 1;
        while (mul * base <= num) {
            mul *= base;
        }

        while (num > 0) {
            if (num / mul != num % base) {
                return false;
            }
            num = (num - (num / mul) * mul - num % base) / base;
            mul /= base * base;
        }

        return true;
    }

    long long find(int l, long long first_mul, vector<long long> &pre, vector<long long> &cur, int k, int n) {
        vector<long long> tmp;
        long long res = 0;

        for (int i = 0; i < 10 && n > 0; ++i) {
            for (int j = 0; j < pre.size() && n > 0; ++j) {
                long long val = first_mul * i + pre[j] * 10 + i;
                tmp.push_back(val);
                if (i != 0 && testK(val, k)) {
                    res += val;
                    --n;
                }
            }
        }

        return res + (n == 0 ? 0 : find(l + 1, first_mul * 10, cur, tmp, k, n));
    }
};

class Solution {
public:
    long long kMirror(int k, int n) {
        vector<long long> res;
        int l = 1;
        while (res.size() < n) {
            string tmp(l, ' ');
            find(l, 0, tmp, res, k, n);
            l += 1;
        }

        return accumulate(res.begin(), res.end(), 0LL);
    }

    bool testK(long long num, int k) {
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % k);
            num /= k;
        }

        int l = 0;
        int r = digits.size() - 1;
        while (l < r && digits[l] == digits[r]) {
            l += 1;
            r -= 1;
        }

        return l >= r;
    }

    void find(int l, int i, string &tmp, vector<long long> &res, int k, int n) {
        if (res.size() == n) {
            return;
        }

        if (i > l - 1 - i) {
            long long num = stoll(tmp);
            if (testK(num, k)) {
                res.push_back(num);
            }
            return;
        }

        for (int d = 0; d < 10; d++) {
            if (i == 0 && d == 0) {
                continue;
            }

            tmp[i] = tmp[l - 1 - i] = d + '0';
            find(l, i + 1, tmp, res, k, n);
        }
    }
};