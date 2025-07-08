//  Tag: Array, Binary Search, Dynamic Programming, Sorting
//  Time: O(NlogN + NK)
//  Space: O(NK)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/FPO3W8l2Jjg

//  You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
//  You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
//  Return the maximum sum of values that you can receive by attending events.
//   
//  Example 1:
//  
//  
//  Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
//  Output: 7
//  Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
//  Example 2:
//  
//  
//  Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
//  Output: 10
//  Explanation: Choose event 2 for a total value of 10.
//  Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
//  Example 3:
//  
//  
//  Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
//  Output: 9
//  Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
//   
//  Constraints:
//  
//  1 <= k <= events.length
//  1 <= k * events.length <= 106
//  1 <= startDayi <= endDayi <= 109
//  1 <= valuei <= 106
//  
//  

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return dfs(events, 0, k, dp);
    }

    int dfs(vector<vector<int>>& events, int i, int k, vector<vector<int>> &dp) {
        if (k == 0 || i >= events.size()) {
            return 0;
        }

        if (dp[i][k] == -1) {
            int end = events[i][1];
            int value = events[i][2];
            int j = upper_bound(events.begin() + i, events.end(), end, [](int t, vector<int> &e) {
                return t < e[0];
            }) - events.begin();
    
            dp[i][k] = max(value + dfs(events, j, k - 1, dp), dfs(events, i + 1, k, dp));
        }
        return dp[i][k];
    }
};

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++) {
            int start = events[i - 1][0];
            int val = events[i - 1][2];
            int pre = upper_bound(events.begin(), events.end(), start - 1, [](int t, vector<int> e){
                return t < e[1];
            }) - events.begin();

            for (int j = 1; j <=k; j++) {
                dp[i][j] = max(dp[pre][j - 1] + val, dp[i - 1][j]);
            }
        }

        return dp[n][k];
    }

};

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> b) {
            return a[1] < b[1];
        });

        vector<pair<int, long long>> dp = {{0, 0}};
        for (int t = 0; t < k; t++) {
            vector<pair<int, long long>> tmp = {{0, 0}};
            for (auto& event : events) {
                int i = upper_bound(dp.begin(), dp.end(), make_pair(event[0], 0)) - dp.begin() - 1;
                if (dp[i].second + event[2] > tmp.back().second) {
                    tmp.emplace_back(event[1], dp[i].second + event[2]);
                }
            }
            dp = tmp;
        }

        return dp.back().second;
    }
};