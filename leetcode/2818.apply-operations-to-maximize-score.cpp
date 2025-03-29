//  Tag: Array, Math, Stack, Greedy, Sorting, Monotonic Stack, Number Theory
//  Time: O((N + K) * logN)
//  Space: O(Max)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/9orglCbAmwE

//  You are given an array nums of n positive integers and an integer k.
//  Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:
//  
//  Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
//  Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
//  Multiply your score by x.
//  
//  Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.
//  The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.
//  Return the maximum possible score after applying at most k operations.
//  Since the answer may be large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: nums = [8,3,9,3,8], k = 2
//  Output: 81
//  Explanation: To get a score of 81, we can apply the following operations:
//  - Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
//  - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
//  It can be proven that 81 is the highest score one can obtain.
//  Example 2:
//  
//  Input: nums = [19,12,14,6,10,18], k = 3
//  Output: 4788
//  Explanation: To get a score of 4788, we can apply the following operations: 
//  - Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
//  - Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
//  - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
//  It can be proven that 4788 is the highest score one can obtain.
//  
//   
//  Constraints:
//  
//  1 <= nums.length == n <= 105
//  1 <= nums[i] <= 105
//  1 <= k <= min(n * (n + 1) / 2, 109)
//  
//  

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int upper = *max_element(nums.begin(), nums.end()) + 1;
        vector<bool> primes(upper, true);
        vector<int> scores(upper, 0);
        for (int i = 2; i < upper; i++) {
            if (primes[i]) {
                for (int j = i; j < upper; j += i) {
                    primes[j] = false;
                    scores[j] += 1;
                }
            }
        }

        stack<int> st;
        vector<pair<int, int>> sub(n);
        for (int i = 0; i <= n; i++) {
            int cur = i == n ? INT_MAX: scores[nums[i]];
            while (!st.empty() && scores[nums[st.top()]] < cur) {
                int index = st.top();
                st.pop();
                int l = st.empty() ? 0 : st.top() + 1;
                int r = i - 1;
                sub[index] = make_pair(l, r);
            }
            st.push(i);
        }

        priority_queue<pair<int, long long>> q;
        for (int i = 0; i < n; i++) {
            long long count = (i - sub[i].first + 1LL) * (sub[i].second - i + 1LL);
            q.emplace(nums[i], count);
        }

        long long res = 1;
        int mod = 1e9 + 7;
        while (k > 0) {
            auto [val, count] = q.top();
            q.pop();
            res *= pow(val, min(k * 1LL, count), mod);
            res %= mod;
            k -= count;
        }

        return res;
    }

    int pow(int x, long long n, int mod) {
        long long res = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                res = (res * x) % mod;
            }
            x = 1LL * x * x % mod;
            n = n / 2;
        }
        return res;
    }
};