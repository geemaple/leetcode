//  Tag: Array, Dynamic Programming
//  Time: O(N^2)
//  Space: O(N^2)
//  Ref: -
//  Note: -

//  A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
//  Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
//  If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.
//   
//  Example 1:
//  
//  Input: stones = [0,1,3,5,6,8,12,17]
//  Output: true
//  Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
//  
//  Example 2:
//  
//  Input: stones = [0,1,2,3,4,8,9,11]
//  Output: false
//  Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
//  
//   
//  Constraints:
//  
//  2 <= stones.length <= 2000
//  0 <= stones[i] <= 231 - 1
//  stones[0] == 0
//  stones is sorted in a strictly increasing order.
//  
//  

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> dp;
        for (int s: stones) {
            dp[s] = unordered_set<int>();
        }
        dp[0].insert(0);

        for (int s: stones) {
            for (int jump : dp[s]) {
                for (int next_jump : {jump - 1, jump, jump + 1}) {
                    if (next_jump > 0 && dp.count(s + next_jump)) {
                        dp[s + next_jump].insert(next_jump);
                    }
                }
            }
        }

        return dp[stones[n - 1]].size() > 0;
    }
};


class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                long k = stones[i] - stones[j];
                if (dp[j].count(k - 1) || dp[j].count(k) || dp[j].count(k + 1)) {
                    dp[i].insert(k);
                }
            }
        }

        return dp[n - 1].size() > 0;
    }
};