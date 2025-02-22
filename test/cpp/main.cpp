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

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
                
        set<int> bloom;
        bloom.insert(flowers[0]);
        
        for (auto i = 1; i < flowers.size(); ++i) {
            auto lower = bloom.lower_bound(flowers[i]);
            if (lower != bloom.begin()) {
               lower--;
            }
    
            if (flowers[i] - *lower == k + 1) {
                return i + 1;
            }
            
            auto upper = bloom.upper_bound(flowers[i]);
            if (upper != bloom.end() && *upper - flowers[i] == k + 1) {
                return i + 1;
            }
            
            bloom.insert(flowers[i]);
        }
        
        return -1;
    }
};

int main() {
    std::string str = "Hello, World!";
    
//    vector<vector<int>> matrix = {
//        {0,1,1,0,0,0},
//        {1,0,1,0,0,0},
//        {0,1,1,1,0,1},
//        {0,0,1,0,1,0}
//    };
//    
//    
//    
//    vector<int> nums = {7,8,8,3,8,1,5,3,5,4};
//    vector<int> end = {3,4,5,6};
    vector<int> profit = {1, 3, 2};
    Solution s;
    int res = s.kEmptySlots(profit, 1);

    return 0;
}

