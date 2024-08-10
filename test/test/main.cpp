#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string t = buildString(s);
        int n = t.size();
        vector<int> p(n, 0);
        int center = 0;
        int right_x = 0;

        for (int i = 0; i < n; i++) {
            int mirror_j = 2 * center - i;
            if (i < right_x) {
                p[i] = min(right_x - i, p[mirror_j]);
            }

            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }

            if (right_x < i + p[i]) {
                center = i;
                right_x = i + p[i];
            }
        }


        int max_center = 0;
        int max_r = 0;
        for (int i = 0; i < n; i++) {
            if (max_r < p[i]) {
                max_r = p[i];
                max_center = i;
            }
        }

        int start = (max_center - max_r) / 2;
        return s.substr(start, max_r);

    }

    string buildString(string s) {
        string t = "#";
        for (auto x: s) {
            t += x + '';
            t += '#';
        }
        
        cout << t << endl;
        return t;
    }
};

int main() {
    Solution s;
    cout << "Longest Palindromic Substring: " << s.longestPalindrome("babad") << endl;
    return 0;
}
