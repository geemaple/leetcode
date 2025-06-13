//  Tag: Binary Search, Prefix Sum Array, Array
//  Time: O((N + M) * logM)
//  Space: O(M)
//  Ref: Leetcode-2838
//  Note: -

//  Given two arrays of positive integers `heroes` and `dungeons` with subscripts starting from **0** and lengths `n` and `m`, respectively, where `heroes[i]` denotes the ability value of the `i`th hero and `dungeons[j]` denotes the difficulty value of the `j`th dungeon.
//  
//  If `heroes[i] >= dungeons[j]`, it means that the `i`th hero can finish exploring the `j`th dungeon.
//  
//  Given a positive integer array `coins` of length `m`, `coins[j]` denotes the amount of gold that can be obtained after exploring the `j`th dungeon, and:
//  - the hero's ability value is not reduced after completing the exploration of the dungeon
//  - For each hero, the same dungeon can only be explored once
//  - Each dungeon can be explored once by a different hero
//  
//  Returns an array `res` of length `n`, where `res[i]` is the **maximum number of coins the `i`th hero can get.**
//  
//  Example 1:
//  
//  ```
//  Input:
//  heroes = [1, 5, 3]
//  dungeons = [1, 3, 7, 2, 1, 4]
//  coins = [2, 3, 4, 5, 6, 7]
//  Output:
//  [8, 23, 16]
//  Explanation:
//  heroes[0]:
//  heroes[0] = 1 >= dungeons[0], dungeons[4]
//  So will get 2 + 6 = 8 coins
//  heroes[1]
//  heroes[1] = 5 >= dungeons[0], dungeons[1], dungeons[3], dungeons[4], dungeons[5]
//  So will get 2 + 3 + 5 + 6 + 7 = 23 coins
//  heroes[2]
//  heroes[2] = 3 >= dungeons[0], dungeons[1], dungeons[3], dungeons[4]
//  So will get 2 + 3 + 5 + 6 = 16 coins
//  ```
//  
//  Example 2:
//  
//  ```
//  Input:
//  heroes = [1, 2]
//  dungeons = [3, 4]
//  coins = [5, 6]
//  Output:
//  [0, 0]
//  Explanation:
//  There are no dungeons can explore, so the maximum amount of gold gained is 0
//  ```
//  
//  - $ 1 \leq n == heroes.length \leq 10^5$
//  - $ 1 \leq m == dungeons.length \leq 10^5$
//  - $ coins.length == dungeons.length == m$
//  - $ 1 \leq heroes[i], dungeons[j], coins[j] \leq 10^9$

class Solution {
public:
    /**
     * @param heroes: An integer array
     * @param dungeons: An integer array
     * @param coins: An integer array
     * @return: Maximum number of coins that can be collect
     */
    vector<long long> maximumCoins(vector<int> &heroes, vector<int> &dungeons, vector<int> &coins) {
        // write your code here
        int n = heroes.size();
        int m = dungeons.size();

        vector<pair<int, int>> rewards;
        for (int i = 0; i < m; i++) {
            rewards.emplace_back(dungeons[i], coins[i]);
        }

        sort(rewards.begin(), rewards.end());
        vector<long long> prefix(m + 1, 0);
        vector<int> power(m, 0);
        for (int i = 0; i < m; i++) {
            power[i] = rewards[i].first;
            prefix[i + 1] = prefix[i] + rewards[i].second;
        }

        vector<long long> res(n, 0);
        for (int i = 0; i < n; i++) {
            int idx = upper_bound(power.begin(), power.end(), heroes[i]) - power.begin();
            res[i] = prefix[idx];
        }

        return res;
    }
};