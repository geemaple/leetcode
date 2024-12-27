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

template <typename T>
void printHeap(priority_queue<T> heap) {
    cout << "Heap elements (max-heap order): ";
    while (!heap.empty()) {
        cout << heap.top().first << "," <<  heap.top().second << " ";
        heap.pop();  // Pop from the copied heap
    }
    cout << endl;
}

template <typename T, typename Comparator>
void printHeap(priority_queue<T, vector<T>, Comparator> heap) {
    cout << "Heap elements (custom order): ";
    while (!heap.empty()) {
        cout << heap.top().first << "," <<  heap.top().second << " ";
        heap.pop();  // Pop from the copied heap
    }
    cout << endl;
}

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> max_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        
        for (int i = 0; i < k; i++) {
            max_heap.emplace(nums[i], i);
        }

        for (int i = 0; i < k / 2; i++) {
            auto [number, index] = max_heap.top();
            max_heap.pop();
            min_heap.emplace(number, index);
        }
        vector<double> res;
        res.push_back(median(max_heap, min_heap, k));

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] <= max_heap.top().first) {
                max_heap.emplace(nums[i], i);
                if (nums[i - k] >= min_heap.top().first) {
                    auto [number, index] = max_heap.top();
                    max_heap.pop();
                    min_heap.emplace(number, index);
                }
            } else {
                min_heap.emplace(nums[i], i);
                if (nums[i - k] <= max_heap.top().first) {
                    auto [number, index] = min_heap.top();
                    min_heap.pop();
                    max_heap.emplace(number, index);
                }
            }

            while (!max_heap.empty() && max_heap.top().second <= i - k) {
                max_heap.pop();
            }

            while (!min_heap.empty() && min_heap.top().second <= i - k) {
                min_heap.pop();
            }

            res.push_back(median(max_heap, min_heap, k));
        }

        return res;
    }

    double median(priority_queue<pair<int, int>>& max_heap, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& min_heap, int k) {
        return (k % 2 == 1) ? (double)max_heap.top().first : ((double)max_heap.top().first + (double)min_heap.top().first) / 2.0;
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

