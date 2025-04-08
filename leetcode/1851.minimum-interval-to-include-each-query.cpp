//  Tag: Array, Binary Search, Line Sweep, Sorting, Heap (Priority Queue)
//  Time: O((N + M)logN + MlogM)
//  Space: O(N + M)
//  Ref: -
//  Note: -

//  You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.
//  You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
//  Return an array containing the answers to the queries.
//   
//  Example 1:
//  
//  Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
//  Output: [3,3,1,4]
//  Explanation: The queries are processed as follows:
//  - Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
//  - Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
//  - Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
//  - Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
//  
//  Example 2:
//  
//  Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
//  Output: [2,-1,4,6]
//  Explanation: The queries are processed as follows:
//  - Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
//  - Query = 19: None of the intervals contain 19. The answer is -1.
//  - Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
//  - Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.
//  
//   
//  Constraints:
//  
//  1 <= intervals.length <= 105
//  1 <= queries.length <= 105
//  intervals[i].length == 2
//  1 <= lefti <= righti <= 107
//  1 <= queries[j] <= 107
//  
//  

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
        
        vector<pair<int, int>> index_queries;
        for (int i = 0; i < queries.size(); i++) {
            index_queries.emplace_back(queries[i], i);
        }
        sort(index_queries.begin(), index_queries.end());
        
        vector<int> res(queries.size(), 0);
        int i = 0;
        for (auto &[q, idx]: index_queries) {
            while (i < n && intervals[i][0] <= q) {
                heap.emplace(intervals[i][1] - intervals[i][0] + 1, intervals[i][1]);
                i +=1;
            }

            while (!heap.empty() && heap.top().second < q) {
                heap.pop();
            }

            res[idx] = heap.empty() ? -1 : heap.top().first;
        }

        return res;
    }
};