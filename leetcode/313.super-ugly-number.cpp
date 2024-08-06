//  Tag: Array, Math, Dynamic Programming
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  A super ugly number is a positive integer whose prime factors are in the array primes.
//  Given an integer n and an array of integers primes, return the nth super ugly number.
//  The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
//   
//  Example 1:
//  
//  Input: n = 12, primes = [2,7,13,19]
//  Output: 32
//  Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
//  
//  Example 2:
//  
//  Input: n = 1, primes = [2,3,5]
//  Output: 1
//  Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
//  
//   
//  Constraints:
//  
//  1 <= n <= 105
//  1 <= primes.length <= 100
//  2 <= primes[i] <= 1000
//  primes[i] is guaranteed to be a prime number.
//  All the values of primes are unique and sorted in ascending order.
//  
//

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> nth(k, 0);
        vector<long> candidates(primes.begin(), primes.end());
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            dp[i] = *min_element(candidates.begin(), candidates.end());
            for (int j = 0; j < k; j++) {
                if (dp[i] == candidates[j]) {
                    nth[j] ++;
                    candidates[j] = long(dp[nth[j]]) * primes[j];
                }
            }
        }

        return dp[n - 1];
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> nth(k, 0);
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> q;
        vector<int> dp(n, 1);

        for (int i = 0; i < k; i++) {
            q.push(make_pair(primes[i], i));
        }

        for (int i = 1; i < n; i++) {
            dp[i] = q.top().first;

            while (!q.empty() && q.top().first == dp[i]) {
                int j = q.top().second;
                q.pop();
                nth[j]++;
                long next_value = long(dp[nth[j]]) * primes[j];
                q.push(make_pair(next_value, j));
            }
        }

        return dp[n - 1];
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        long res = 1;
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> q;
        q.push(make_pair(1, 0));

        for (int i = 0; i < n; i++) {
            pair<int, int> p = q.top();
            res = p.first;
            q.pop();
            for (int j = p.second; j < k; j++) {
                q.push(make_pair(res * primes[j], j));
            }
        }

        return res;
    }
};