//  Tag: Array, Binary Search, Dynamic Programming, Sorting
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
//  You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
//  If you choose a job that ends at time X you will be able to start another job that starts at time X.
//   
//  Example 1:
//  
//  
//  Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
//  Output: 120
//  Explanation: The subset chosen is the first and fourth job. 
//  Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
//  
//  Example 2:
//   
//  
//  Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
//  Output: 150
//  Explanation: The subset chosen is the first, fourth and fifth job. 
//  Profit obtained 150 = 20 + 70 + 60.
//  
//  Example 3:
//  
//  
//  Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
//  Output: 6
//  
//   
//  Constraints:
//  
//  1 <= startTime.length == endTime.length == profit.length <= 5 * 104
//  1 <= startTime[i] < endTime[i] <= 109
//  1 <= profit[i] <= 104
//  
//  

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        vector<vector<int>> dp;
        dp.push_back({0, 0});
        for (auto &x : jobs) {
            auto p = upper_bound(dp.begin(), dp.end(), x[0], [](int target, vector<int> & a) {
                return target < a[0];
            });

            p = prev(p);
            if ((*p)[1] + x[2] > dp.back()[1]) {
                dp.push_back({x[1], (*p)[1] + x[2]});
            }
        }

        return dp.back()[1];
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        map<int, int> dp;
        dp[0] = 0;

        for (auto &x : jobs) {
            auto p = dp.upper_bound(x[0]);
            p = prev(p);

            if (p->second + x[2] > dp.rbegin()->second) {
                dp[x[1]] = p->second  + x[2];
            }
        }

        return dp.rbegin()->second;
    }
};