class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    bool isWord = false;
    vector<string> words;
    
    ~TrieNode(){
        for (auto it: children){
            delete it.second;
        }
    }
};

class Trie {
    TrieNode *root;
public:
    Trie()
    {
        this->root = new TrieNode();
    }
    
    void addWord(string &word)
    {
        TrieNode *cur = this->root;
        for(auto i = 0; i < word.size(); ++i)
        {
            cur->words.push_back(word);

            if (cur->children.count(word[i]) == 0)
            {
                cur->children[word[i]] = new TrieNode();
            }
            
            cur = cur->children[word[i]];
        }
        
        cur->isWord = true;
    }
    
    vector<string> prefixWords(string prefix)
    {
        TrieNode *cur = this->root;
        for (auto i = 0; i < prefix.size(); ++i) {
            if (cur->children.count(prefix[i]) == 0)
            {
                return vector<string>();
            }
            
            cur = cur->children[prefix[i]];
        }
        
        return cur->words;
    }
    
    ~Trie()
    {
        delete this->root;
    }
};

class Solution {
    
private:
    Trie trie;
    void dfs(vector<string>& words, vector<string>& ans, vector<vector<string>> &res)
    {
        if (ans.size() == words[0].size())
        {
            res.push_back(ans);
            return;
        }
        
        string prefix = "";
        int size = ans.size();
        for (auto i = 0; i < size; ++i)
        {
            prefix += ans[i][size];
        }

        vector<string> candidates = trie.prefixWords(prefix);

        for (auto i = 0; i < candidates.size(); ++i)
        {
            ans.push_back(candidates[i]);
            dfs(words, ans, res);
            ans.pop_back();
        }
    }
    
    void buildTrie(vector<string>& words){
        for (auto i = 0; i < words.size(); ++i)
        {
            trie.addWord(words[i]);
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        
        buildTrie(words);
        vector<vector<string>> res;
        vector<string> ans;
        
        dfs(words, ans, res);
        return res;
    }
};