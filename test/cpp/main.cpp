#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <set>

using namespace std;

#include <vector>
#include <string>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        unordered_map<int, int> table;
        vector<double> res;
        
        for (int i = 0; i < k; i++) {
            min_heap.emplace(nums[i]);
        }

        for (int i = 0; i < k / 2; i++) {
            int num = min_heap.top();
            min_heap.pop();
            max_heap.emplace(num);
        }
        res.push_back(median(max_heap, min_heap, k));
        
        for (int i = k; i < nums.size(); i++) {
            int out_num = nums[i - k];
            int in_num = nums[i];

            int balance = out_num <= max_heap.top() ? -1 : 1;
            table[out_num] += 1;

            if (in_num <= max_heap.top()) {
                balance += 1;
                max_heap.push(in_num);
            } else {
                balance -= 1;
                min_heap.push(in_num);
            }

            if (balance < 0) {
                int num = min_heap.top();
                min_heap.pop();
                max_heap.push(num);
            }

            if (balance > 0) {
                int num = max_heap.top();
                max_heap.pop();
                min_heap.push(balance);
            }

            while (table[max_heap.top()] > 0) {
                table[max_heap.top()] -= 1;
                max_heap.pop();
            }

            while (!min_heap.empty() && table[min_heap.top()] > 0) {
                table[min_heap.top()] -= 1;
                min_heap.pop();
            }

            res.push_back(median(max_heap, min_heap, k));
        }

        return res;
    }

    double median(priority_queue<int>& max_heap, priority_queue<int, vector<int>, greater<int>>& min_heap, int k) {
        return (k % 2 == 1) ? (double)min_heap.top(): ((double)max_heap.top() + (double)min_heap.top()) / 2.0;
    }
};
/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */
/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */

int main() {
    vector<vector<int>> matrix = {
        {0,1,1,0,0,0},
        {1,0,1,0,0,0},
        {0,1,1,1,0,1},
        {0,0,1,0,1,0}
    };
    
    
    
    vector<int> nums = {7,8,8,3,8,1,5,3,5,4};
    vector<int> end = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    Solution s;
    vector<double> res = s.medianSlidingWindow(nums, 3);
    

    for (int word : res) {
        cout << to_string(word) << ", ";
    }
    cout << endl;
    
    return 0;
}

