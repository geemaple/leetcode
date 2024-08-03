#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto t: tickets) {
            graph[t[0]].push(t[1]);
        }

        vector<string> res;
        stack<string> st;
        st.push("JFK");
        
        while (!st.empty()) {
            string cur = st.top();
            if (graph[cur].empty()) {
                res.push_back(cur);
                st.pop();
            } else {
                auto& q = graph[cur];
                string to = q.top();
                q.pop();
                st.push(to);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<string>> grid = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}}; //{{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    
    vector<string> res = s.findItinerary(grid);
    for (auto x: res) {
        cout << "(" << x << ") ";
    }
    cout << endl;
}
