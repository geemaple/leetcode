class Solution {
private:
    vector<string> getNeighbors(string& target, unordered_map<string, int>& words_distance, unordered_set<string>& visited)
    {
        vector<string> res;
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        
        for (auto i = 0; i < target.size(); ++i)
        {
            for (auto j = 0; j < alphabet.size(); ++j)
            {
                string candidate = target;
                candidate[i] = alphabet[j];
                
                if (words_distance.count(candidate) == 0)
                {
                    continue;
                }
                
                if (candidate == target)
                {
                    continue;
                }
                
                if (visited.count(candidate) > 0)
                {
                    continue;
                }
                
                res.push_back(candidate);
            }
        }
        
        return res;
    }
    
    // bfs
    void preBuildDistance(string& beginWord, string& endWord, unordered_map<string, int>& words_distance)
    {
        if (words_distance.size() == 0 || words_distance.count(endWord) == 0)
        {
            return;
        }
        
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(endWord);
        visited.insert(endWord);
        int steps = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for (auto i = 0; i < size; ++i)
            {
                string tmp = q.front();
                q.pop();
                
                words_distance[tmp] = steps;
                
                if (tmp == beginWord)
                {
                    return;
                }
                
                for (auto neighbor: getNeighbors(tmp, words_distance, visited))
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
            
            steps++;
        }
    }
    
    void helper(string& beginWord, string &endWord, unordered_map<string, int>& words_distance, unordered_set<string>& visited, vector<string>& ans, vector<vector<string>>& res)
    {
        if (beginWord == endWord)
        {
            res.push_back(ans);
            return;
        }
        
        int distance = words_distance.count(beginWord) == 0 ? INT_MAX : words_distance[beginWord];
        
        for (auto neighbor: getNeighbors(beginWord, words_distance, visited))
        {
            if (words_distance[neighbor] < distance) {
                visited.insert(neighbor);
                
                ans.push_back(neighbor);
                helper(neighbor, endWord, words_distance, visited, ans, res);
                ans.pop_back();
                
                visited.erase(neighbor);
            }
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> words_distance;
        
        for (auto i = 0; i < wordList.size(); ++i)
        {
            words_distance[wordList[i]] = INT_MAX;
        }
        
        preBuildDistance(beginWord, endWord, words_distance);
        
        // DFS
        unordered_set<string> visited;
        vector<vector<string>> res;
        vector<string> ans;
        
        ans.push_back(beginWord);
        visited.insert(beginWord);
        
        helper(beginWord, endWord, words_distance, visited, ans, res);
        
        return res;
    }
};