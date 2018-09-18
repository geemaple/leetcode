class Solution {
private:
    char choices[4] = {'A', 'C', 'G', 'T'};
    vector<string> find_neighbors(string& gene, unordered_set<string>& bank)
    {
        vector<string> res;
        for (auto i = 0; i < gene.size(); ++i)
        {
            for(auto j = 0; j < 4; ++j)
            {
                if (gene[i] == choices[j])
                {
                    continue;
                }

                string mutate = gene.substr(0, i) + choices[j] + gene.substr(i + 1, gene.size() - i - 1);
                if (bank.count(mutate) == 0)
                {
                    continue;
                }
                
                res.push_back(mutate);
            }
        }

        return res;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        int level = 0;
        queue<string> q;
        unordered_set<string> visited;
        unordered_set<string> bank_set(bank.begin(), bank.end());

        q.push(start);
        visited.insert(start);

        while(q.size() > 0)
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                string top = q.front();
                q.pop();

                if (top == end)
                {
                    return level;
                }
                    
                for (auto neighbor: find_neighbors(top, bank_set))
                {
                    if (visited.count(neighbor) == 0)
                    {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            level ++;
        }

        return -1;
    }
};
