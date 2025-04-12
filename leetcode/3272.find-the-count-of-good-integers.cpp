//  Tag: Hash Table, Math, Combinatorics, Enumeration
//  Time: O(10**(N/2) * NlogN)
//  Space: O(10**(N/2))
//  Ref: -
//  Note: -
//  Video: https://youtu.be/MspuxMFiZeM

//  You are given two positive integers n and k.
//  An integer x is called k-palindromic if:
//  
//  x is a palindrome.
//  x is divisible by k.
//  
//  An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.
//  Return the count of good integers containing n digits.
//  Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.
//   
//  Example 1:
//  
//  Input: n = 3, k = 5
//  Output: 27
//  Explanation:
//  Some of the good integers are:
//  
//  551 because it can be rearranged to form 515.
//  525 because it is already k-palindromic.
//  
//  
//  Example 2:
//  
//  Input: n = 1, k = 4
//  Output: 2
//  Explanation:
//  The two good integers are 4 and 8.
//  
//  Example 3:
//  
//  Input: n = 5, k = 6
//  Output: 2468
//  
//   
//  Constraints:
//  
//  1 <= n <= 10
//  1 <= k <= 9
//  
//  

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<int> fac(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            fac[i] = i * fac[i - 1];
        }

        long long res = 0;
        int half = (n + 1) / 2;
        unordered_set<string> seen;
        for (int d = pow(10, half - 1); d < pow(10, half); d++) {
            string num = to_string(d);
            string p = num;
            for (int i = num.size() - 1 - n % 2; i >= 0; i--) {
                p += num[i];
            }

            string key = p;
            sort(key.begin(), key.end());
            if (seen.find(key) == seen.end() && stol(p) % k == 0) {
                seen.insert(key);
                unordered_map<char, int> counter;
                for (auto &x: p) {
                    counter[x] += 1;
                }

                long long x = (n - counter['0']) * fac[n - 1];
                for (auto &[digit, count]: counter) {
                    x /= fac[count];
                }
                res += x;
            }
        }
        
        return res;
    }
};