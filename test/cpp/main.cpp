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
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        // write your code here
        int i = 0;
        int j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (word[i] == abbr[j]) {
                i++;
                j++;
            } else if (isdigit(abbr[j]) && abbr[j] != '0') {
                int num = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    num = num * 10 + abbr[j] - '0';
                    j++;
                }
                i += num;
            } else {
                return false;
            }
        }
        
        return i == word.size() && j == abbr.size();
    }
};


int main() {
    vector<vector<int>> matrix = {
        {0,1,1,0,0,0},
        {1,0,1,0,0,0},
        {0,1,1,1,0,1},
        {0,0,1,0,1,0}
    };
    
    vector<int> nums1 = {-3,-1,2,4,5};
    vector<int> nums2 = {-3,-1,2,4,5};
    Solution s;
    bool res = s.validWordAbbreviation(-2, 3);
    cout << res << endl;
//    for (int word : res) {
//        cout << std::to_string(word) << ", ";
//    }
//    cout << endl;
    
    return 0;
}

