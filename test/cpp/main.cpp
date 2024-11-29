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

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter;
        for (string w: words) {
            counter[w] += 1;
        }
        
        vector<pair<int, string>> word_list;
        for (auto &[word, count]: counter) {
            word_list.emplace_back(-count, word);
        }
            
        sort(word_list.begin(), word_list.end());
        vector<string> res;
 
        for (int i = 0; i < k; i++) {
            res.push_back(word_list[i].second);
        }
        
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0,1,1,0,0,0},
        {1,0,1,0,0,0},
        {0,1,1,1,0,1},
        {0,0,1,0,1,0}
    };
    
    
    
    vector<int> start = {1,2,3,3};
    vector<int> end = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    Solution s;
    int res = s.longestValidParentheses("())");
    cout << res << endl;
//    for (int word : res) {
//        cout << to_string(word) << ", ";
//    }
//    cout << endl;
    
    return 0;
}

