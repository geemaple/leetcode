//  Tag: Array, Binary Search, Greedy, Sliding Window, Sorting, Prefix Sum
//  Time: O(NlogN)
//  Space: O(1)
//  Ref: -
//  Note: -

//  There are an infinite amount of bags on a number line, one bag for each coordinate. Some of these bags contain coins.
//  You are given a 2D array coins, where coins[i] = [li, ri, ci] denotes that every bag from li to ri contains ci coins.
//  The segments that coins contain are non-overlapping.
//  You are also given an integer k.
//  Return the maximum amount of coins you can obtain by collecting k consecutive bags.
//   
//  Example 1:
//  
//  Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
//  Output: 10
//  Explanation:
//  Selecting bags at positions [3, 4, 5, 6] gives the maximum number of coins: 2 + 0 + 4 + 4 = 10.
//  
//  Example 2:
//  
//  Input: coins = [[1,10,3]], k = 2
//  Output: 6
//  Explanation:
//  Selecting bags at positions [1, 2] gives the maximum number of coins: 3 + 3 = 6.
//  
//   
//  Constraints:
//  
//  1 <= coins.length <= 105
//  1 <= k <= 109
//  coins[i] == [li, ri, ci]
//  1 <= li <= ri <= 109
//  1 <= ci <= 1000
//  The given segments are non-overlapping.
//  
//  

class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();
        sort(coins.begin(), coins.end());

        long long res = 0;
        long long count = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && coins[i][0] + k - 1 >= coins[j][1]) {
                count += (coins[j][1] - coins[j][0] + 1) * (long long)coins[j][2];
                j += 1;
            }

            if (j < n) {
                long long partial = max(0, coins[i][0] + k - coins[j][0]) * (long long)coins[j][2];
                res = max(res, count + partial);
            }
            count -= (coins[i][1] - coins[i][0] + 1) * (long long)coins[i][2];
        }

        count = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            count += (coins[j][1] - coins[j][0] + 1) * (long long)coins[j][2];
            while (coins[j][1] - k + 1 > coins[i][1]) {
                count -= (coins[i][1] - coins[i][0] + 1) * (long long)coins[i][2];
                i += 1;
            }

            long long partial = max(0, coins[j][1] - k - coins[i][0] + 1) * (long long)coins[i][2];
            res = max(res, count - partial);
        }

        return res;
    }
};