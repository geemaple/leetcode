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

int read4(char* buf);

class Solution {
public:
    /**
     * @param buf: destination
     * @param n: the number of characters that need to be read
     * @return: the number of characters read
     */
    char tmp[4];
    int read(char* &buf, int n) {
        // write you code here
        int total = 0;
        
        while (total < n) {
            int count = read4(tmp);
            if (count == 0) {
                break;
            }
            int read = min(count, n - total);
            for (int i = 0; i < read; i++) {
                buf[total + i] = tmp[i];
            }
            total += read;
        }
        return total;
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

