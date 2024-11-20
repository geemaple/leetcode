//  Tag: Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
//  Return the minimum number of CPU intervals required to complete all tasks.
//   
//  Example 1:
//  
//  Input: tasks = ["A","A","A","B","B","B"], n = 2
//  Output: 8
//  Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
//  After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.
//  
//  Example 2:
//  
//  Input: tasks = ["A","C","A","B","D","B"], n = 1
//  Output: 6
//  Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
//  With a cooling interval of 1, you can repeat a task after just one other task.
//  
//  Example 3:
//  
//  Input: tasks = ["A","A","A", "B","B","B"], n = 3
//  Output: 10
//  Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
//  There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
//  
//   
//  Constraints:
//  
//  1 <= tasks.length <= 104
//  tasks[i] is an uppercase English letter.
//  0 <= n <= 100
//  
//  

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counter;
        int max_count = 0;
        for (auto t: tasks) {
            counter[t] += 1;
            max_count = max(max_count, counter[t]);
        }

        int ans = (max_count - 1) * (n + 1);
        for (auto &[task, count]: counter) {
            if (count == max_count) {
                ans += 1;
            }
        }

        return max((int)tasks.size(), ans);
    }
};


class Solution {
public:
        int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counter;
        for (char task : tasks) {
            counter[task]++;
        }

        priority_queue<pair<int, char>> heap;
        for (auto& [task, count] : counter) {
            heap.push({count, task});
        }

        int res = 0;
        while (!heap.empty()) {
            unordered_map<char, int> visited;
            for (int i = 0; i <= n; ++i) {
                if (heap.empty()) {
                    break;
                }

                auto top = heap.top();
                heap.pop();
                int count = top.first;
                char task = top.second;
                visited[task] = count;
            }

            for (auto& [task, count] : visited) {
                if (count > 1) {
                    heap.push({count - 1, task});
                }
            }

            res += heap.empty() ? visited.size() : n + 1;
        }

        return res;
    }
};