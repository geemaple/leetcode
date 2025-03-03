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
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> counter;
        for (char x: s) {
            counter[x - 'a'] += 1;
        }

        for (int i = 0; i < 3; i++) {
            if (counter[i] < k) {
                return -1;
            }
            counter[i] -= k;
        }
 
        int i = 0;
        int res = 0;
        vector<int> tmp;
        for(int j = 0; j < n; j++) {
            tmp[s[j] - 'a'] += 1;
            while (tmp[s[j] - 'a'] > counter[s[j] - 'a']) {
                tmp[s[i] - 'a'] -= 1;
                i += 1;
            }
            res = max(res, j - i + 1);
        }

        return n - res;
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
    int res = s.takeCharacters("aabaaaacaabc", 2);

    return 0;
}

