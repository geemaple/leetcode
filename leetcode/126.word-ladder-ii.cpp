//  Tag: Hash Table, String, Backtracking, Breadth-First Search
//  Time: O((N*L)^C)
//  Space: O(N)
//  Ref: -
//  Note: -

//  A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
//  
//  Every adjacent pair of words differs by a single letter.
//  Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//  sk == endWord
//  
//  Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
//   
//  Example 1:
//  
//  Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
//  Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
//  Explanation: There are 2 shortest transformation sequences:
//  "hit" -> "hot" -> "dot" -> "dog" -> "cog"
//  "hit" -> "hot" -> "lot" -> "log" -> "cog"
//  
//  Example 2:
//  
//  Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
//  Output: []
//  Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
//  
//   
//  Constraints:
//  
//  1 <= beginWord.length <= 5
//  endWord.length == beginWord.length
//  1 <= wordList.length <= 500
//  wordList[i].length == beginWord.length
//  beginWord, endWord, and wordList[i] consist of lowercase English letters.
//  beginWord != endWord
//  All the words in wordList are unique.
//  The sum of all shortest transformation sequences does not exceed 105.
//  
//  

class Solution {
private:
    vector<string> getNext(string& word, unordered_map<string, int>& words_distance, unordered_set<string>& visited) {
        vector<string> res;
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        
        for (auto i = 0; i < word.size(); ++i) {
            for (auto l: alphabet) {
                if (word[i] == l) {
                    continue;
                }
                
                string candidate = word;
                candidate[i] = l;
                
                if (words_distance.count(candidate) == 0 || visited.count(candidate) > 0) {
                    continue;
                }
                
                res.push_back(candidate);
            }
        }
        
        return res;
    }
    
    void bfs(string& endWord, unordered_map<string, int>& words_distance) {
        
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(endWord);
        visited.insert(endWord);
        int distance = 0;
        
        while(!q.empty()) {
            int count = q.size();
            for (auto i = 0; i < count; ++i) {
                string word = q.front();
                q.pop();
                
                words_distance[word] = distance;
                for (auto neighbor: getNext(word, words_distance, visited)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
            
            distance++;
        }
    }
    
    void dfs(unordered_map<string, int>& words_distance, string &endWord, unordered_set<string>& visited, vector<string>& tmp, vector<vector<string>>& res) {
        string word = tmp.back();
        if (word == endWord) {
            res.push_back(tmp);
            return;
        }
        
        int distance = words_distance.count(word) > 0 ? words_distance[word] : INT_MAX;
        
        for (auto neighbor: getNext(word, words_distance, visited)) {
            if (words_distance[neighbor] >= distance) {
                continue;
            }
            visited.insert(neighbor);
            tmp.push_back(neighbor);
            
            dfs(words_distance, endWord, visited, tmp, res);
            
            tmp.pop_back();
            visited.erase(neighbor);
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> words_distance;
        
        for (auto word: wordList) {
            words_distance[word] = 0;
        }
        
        if (words_distance.count(endWord) == 0) {
            return vector<vector<string>>{};
        }
        
        bfs(endWord, words_distance);
        
        unordered_set<string> visited;
        vector<vector<string>> res;
        vector<string> tmp;
        
        tmp.push_back(beginWord);
        visited.insert(beginWord);
        
        dfs(words_distance, endWord, visited, tmp, res);
        
        return res;
    }
};