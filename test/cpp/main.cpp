#include <iostream>
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
    string decodeString(string s) {
        stack<char> st;

        for (auto x: s) {
            if (x == ']') {
                string seg = "";
                while (st.top() != '[') {
                    seg = st.top() + seg;
                    st.pop();
                }
                st.pop();
                int count = 0;
                int power = 1;
                while (!st.empty() && isdigit(st.top())) {
                    count = (st.top() - '0') * power + count;
                    power *= 10;
                    st.pop();
                }

                for (int i = 0; i < count; i++) {
                    for (int j = 0; j < seg.size(); j++) {
                        st.push(seg[j]);
                    }
                }
            } else {
                st.push(x);
            }
        }

        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};

int main() {
    vector<int> graph= {1,3,-1,-3,5,3,6,7};
    
    vector<int> nums1 = {-3,-1,2,4,5};
    vector<int> nums2 = {-3,-1,2,4,5};
    Solution s;
    string res = s.decodeString("3[a]2[bc]");
    cout << res << endl;
//    for (auto word : res) {
//        cout << word << ", ";
//    }
//    cout << endl;
    
    return 0;
}

