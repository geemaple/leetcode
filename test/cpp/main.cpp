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

class ValidWordAbbr {
public:
    /*
    * @param dictionary: a list of words
    */
    unordered_map<string, unordered_set<string>> word_map;
    ValidWordAbbr(vector<string> dictionary) {
        // do intialization if necessary
        for (auto &x: dictionary) {
            word_map[abbreviate(x)].insert(x);
        }
    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    bool isUnique(string &word) {
        // write your code here
        string ab = abbreviate(word);
        return word_map[ab].size() == 0 || (word_map[ab].size() == 1 && word_map[ab].count(word) > 0);
    }

    string abbreviate(string &word) {
        if (word.size() <= 2) {
            return word;
        } else {
            return word[0] + to_string(word.size() - 2) + word.back();
        }
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

