//  Tag: Array, Binary Search, Greedy, Queue, Sorting, Monotonic Queue
//  Time: O(NLogN)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/qvKodnc1_Dg

//  You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).
//  Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.
//  Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.
//   
//  Example 1:
//  
//  Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
//  Output: 3
//  Explanation:
//  We can assign the magical pill and tasks as follows:
//  - Give the magical pill to worker 0.
//  - Assign worker 0 to task 2 (0 + 1 >= 1)
//  - Assign worker 1 to task 1 (3 >= 2)
//  - Assign worker 2 to task 0 (3 >= 3)
//  
//  Example 2:
//  
//  Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
//  Output: 1
//  Explanation:
//  We can assign the magical pill and tasks as follows:
//  - Give the magical pill to worker 0.
//  - Assign worker 0 to task 0 (0 + 5 >= 5)
//  
//  Example 3:
//  
//  Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
//  Output: 2
//  Explanation:
//  We can assign the magical pills and tasks as follows:
//  - Give the magical pill to worker 0 and worker 1.
//  - Assign worker 0 to task 0 (0 + 10 >= 10)
//  - Assign worker 1 to task 1 (10 + 10 >= 15)
//  The last pill is not given because it will not make any worker strong enough for the last task.
//  
//   
//  Constraints:
//  
//  n == tasks.length
//  m == workers.length
//  1 <= n, m <= 5 * 104
//  0 <= pills <= m
//  0 <= tasks[i], workers[j], strength <= 109
//  
//  

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int l = 0;
        int r = min(tasks.size(), workers.size());
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (fit(tasks, workers, pills, strength, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    int fit(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        int n = tasks.size();
        int m = workers.size();
        deque<int> q;
        int i = 0;

        for (int j = m - k; j < m; j++) {
            while (i < n && workers[j] + strength >= tasks[i]) {
                q.push_back(tasks[i]);
                i += 1;
            }

            if (q.empty()) {
                return false;
            }

            if (workers[j] >= q.front()) {
                q.pop_front();
            } else if (pills > 0) {
                q.pop_back();
                pills -= 1;
            } else {
                return false;
            }

        }
        return true;
    }
};

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int l = 0;
        int r = min(tasks.size(), workers.size());
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (fit(tasks, workers, pills, strength, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    int fit(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        int n = tasks.size();
        multiset<int> ms(workers.end() - k, workers.end());
        for (int i = k - 1; i >= 0; i--) {
            auto it = prev(end(ms));
            if (*it < tasks[i]) {
                it = ms.lower_bound(tasks[i] - strength);
                if (it != end(ms) && pills > 0) {
                    pills -= 1;
                } else {
                    return false;
                }
            }
            ms.erase(it);
        }
        return true;
    }
};