class UnionFind
{
    vector<int> graph;
public:
    UnionFind(int n){
        graph.resize(n);

        for (int i = 0; i < n; i++)
        {
            graph[i] = i;
        }
    }
    
    int find(int node)
    {
        if (graph[node] == node)
        {
            return node;
        }
        
        graph[node] = find(graph[node]);
        return graph[node];
    }
    
    void connect(int a, int b)
    {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b)
        {
            graph[root_a] = root_b;
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // email: userId
        unordered_map<string, int> accoutMap; 

        // mapping and connect
        UnionFind uf(accounts.size());
        for (int i = 0; i < accounts.size(); ++i)
        {
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                string email = accounts[i][j];
                if (accoutMap.count(email) == 0)
                {
                    accoutMap[email] = i;
                }
                else
                {
                    int userId = accoutMap[email];
                    uf.connect(i, userId);
                }
            }
        }

        // merge
        unordered_map<int, set<string>> merged;
        for (int i = 0; i < accounts.size(); ++i)
        {
            int k = uf.find(i);
            merged[k].insert(accounts[i].begin(), accounts[i].end());
        }

        // answer
        vector<vector<string>> res;
        for (auto it: merged) //:Fixme
        {
            res.push_back(vector<string>(it.second.begin(), it.second.end()));
        }

        return res;
    }
};