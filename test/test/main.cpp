#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        s += '+';
        int n = s.size();
        int left = 0;
        int right = 0;
        char op = '+';
        int num = 0;

        for (auto i = 0; i < n; i++) {
            if (s[i] == ' ') {
                continue;
            }
            
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else {
                switch (op) {
                    case '+': left = right; right = num; break;
                    case '-': left = right; right = -num; break;
                    case '*': right *= num; break;
                    case '/': right /= num; break;
                }
                num = 0;
                op = s[i];
            }
        }

        return left + right;
    }
};

int main(){
    Solution s;
    vector<vector<string>> grid = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}}; //{{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    
    int res = s.calculate("2147483647");
//    for (auto x: res) {
//        cout << "(" << x << ") ";
//    }
    cout << res <<  endl;
}
