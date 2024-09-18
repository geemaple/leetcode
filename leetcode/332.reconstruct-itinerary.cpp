//  Tag: Depth-First Search, Graph, Eulerian Circuit
//  Time: O(ElogE)
//  Space: O(E+V)
//  Ref: -
//  Note: Containers

//  You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
//  All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
//  
//  For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
//  
//  You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
//   
//  Example 1:
//  
//  
//  Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
//  Output: ["JFK","MUC","LHR","SFO","SJC"]
//  
//  Example 2:
//  
//  
//  Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
//  Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
//  Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
//  
//   
//  Constraints:
//  
//  1 <= tickets.length <= 300
//  tickets[i].length == 2
//  fromi.length == 3
//  toi.length == 3
//  fromi and toi consist of uppercase English letters.
//  fromi != toi
//  
//  

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, queue<string>> graph;
        for (auto t: tickets) {
            graph[t[0]].push(t[1]);
        }

        vector<string> res;
        dfs(graph, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(unordered_map<string, queue<string>> &graph, string from, vector<string>& res) {
        queue<string>& q = graph[from];

        while (!q.empty()) {
            string to = q.front();
            q.pop();
            dfs(graph, to, res);
        }

        res.push_back(from);
    }
};

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

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, multiset<string>> graph;
        for (auto t: tickets) {
            graph[t[0]].insert(t[1]);
        }

        vector<string> res;
        dfs(graph, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(unordered_map<string, multiset<string>> &graph, string from, vector<string>& res) {
        multiset<string>& ms = graph[from];
        while (!ms.empty()) {
            string to = *(ms.begin());
            ms.erase(ms.begin());
            dfs(graph, to, res);
        }

        res.push_back(from);
    }
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, multiset<string>> graph;
        for (auto t: tickets) {
            graph[t[0]].insert(t[1]);
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
                multiset<string>& ms = graph[cur];
                string to = *(ms.begin());
                ms.erase(ms.begin());
                st.push(to);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};