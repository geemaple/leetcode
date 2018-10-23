class Solution {
private:
    vector<string> getNeighbors(string& target, unordered_set<string>& words, unordered_set<string>& visited)
    {
        vector<string> res;
        string alphabet = "abcdefghijklmnopqrstuvwxyz";

        for (auto i = 0; i < target.size(); ++i)
        {
            for (auto j = 0; j < alphabet.size(); ++j)
            {
                string candidate = target;
                candidate[i] = alphabet[j];

                if (words.count(candidate) == 0)
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
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;

        for (auto i = 0; i < wordList.size(); ++i)
        {
            words.insert(wordList[i]);
        }

        if (words.size() == 0 || words.count(endWord) == 0)
        {
            return 0;
        }

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);
        int steps = 0;
        
        while(!q.empty())
        {
            steps++;
            int size = q.size();
            
            for (auto i = 0; i < size; ++i)
            {
                string tmp = q.front();
                q.pop();

                if (tmp == endWord)
                {
                    return steps;
                }

                for (auto neighbor: getNeighbors(tmp, words, visited))
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return 0;
    }
};
