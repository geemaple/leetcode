//  Tag: Array, Math, Sliding Window, Enumeration, Number Theory
//  Time: O(N * sqrt(Num))
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given an array of positive integers nums.
//  An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:
//  
//  prod(arr) is the product of all elements of arr.
//  gcd(arr) is the GCD of all elements of arr.
//  lcm(arr) is the LCM of all elements of arr.
//  
//  Return the length of the longest product equivalent subarray of nums.
//   
//  Example 1:
//  
//  Input: nums = [1,2,1,2,1,1,1]
//  Output: 5
//  Explanation: 
//  The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
//  
//  Example 2:
//  
//  Input: nums = [2,3,4,5,6]
//  Output: 3
//  Explanation: 
//  The longest product equivalent subarray is [3, 4, 5].
//  
//  Example 3:
//  
//  Input: nums = [1,2,3,1,4,5,1]
//  Output: 5
//  
//   
//  Constraints:
//  
//  2 <= nums.length <= 100
//  1 <= nums[i] <= 10
//  
//  

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 2;
        int i = 0;
        unordered_map<int, int> last;
        for (int j = 0; j < n; ++j) {
            vector<int> primes = getPrimes(nums[j]);
            for (auto d: primes) {
                int next_i = last.count(d) > 0 ? last[d] + 1: 0;
                i = max(i, next_i);
                last[d] = j;
            }
            res = max(res, j - i + 1);
        }

        return res;
    }

    vector<int> getPrimes(int x) {
        vector<int> res;
        int d = 2;
        while (d * d <= x) {
            if (x % d == 0) {
                res.push_back(d);
                while (x % d == 0) {
                    x /= d;
                }
            }
            d += 1;
        }
        if (x > 1) {
            res.push_back(x);
        }
        return res;
    }
};

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int MOD = 1000000007;
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long gcd = nums[i];
            long long lcm = nums[i];

            for (int j = i; j < n; ++j) {
                prod = (prod * nums[j]) % MOD;
                gcd = std::gcd(gcd, nums[j]);
                lcm = lcm * nums[j] / std::gcd(lcm, nums[j]);

                if (prod == lcm * gcd) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};